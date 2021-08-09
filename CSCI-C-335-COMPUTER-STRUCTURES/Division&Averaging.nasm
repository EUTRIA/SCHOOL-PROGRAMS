extern printf						; the C function, to be called 
     
%macro EXITPGM 0					; Macro has no parameters 
mov rax, 60 						;60 is the sys_exit number
mov rdi, 0							; sets status to 0
syscall 
%endmacro
 
section .data						; Data section, initialized variables

NUM    db    5						;defining numbers stored in memory
NUM1   db    5
NUM2   db    5
 	
format db "%d", 10, 0                	; The printf format, "\n",'0' 
	
section .text                       ; Code section.   
 
global main							; the standard gcc entry point
  
main:								; the program label for the entry point      
	    push    rbp					;set up stack frame, must be alligned
		
		mov		rax,NUM				;assign NUM to rax
		
		add		rax,NUM1 			;add register NUM1 value to rax. 
		add		rax,NUM2			;add register NUM2 value to rax.
		
		mov		rdx,0				; to avoid errors rdx is assigned 0 before div
		mov		rcx,3				; value we will use to divide rax
		div     rcx					; divide rax by rcx

print_avg:		 

		mov		rdi,format 			;first parameters for printf
		mov		rsi,rax			    ;second parameters for printf
		xor		rax,rax				; printf is vararg
		
		call    printf				; Call C function
	
		pop 	rbp					; restore stack
		
		mov 	rax,0				; normal, no error, return value
		ret							; return
		;EXITPGM	
