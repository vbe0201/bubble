.intel_syntax noprefix

//
// The global entrypoint to the program.
//
// The arguments are encoded on the stack, then supplied to
// main() via registers:
//
//   argc: %rdi
//   argv: %rsi
//
.text
.global _start
_start:
    // Clear the frame pointer to mark the outermost frame.
    xor rbp, rbp

    // Load argc and argv from stack into registers.
    pop rdi
    mov rsi, rsp

    // Align the stack to 16 byte boundary to follow the ABI.
    and rsp, ~15

    // Jump to the C entrypoint.
    call main

    // Terminate the program with an exit syscall. The return
    // value of the main() call is in the rax register.
    mov rdi, rax
    mov rax, 60
    syscall

    // If exit somehow manages to return, crash the process.
    hlt
