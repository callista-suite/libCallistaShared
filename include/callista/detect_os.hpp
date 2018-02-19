#pragma once

// Just include build_info.hpp.

// Massive mess of platform-detection macros.
//
//             Windows: CS_OS_WIN32
//               Apple: CS_OS_APPLE    CS_OS_NIX  (CS_OS_IOS | CS_OS_MACOS)  CS_OS_DARWIN
//             Android: CS_OS_ANDROID  CS_OS_NIX
//               Linux: CS_OS_LINUX    CS_OS_NIX  CS_OS_GTK
//                 BSD: CS_OS_BSD      CS_OS_NIX  CS_OS_GTK
//  Generic POSIX/Unix: CS_OS_NIX                 CS_OS_GTK
//
//                 GCC: CS_COMPILER_GCC
//               Clang: CS_COMPILER_CLANG
//                MSVC: CS_COMPILER_MSVC
//             Unknown: CS_COMPILER_UNKNOWN
//
#ifdef _WIN32
	#define CS_OS_WIN32 1
#elif __APPLE__
	#define CS_OS_DARWIN 1
	#define CS_OS_APPLE 1
	#define CS_OS_NIX 1
	#include "TargetConditionals.h"
	#if TARGET_IPHONE_SIMULATOR
		#define CS_OS_IOS 1
	#elif TARGET_OS_IPHONE
		#define CS_OS_IOS 1
	#elif TARGET_OS_MAC
		#define CS_OS_MACOS 1
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	#define CS_OS_ANDROID 1
	#define CS_OS_NIX 1
#elif __linux__
	#define CS_OS_NIX 1
	#define CS_OS_LINUX 1
	#define CS_OS_GTK 1
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
	#define CS_OS_NIX 1
	#define CS_OS_BSD 1
	#define CS_OS_GTK 1
#elif __unix__
	#define CS_OS_NIX 1
	#define CS_OS_GTK 1
#elif defined(_POSIX_VERSION)
	#define CS_OS_NIX 1
	#define CS_OS_GTK 1
#else
	#error "Unknown platform."
#endif

#ifdef __clang__
	#define CS_COMPILER_CLANG 1
#elif defined(__GNUC__) || defined(__GNUG__)
	#define CS_COMPILER_GCC 1
#elif defined(_MSC_VER)
	#defined CS_COMPILER_MSVC 1
#else
	// TODO(zachary): Should I allow building on alternative toolchains?
	//                It shouldn't be a problem... I guess.
	#warning "Building with unknown compiler."
	#define CS_COMPILER_UNKNOWN 1
#endif

// Clearing out unused defines.

#ifndef CS_OS_WIN32
#define CS_OS_WIN32 0
#endif

#ifndef CS_OS_APPLE
#define CS_OS_APPLE 0
#endif

#ifndef CS_OS_IOS
#define CS_OS_IOS 0
#endif

#ifndef CS_OS_MACOS
#define CS_OS_MACOS 0
#endif

#ifndef CS_OS_DARWIN
#define CS_OS_DARWIN 0
#endif

#ifndef CS_OS_ANDROID
#define CS_OS_ANDROID 0
#endif

#ifndef CS_OS_LINUX
#define CS_OS_LINUX 0
#endif

#ifndef CS_OS_BSD
#define CS_OS_BSD 0
#endif

#ifndef CS_OS_NIX
#define CS_OS_NIX 0
#endif

#ifndef CS_OS_GTK
#define CS_OS_GTK 0
#endif

#ifndef CS_COMPILER_CLANG
#define CS_COMPILER_CLANG 0
#endif

#ifndef CS_COMPILER_GCC
#define CS_COMPILER_GCC 0
#endif

#ifndef CS_COMPILER_MSVC
#define CS_COMPILER_MSVC 0
#endif

#ifndef CS_COMPILER_UNKNOWN
#define CS_COMPILER_UNKNOWN 0
#endif
