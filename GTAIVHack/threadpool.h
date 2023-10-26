#pragma once
#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>


class ThreadPool
{
public:
    //���캯��ֻ��������һЩworker
    ThreadPool(size_t);
    //��������join�����߳�
    ~ThreadPool();
    //���������µ�worker
    template<typename F, class... Args>
    auto enqueue(F&& f, Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>;
private:
    //��Ҫ�����̣߳��Ա����ǿ������ɾ������
    std::vector<std::thread> workers;
    //�������
    std::queue<std::function<void()>> tasks;
    //������л�����
    std::mutex tasks_mutex;
    //ͬ���ź�
    std::condition_variable condition;
    bool stop;
};

inline ThreadPool::ThreadPool(size_t threads) :
    stop(false)
{
    for (size_t i = 0; i < threads; i++)
    {
        workers.emplace_back(
            [this]
            {
                for (;;)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->tasks_mutex);
                        this->condition.wait(lock,
                            [this] { return this->stop || !this->tasks.empty(); });
                        if (this->stop && this->tasks.empty())
                        {
                            return;
                        }
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            }
            );
    }
}

inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(tasks_mutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread& worker : workers)
    {
        worker.join();
    }
}

template <typename F, typename... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    //std::forward��������ת��: https://zhuanlan.zhihu.com/p/92486757
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(tasks_mutex);
        //ֹͣ�غ������Ŷ�
        if (stop)
        {
            throw std::runtime_error("enqueue on stopped ThreadPool!");
        }
        tasks.emplace([task]() { (*task)(); });
    }
    condition.notify_one();
    return res;
}

#endif // THREADPOOL_H