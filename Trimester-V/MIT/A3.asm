section .data
arr times 64 db 0
msg db "Enter numbers : ", 10
msgLen equ $-msg
msgNum db "Num - "
msgNumLen equ $-msgNum
msgDone db "Sum = "
msgDoneLen equ $-msgDone
nwln equ 10
count db 5

%macro rw 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

%macro unpack 1
    mov rax, 0
    mov rsi, %1
    mov rbx, 0
l1:    
    mov bl, byte[rsi]
    cmp bl, 0ah
    je packed
    cmp bl, 39h
    jbe l2
    sub bl, 07h
l2:
    sub bl, 30h
    rol al, 4
    add al, bl
    inc rsi
    jmp l1
packed:
%endmacro


section .bss
num: resb 3
sum: resb 2
temp: resb 2
temp2: resb 2

section .text
    global _start
_start:
    mov rbp, arr
    mov cl, 5
    rw 1, 1, msg, msgLen
    rw 1, 1, nwln, 2
readnext:
    rw 1, 1, msgNum, msgNumLen
    rw 0, 0, num, 3
    unpack num
    mov byte[rbp], al
    inc rbp
    dec byte[count]
    jnz readnext

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

    mov word[sum], ax
    rw 1, 1, msgDone, msgDoneLen
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
    mov [temp2],al
    rw 1, 1, temp2,1
    
    mov ax,[temp]
    dec bp
    jnz l4
    rw 60, 0, 0, 0