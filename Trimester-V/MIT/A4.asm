section .data
menu db "MENU", 10
        db "1. Enter string", 10
        db "2. Calculate length of the string", 10
        db "3. Check if string is palindrome", 10
        db "4. Reverse string", 10
        db "5. Exit", 10
        db "Enter your choice: "
menulen equ $-menu

m1 db 10d,"Enter String: "
l1 equ $-m1
m2 db 10d,"Length Of String: "
l2 equ $-m2
m3 db 10d,"Reversed String: "
l3 equ $-m3
m4 db 10d,"String is Palindrome!!!", 10
l4 equ $-m4
m5 db 10d,"String is not Palindrome!!!", 10
l5 equ $-m5

nwln db 10

%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .bss
string: resb 20
strlen: resb 3
string2: resb 20
count: resb 3
choice: resb 2

section .text
    global _start

_start:
    rw 1, 1, nwln, 2
    rw 1, 1, menu, menulen
    rw 0, 0, choice, 2

    cmp byte[choice],'1'
    je case1
    cmp byte[choice],'2'
    je case2
    cmp byte[choice],'3'
    je case3
    cmp byte[choice],'4'
    je case4
    cmp byte[choice],'5'
    je exit

case1:
    rw 1, 1, m1, l1
    rw 0, 0, string, 20
    dec rax
    mov byte[strlen], al
    mov byte[count], al

    jmp _start

case2:
    rw 1, 1, m2, l2
    add byte[strlen], 30h
    rw 1, 1, strlen, 3
    rw 1, 1, nwln, 2

    jmp _start

case3:
    mov rsi, string
    mov rdi, string
    mov rcx, [count]
until_endstr:
    inc rdi
    dec cx
    jnz until_endstr
    dec rdi

iterate:
    mov al, [rsi]
    cmp al, [rdi]
    je still_palindrome
    rw 1, 1, m5, l5
    jmp _start

still_palindrome:
    inc rsi
    dec rdi
    dec byte[count]
    jnz iterate
    rw 1, 1, m4, l4

    jmp _start

case4:
    mov rsi, string
    mov rdi, string2
    mov rcx, [count]
until_endstr2:
    inc rsi
    dec cx
    jnz until_endstr2
    dec rsi

iterate2:
    mov al, [rsi]
    mov [rdi], al
    inc rdi
    dec rsi
    dec byte[count]
    jnz iterate2

    rw 1, 1, m3, l3
    rw 1, 1, string2, 20
    rw 1, 1, nwln, 2

    jmp _start

exit:
    rw 60, 0, 0, 0