#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#define NULL     ((void*)0)

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned  long int u32;
typedef unsigned  long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed  long long int s64;

typedef unsigned int * pu32;
typedef unsigned short int * pu16;
typedef unsigned char*  pu8;
typedef signed char* ps8;
typedef unsigned  long long int* pu64;


typedef float  f32;
typedef double f64;
typedef long double f128;

typedef struct{
	u8 *data;
	u32 size;
	u32 used;
}Buffer_t;



#endif
