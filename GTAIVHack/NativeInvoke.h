#pragma once
#include "ScriptHook/Types.h"
#include "ScriptHook/Game.h"
#include "NativeContext.h"
#include "global.h"

namespace NativeCall
{
	class NativeInvoke
	{
	private:
		typedef void(_cdecl* NativeCall)(GameTypes::scrNativeCallContext* cxt);

		static  void Invoke(const char* name, NativeContext* cxt);


	public:

		// Here be repetitive ugly code... x16 (thanks copy and paste)
		// Only because I didn't want to use variadic functions

		template <typename R>
		static inline R Invoke(const char* name)
		{
			NativeContext cxt;

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1>
		static inline R Invoke(const char* name, T1 p1)
		{
			NativeContext cxt;

			cxt.Push(p1);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2>
		static inline R Invoke(const char* name, T1 p1, T2 p2)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11, typename T12>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);
			cxt.Push(p12);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11, typename T12, typename T13>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);
			cxt.Push(p12);
			cxt.Push(p13);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11, typename T12, typename T13, typename T14>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);
			cxt.Push(p12);
			cxt.Push(p13);
			cxt.Push(p14);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}

		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11, typename T12, typename T13, typename T14,
			typename T15>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);
			cxt.Push(p12);
			cxt.Push(p13);
			cxt.Push(p14);
			cxt.Push(p15);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}


		template <typename R, typename T1, typename T2, typename T3, typename T4,
			typename T5, typename T6, typename T7, typename T8, typename T9,
			typename T10, typename T11, typename T12, typename T13, typename T14,
			typename T15, typename T16>
		static inline R Invoke(const char* name, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8,
			T9 p9, T10 p10, T11 p11, T12 p12, T13 p13, T14 p14, T15 p15, T16 p16)
		{
			NativeContext cxt;

			cxt.Push(p1);
			cxt.Push(p2);
			cxt.Push(p3);
			cxt.Push(p4);
			cxt.Push(p5);
			cxt.Push(p6);
			cxt.Push(p7);
			cxt.Push(p8);
			cxt.Push(p9);
			cxt.Push(p10);
			cxt.Push(p11);
			cxt.Push(p12);
			cxt.Push(p13);
			cxt.Push(p14);
			cxt.Push(p15);
			cxt.Push(p16);

			Invoke(name, &cxt);
			return cxt.GetResult<R>();
		}
	};
}