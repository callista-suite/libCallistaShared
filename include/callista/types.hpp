#pragma once


#include <deque>
template<typename T> using Dynarr = std::deque<T>;

#include <string>
using String = std::string;

#include <stdint.h>

// A whole buncha int types
typedef intmax_t  imax;
typedef uintmax_t umax;
typedef int8_t    i8;
typedef uint8_t   u8;
typedef int16_t   i16;
typedef uint16_t  u16;
typedef int32_t   i32;
typedef uint32_t  u32;
typedef int64_t   i64;
typedef uint64_t  u64;

typedef int_least8_t    least_i8;
typedef uint_least8_t   least_u8;
typedef int_least16_t   least_i16;
typedef uint_least16_t  least_u16;
typedef int_least32_t   least_i32;
typedef uint_least32_t  least_u32;
typedef int_least64_t   least_i64;
typedef uint_least64_t  least_u64;

typedef int_fast8_t    fast_i8;
typedef uint_fast8_t   fast_u8;
typedef int_fast16_t   fast_i16;
typedef uint_fast16_t  fast_u16;
typedef int_fast32_t   fast_i32;
typedef uint_fast32_t  fast_u32;
typedef int_fast64_t   fast_i64;
typedef uint_fast64_t  fast_u64;

typedef intptr_t  intptr;
typedef uintptr_t uintptr;