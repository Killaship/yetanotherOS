; (C) Killaship 2022
; all rights reserved? I dunno, closed source
bits 32

section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002              ;magic
        dd 0x00                    ;flags
        dd - (0x1BADB002 + 0x00)   ;checksum. m+f+c should be zero


gdt_start:
	dq 0x0
gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0
gdt_data:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0
gdt_end:
gdt_pointer:
	dw gdt_end - gdt_start
	dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

global start
;global keyboard_handler

extern kmain 		;this is defined in the c file
;extern keyboard_handler_main
;extern pithandler
;keyboard_handler:                 
;	call    keyboard_handler_main
; iretd

start:
     lgdt [gdt_pointer]  
    ; xor ebp, ebp
     ;jmp CODE_SEG:($+1)
    ; push ebx
    ; call kmain
   jmp CODE_SEG:kernelcall
    .setcs:
    mov ax, DATA_SEG          ; Setup the segment registers with our flat data selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, stack_space        ; set stack pointer		

kernelcall:
;	push ebx
	call kmain
	sti
	hlt

section .bss
resb 8192; 8KB for stack
stack_space:
