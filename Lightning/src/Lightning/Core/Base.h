#pragma once

#ifdef LN_PLATFORM_WINDOWS
	#ifdef LN_BUILD_DLL
		#define LN_API __declspec(dllexport)
	#else
		#define LN_API __declspec(dllimport)
	#endif
#endif