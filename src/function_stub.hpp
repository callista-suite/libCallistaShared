#pragma once

// The templating here is just so that the assert is only called
// if the function is used. If there's no callers, templates don't get generated,
// and you don't get an assert!
#include <type_traits>

#include <callista/build_info.hpp>

// Because the funciton signature may dictate any return type, we have to prevent errors or warnings
// due to no return value at the end of the function. There's no standards-compliant way to do that,
// so I just have to get into brute-forced macro hell.

#pragma GCC diagnostic ignored "-Wreturn-type"

#if CS_COMPILER_GCC
	#define CS__FSTUB_CLEARWARN   _Pragma("GCC diagnostic push"); _Pragma("GCC diagnostic ignored \"-Wreturn-type\"");
	#define CS__FSTUB_RESTOREWARN _Pragma("GCC diagnostic pop");
#elif CS_COMPILER_CLANG
	#define CS__FSTUB_CLEARWARN   _Pragma("clang diagnostic push"); _Pragma("clang diagnostic ignored \"-Wreturn-type\"");
	#define CS__FSTUB_RESTOREWARN _Pragma("clang diagnostic pop");
#elif CS_COMPILER_MSVC
	// TODO(zachary): Is this the correct warning code for msvc?
	#define CS__FSTUB_CLEARWARN   __pragma(warning(push)); __pragma(warning(disable:4715))
	#define CS__FSTUB_RESTOREWARN __pragma(warning(pop));
#else
	#define CS__FSTUB_CLEARWARN
	#define CS__FSTUB_RESTOREWARN
#endif


#define function_stub(error, ...) \
	CS__FSTUB_CLEARWARN; \
	template <typename T = float> \
	__VA_ARGS__ { \
		static_assert(std::is_integral<T>::value, error); \
	}; \
	CS__FSTUB_RESTOREWARN;
