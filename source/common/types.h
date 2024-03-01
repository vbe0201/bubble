/*
 * Copyright (c) 2024 Valentin B.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "macros/arch.h"

#if defined(BUBBLE_ARCH_AMD64)
    /* Unsigned integer types. */
    typedef unsigned char u8;
    typedef unsigned short u16;
    typedef unsigned int u32;
    #ifdef __APPLE__
        typedef unsigned long long u64;
    #else
        typedef unsigned long u64;
    #endif
    typedef unsigned long uptr;
    typedef unsigned long usize;

    /* Signed integer types. */
    typedef signed char i8;
    typedef signed short i16;
    typedef signed int i32;
    #ifdef __APPLE__
        typedef signed long long i64;
    #else
        typedef signed long i64;
    #endif
    typedef long iptr;
    typedef long isize;

    /* Floating-point types. */
    typedef float f32;
    typedef double f64;

#else
    #error "Missing types for target architecture!"
#endif

static_assert(sizeof(u8) == sizeof(i8));
static_assert(sizeof(u16) == sizeof(i16));
static_assert(sizeof(u32) == sizeof(i32));
static_assert(sizeof(u64) == sizeof(i64));
static_assert(sizeof(uptr) == sizeof(iptr));
static_assert(sizeof(usize) == sizeof(isize));

static_assert(sizeof(u32) == sizeof(f32));
static_assert(sizeof(u64) == sizeof(f64));
