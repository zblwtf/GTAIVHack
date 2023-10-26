#pragma once
#include "ScriptHook/Types.h"
#include "ScriptHook/Game.h"

namespace NativeCall
{
	
	class NativeContext3 : public GameTypes::scrNativeCallContext {

	private:

		// Configuration
		enum {
			MaxNativeParams = 16,
			MaxReturnParams = 16,
			ArgSize = sizeof(u32),
		};

		// Anything temporary that we need
		u8 m_TempStack[MaxNativeParams * ArgSize];
		//u8 m_TempStackReturn[MaxReturnParams * ArgSize];

		typedef void(_cdecl* NativeCall)(GameTypes::scrNativeCallContext* cxt);

		inline void ReadVectorDataBack() {
			// Copy back any vector results
			while (m_nDataCount > 0) {
				m_nDataCount--;
				Vector3* pVec3 = m_pOriginalData[m_nDataCount];
				Vector4* pVec4 = &m_TemporaryData[m_nDataCount];
				pVec3->X = pVec4->X;
				pVec3->Y = pVec4->Y;
				pVec3->Z = pVec4->Z;
			}
		}

	public:

		NativeContext3();

		inline void Reset() {
			m_nArgCount = 0;
			m_nDataCount = 0;
		}

		inline int ArgCount() {
			return m_nArgCount;
		}

		void SetArgument(int index, u8* value, u32 len);

		template <typename T>
		inline void SetArgument(int index, T value) {
			SetArgument(index, (u8*)&value, sizeof(T));
		}

		void Push(u8* value, u32 len);

		template <typename T>
		inline void Push(T value) {
			Push((u8*)&value, sizeof(T));
		}

		static void Invoke(const char* name, NativeContext3* cxt);



		u8* GetResult();

		template <typename T>
		inline T GetResult() {
			ReadVectorDataBack();
			return *ptr_cast<T>(m_TempStack); //*ptr_cast<T>(m_TempStackReturn);
		}

	};
}