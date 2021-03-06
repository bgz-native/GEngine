#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <functional>
#include <vector>

//TODO investigate, only needed by uint32_t
#include <stdint.h>

#ifdef GENGINE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#ifdef GENGINE_PLATFORM_WINDOWS

	#ifdef GENGINE_BUILD_DLL
		#define GENGINE_API __declspec(dllexport)
	#else
		#define GENGINE_API __declspec(dllimport)
	#endif

	#ifdef _DEBUG
	#		define LOGD(...) fprintf(stdout, __VA_ARGS__)
	#		define LOGV(...) fprintf(stdout, __VA_ARGS__) 
	#		define LOGE(...) fprintf(stdout, __VA_ARGS__)
	#else
	#		define LOGD(__FILE__, ...) 
	#		define LOGV(__FILE__, ...) 
	#		define LOGE(__FILE__, ...) 
	#endif

#else

#error Engine Only Supports Windows!

#endif

#define BIT(x)(1<<x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

//TODO ASSERT

//TODO check all pointers, make const if neccesary

