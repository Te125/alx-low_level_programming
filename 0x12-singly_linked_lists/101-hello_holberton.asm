section .data
    hello: db 'Hello, Holberton', 10, 0

section .text
    global main

    extern printf

main:
    ; Load the address of the hello string into RDI
    lea rdi, [hello]

    ; Call printf to print the string
    mov eax, 0
    call printf

    ; Return 0 to indicate success
    mov eax, 0
    ret

