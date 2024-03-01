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

#include "types.h"
#include "macros/arch.h"
#include "macros/misc.h"

#if defined(BUBBLE_ARCH_AMD64)
    #include "syscall/syscall.amd64.h"
#else
    #error "Missing syscall implementation for target architecture!"
#endif

/**
 * @brief Invokes a system call with a variable number of arguments.
 */
#define syscall(num, ...) B_VMACRO(syscall, ##__VA_ARGS__)(num, ##__VA_ARGS__)
