#pragma once

#ifdef GENGINE_PLATFORM_WINDOWS

	#ifdef GENGINE_BUILD_DLL
		#define GENGINE_API __declspec(dllexport)
	#else
		#define GENGINE_API __declspec(dllimport)
	#endif

#else

#error Engine Only Supports Windows!

#endif


#define BIT(x)(1<<x)