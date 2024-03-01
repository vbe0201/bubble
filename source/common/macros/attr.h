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

/** Strong hint to the compiler to always inline a function. */
#define ALWAYS_INLINE __attribute__((always_inline))

/** Strong hint to the compiler that a function should never be inlined. */
#define NOINLINE __attribute__((noinline))

/** Hint to the compiler that a function is unlikely to be executed. */
#define COLD __attribute__((cold))

/** Hint to the compiler that a function never returns. */
#define NORETURN __attribute__((noreturn))

/** Hint to branch prediction that a path is likely to be taken. */
#define LIKELY(expr) __builtin_expect(!!(expr), 1)

/** Hint to branch prediction that a path is likely to not be taken. */
#define UNLIKELY(expr) __builtin_expect(!!(expr), 0)

/**
 * @brief Hint to the compiler that a certain invariant is always met.
 *
 * The expression is never evaluated, but it must always hold true
 * at the point where it occurs.
 */
#define ASSUME(expr) __builtin_assume(expr)
