section .data
v1 db "Enter number: "
v1len equ $-v1
v2 db "Packing is successfully completed"
v2len equ $-v2

%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .bss
num: resb 4

section .text
	global _start
_start:
	rw 1, 1, v1, v1len
	rw 0, 0, num, 4
	mov rsi, num
	mov rcx, 2
	mov rax, 0
l1:	rol al, 4
	mov bl, [rsi]
	cmp bl, 39
	jbe l2
	sub bl, 07
l2: sub bl, 30
	add al, bl
	inc rsi
	dec rcx
	jnz l1
	rw 1, 1, v2, v2len
	rw 60, 0, 0, 0
