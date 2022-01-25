global ft_write
section .text
extern __errno_location ;this thing will return the address of the errno variable

;syscal write rax - 1,  rdi - fd, rsi - buf, rdx count
;function call rdi - fd, rsi -buff, rdx - count

ft_write:
	mov rax,1
	syscall
	cmp rax,0
	jl error
	ret 

error:
;negative value in case of error and if we get rid of minus it will be the errno value
	neg rax
	mov rdi,rax ;errno location will return the pointer in rax register so we need to save error code
	call __errno_location wrt ..plt;errno location now in rax
	mov [rax], rdi ;now the errno code is in memory which rax points to
	mov rax, -1 ;now rax dont have the address of errno but will have the return value of -1 which means the error happened
	ret


;
;Calling procedures outside your shared library has to be done by means of
; a procedure linkage table, or PLT. The PLT is placed at a known offset 
;from where the library is loaded, so the library code can make calls to 
; the PLT in a position-independent way. Within the PLT there is code to 
; jump to offsets contained in the GOT, so function calls to other shared
;  libraries or to routines in the main program can be transparently passed
;   off to their real destinations.

;To call an external routine, you must use
; another special PIC relocation type, WRT ..plt.
;  This is much easier than the GOT-based ones:
;   you simply replace calls such as CALL printf 
;   with the PLT-relative version CALL printf WRT ..plt. 