#pragma once
#include "NativeContext3.h"
#include <string>
#include "global.h"

namespace NativeCall
{
	

	NativeContext3::NativeContext3()
	{
		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack; //&m_TempStackReturn;		// It's okay to point both args and return at 
		// the same pointer. The game should handle this.
		m_nArgCount = 0;
		m_nDataCount = 0;
	}
	void NativeContext3::Invoke(const char* name, NativeContext3* cxt)
	{
		ptr fn = pGetNativeAddress(name);
		if (fn != 0)
		{
			try
			{
				NativeCall call = (NativeCall)fn;
				call(cxt);
			}
			catch (std::exception e) {

			}
		}
	}
	void NativeContext3::Push(u8* value, u32 len) {
		SetArgument(m_nArgCount, value, len);
		m_nArgCount++;
	}
	void NativeContext3::SetArgument(int index, u8* value, u32 len) {
		if (len > ArgSize) {	// We only accept sized 4 or less arguments... that means no double/f64 or large structs are allowed.
			throw std::exception("Argument has an invalid size");
		}
		else if (len < ArgSize) {	// Ensure we don't have any stray data
			*ptr_cast<u32>(m_TempStack + ArgSize * index) = 0;
		}
		memcpy(m_TempStack + ArgSize * index, value, len);
	}
}

