GTAIVHack

项目介绍
GTAIVHack是一个使用代理DLL与ScriptHook进行交互的项目。由于没有ScriptHook的lib文件，无法直接使用ScriptHook，因此通过生成一个ScriptHook的代理DLL来实现调用ScriptHook的功能。因此，该项目依赖一个代理DLL和ScriptHook，因此需要使用Loader DLL来先加载代理DLL，再加载项目的DLL。

项目结构
GTAIVHack.dll：项目的核心DLL文件，通过Loader DLL加载。
Loader.dll：用于先加载代理DLL，然后再加载项目的DLL。
ScriptHook.dll：ScriptHook的代理DLL，用于与ScriptHook进行交互。
依赖
ScriptHook.dll：通过Loader DLL加载ScriptHook的代理DLL。
使用方法
使用Loader项目编译得到Loader.dll。
将ScriptHook.dll和Loader.dll放置在与GTAIVHack.dll同一目录下。
使用Loader.dll加载GTAIVHack.dll，确保ScriptHook.dll被正确加载。
项目的DLL文件GTAIVHack.dll现在可以正常运行。
注意：由于代理DLL与普通的PE文件不同，无法使用PE加载技术。因此，需要通过调用Kernel32.dll的LoadLibrary函数来手动加载ScriptHook.dll的代理DLL。为了保证代码的正常工作，建议使用Loader.dll来先加载代理DLL，然后再加载项目的DLL。

许可证
该项目基于 MIT 许可证。详情请参阅 LICENSE 文件。

以上是一个简单的readme示例，说明了项目的背景、结构、依赖和使用方法。您可以根据您的实际项目情况进行适当修改和补充。
