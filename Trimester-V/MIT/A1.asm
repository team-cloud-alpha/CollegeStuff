section .data
v1 db "Enter name: "
v1l equ $-v1
v2 db "Enter roll: "
v2l equ $-v2
v3 db "Enter class: "
v3l equ $-v3
v4 db "Name: "
v4l equ $-v4
v5 db "Roll: "
v5l equ $-v5
v6 db "Class: "
v6l equ $-v6


%macro read 2
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro write 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro	
	
section .bss
name: resb 20
roll: resb 20
class: resb 1
	
section .text
	global _start
_start:
	write v1, v1l
	read name, 20
	write v2, v2l
	read roll, 20
	write v3, v3l
	read class, 1
	write v4, v4l
	write name, 20
	write v5, v5l
	write roll, 20
	write v6, v6l
	write class, 1
	mov rax, 60
	mov rdi, 0
	syscall
