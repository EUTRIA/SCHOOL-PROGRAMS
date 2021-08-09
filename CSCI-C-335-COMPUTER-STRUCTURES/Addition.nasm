extern printf						; the C function, to be called      
 
section .data						; Data section, initialized variables
 	
 format:   
	db "%d", 10, 0                	; The printf format, "\n",'0' 
	
section .text                       ; Code section.   
 
global main							; the standard gcc entry point
  
main:								; the program label for the entry point      
	    push    rbp					;set up stack frame, must be alligned
		
		mov		rax,1 				;assign 1 to rax
		mov		rbx,4 				;assign 4 to rbx
		mov		rcx,0				;assign 0 to rcx 
		add		rax,rbx 			;add register rbx's value to rax. = 5
		add		rax,rcx				;add register rcx's value to rax.= 5

print:		

		mov		rdi,format 			;first parameters for printf
		mov		rsi,rax			    ;second parameters for printf
		xor		rax,rax				; printf is vararg
		
		call    printf				; Call C function
	
		pop 	rbp					; restore stack
	
		mov 	rax,0				; normal, no error, return value
		ret							; return
