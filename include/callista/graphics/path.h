#pragma once
#include <callista/types.h>

#if CS_INTERNAL
	struct Path_Internal {
		Dynarr<
	}
#else
	struct Path_Internal;
#endif

struct Path {
	Path_Internal *internal;
	
};

CS_LIB_PROC_C 