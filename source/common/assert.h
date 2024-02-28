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

#include "macros/attr.h"

/// Asserts a given condition in debug builds and aborts execution
/// when not met.
///
/// In release builds, the asserted condition may be turned into a
/// \ref ASSUME hint for the compiler to optimize around.
#if defined(BLUBBER_ENABLE_DEBUG_ASSERTIONS)
    #define B_ASSERT(expr) B_ASSERT_IMPL(expr)
#else
    #define B_ASSERT(expr) ASSUME(expr)
#endif

#define B_ASSERT_IMPL(expr) do { if (UNLIKELY(!(expr))) { assert_fail_impl(#expr, __FILE__, __LINE__); } } while (0)

COLD NORETURN NOINLINE void assert_fail_impl(const char *expr, const char *file, unsigned line);
