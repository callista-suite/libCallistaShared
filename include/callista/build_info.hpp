#pragma once

#include "detect_os.hpp"

#define CS_VERSION   "0.0.1"
#define CS_DEV_BUILD true


// CS_LIB_PROC_C,
// CS_LIB_PROC_CPP - Use this before defining procedures that should be exported from libcallistashared.
//                   CS_LIB_PROC_C is preferred because its procedures are language-agnostic,
//                   while CS_LIB_PROC_CPP are c++ exclusive.
//
//                   Usage: `CS_LIB_PROC_C   void test_proc(char  *string);`
//                          `CS_LIB_PROC_CPP void test_proc(String string);`
//
//
// CS_LIB_HIDE     - Use this before defining procedures that should *not* be exported from the library.
//                   For example, procedures local to a single .cpp file and not useful from the host application.
//
//                   Usage: `CS_LIB_HIDE void local_thing(bool lalala) {...}`
//

#if CS_OS_WIN32
	#define CS_LIB_HIDE 
#else
	#define CS_LIB_HIDE __attribute__((visibility("hidden")))
#endif


// This block defines a bunch of internal macros that unfortunately must be made public in
// order for the only important one (CS_LIB_PROC) to work. Because of this, everything else
// has an annoying namespaced name beginning with CS__BUILD_INFO__ rather than the standard CS_
//
// {

	#if CS_OS_WIN32
		#define CS__BUILD_INFO__LIB_EXPORT __declspec(dllexport)
		#define CS__BUILD_INFO__LIB_IMPORT __declspec(dllimport)
	#else
		// TODO(zachary): Does clang support this?
		#define CS__BUILD_INFO__LIB_EXPORT __attribute__((visibility("default")))
		#define CS__BUILD_INFO__LIB_IMPORT /* not needed */
	#endif

	#ifdef CS_SHARED
		#define CS__BUILD_INFO__LIB_VISIBILITY_PREFIX CS__BUILD_INFO__LIB_EXPORT
	#else
		#define CS__BUILD_INFO__LIB_VISIBILITY_PREFIX CS__BUILD_INFO__LIB_IMPORT
	#endif

	#ifdef __cplusplus
		#define CS_LIB_PROC_C extern "C" CS__BUILD_INFO__LIB_VISIBILITY_PREFIX
	#else
		#define CS_LIB_PROC_C CS__BUILD_INFO__LIB_VISIBILITY_PREFIX
	#endif
	#define CS_LIB_PROC_CPP CS__BUILD_INFO__LIB_VISIBILITY_PREFIX

// }