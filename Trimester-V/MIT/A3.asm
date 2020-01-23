%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

%macro print 2
rw 1,1,%1,%2
%endmacro

%macro read 2
rw 0,0,%1,%2
%endmacro

section .data
	arr times 64 db 0
	msg db "Enter numbers : "
	msgLen equ $-msg
	msgNum db "Num - "
	msgNumLen equ $-msgNum
	msgDone db "Sum = "
	msgDoneLen equ $-msgDone
	count db 5

section .bss
	num resb 3
	sum resb 2
	temp resb 2
	temp1 resb 2
	
section .text
	global _start
	_start:
		mov rbp, arr
		print msg, msgLen
	readnum:
		print msgNum,msgNumLen
		read num,3
		mov rcx,0
		mov rax,0
		mov rsi,num
	l1:
		mov cl,byte[rsi]
		cmp cl,0ah
		je packed
		cmp cl,39h
		jbe l2
		sub cl,07h
	l2:
		sub cl,30h
		rol al,4
		add al,cl
		inc rsi
		jmp l1
	packed:
		mov byte[rbp],al
		inc rbp
		dec byte[count]
		jnz readnum
		
		mov rsi,arr
		mov ax,0h
		mov bx,0h
		mov cx,5
	
	l3:	
		mov bl,byte[rsi]
		add ax,bx
		jnc skip
		inc ah
	skip:
		inc rsi
		dec cx
		jnz l3
		
		mov word[sum],ax
		print msgDone,msgDoneLen
		call display
	exit:
		mov rax,60
		mov rdi,0
		syscall
	display:
		mov bp,4
		mov ax,word[sum]
	l4:
		rol ax, 4
		mov [temp], ax
		and ax,0fh
		cmp al, 09
		jbe l5
		add al,07
	l5:
		add al,30h
		mov [temp1],al
		print temp1,1
		
		mov ax,[temp]
		dec bp
		jnz l4
		ret
