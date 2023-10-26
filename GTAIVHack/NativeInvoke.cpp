#include "NativeInvoke.h"
namespace NativeCall
{
	void NativeInvoke::Invoke(const char* name, NativeContext* cxt)
	{
		ptr fn = pGetNativeAddress(name);

		// Commented out to reduce debug spam.
		//LogDebug("Invoking native: %s", name);

		if (fn != 0)
		{
			NativeCall call = (NativeCall)fn;
			call(cxt);
		}
	}
}