#pragma once

#ifdef __clang__
#include <stdint.h>
#else
#include <cstdint>
#endif

#include <float.h>

#define i8  int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double

#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920

#define MAX(X,Y) ((X>=Y) ? X : Y)
#define MIN(X,Y) ((X<=Y) ? X : Y)

#define ABS(X) ((X < 0) ? X : -X)
#define SIGN(X) ((X < 0) ? -1 : 1)

#define SQ(X) ((X) * (X))

#define FPS 60
#define CURR_FPS 60

#define FAST_INV_SQRT(x, y) \
{\
	if (x <= 0.0000001f)                          \
	{                                              \
		y = FLT_MAX;                    \
	}                                              \
	else                                           \
	{                                              \
		float _x = x * 0.5f;                      \
		y = x;								\
		long _y = *(long *) &y; \
		_y = 0x5f3759df - (_y >> 1); \
		y = *(float*)&_y;                         \
		y = y * (1.5f - (_x * y * y)); \
	}                                              \
}
