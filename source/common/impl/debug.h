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
#include "macros/attr.h"

#if defined(BUBBLE_ARCH_AMD64) || defined(BUBBLE_ARCH_X86)
    /* It is actually important to use int3 instead of int $3 here. */
    /* While GAS optimizes both to desired CC, NASM produces CD 03. */
    #define B_DEBUG_BREAK_IMPL() __asm__ __volatile__("int3")
#elif defined(__thumb__)
    /* See arm-linux-tdep.c in GDB source, eabi_linux_thumb_le_breakpoint. */
    #define B_DEBUG_BREAK_IMPL() __asm__ __volatile__(".inst 0xd4200000")
#elif defined(BUBBLE_ARCH_AARCH64)
    /* See aarch64-tdep.c in GDB source, aarch64_default_breakpoint. */
    #define B_DEBUG_BREAK_IMPL() __asm__ __volatile__(".inst 0xd4200000")
#elif defined(BUBBLE_ARCH_ARM)
    /* See arm-linux-tdep.c in GDB source, eabi_linux_arm_le_breakpoint. */
    #define B_DEBUG_BREAK_IMPL() __asm__ __volatile__(".inst 0xe7f001f0")
#endif

/** Triggers a breakpoint for debugging. */
ALWAYS_INLINE static void debug_break() {
    B_DEBUG_BREAK_IMPL();
}

#undef B_DEBUG_BREAK_IMPL
