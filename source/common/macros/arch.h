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

#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64)
    #define BLUBBER_ARCH amd64
    #define BLUBBER_ARCH_AMD64 1
#elif defined(__ARM64__) || defined(__aarch64__)
    #define BLUBBER_ARCH aarch64
    #define BLUBBER_ARCH_AARCH64 1
#elif defined(__arm__) || defined(__TARGET_ARCH_ARM)
    #define BLUBBER_ARCH arm
    #define BLUBBER_ARCH_ARM 1
#elif defined(__i386) || defined(__i386__)
    #define BLUBBER_ARCH x86
    #define BLUBBER_ARCH_X86 1
#else
    #error "Unsupported architecture for bubble detected!"
#endif
