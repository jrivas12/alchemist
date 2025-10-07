TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data

myMessage BYTE "Please enter the name",0dh,0ah,0
mymessage2 byte "Please enter 3 grades",0dh,0ah,0
name1 byte "              ",0
name2 byte "              ",0ah,0dh,0
msg byte "'s sum is ",0

.Code
;--------------------------GetName------------------------------
getName proc
	mov edx, offset mymessage
	call writestring
	mov edx, ebx
	mov ebx, eax
	call readstring				;ebx better have our sum before this!!

ret
getName endp
;--------------------------end of GetName--------------------------

;-------------------------GetGrades--------------------------------
getGrades proc

mov edx, offset mymessage2
call writestring
call readint
mov ebx, eax
call readint
add ebx, eax
call readint
add ebx, eax		;ebx has our sum!
ret
getGrades endp
;---------------------------end of Get Grades----------------------

;------------------------------Display-----------------------------
display proc
	mov edx, offset name1
	call writestring
	mov edx, offset msg
	call writestring
	mov eax, ecx
	call writeint
	call crlf

	mov edx, offset name2
	call writestring
	mov edx, offset msg
	call writestring
	mov eax, ebx
	call writeint
	call crlf
ret
display endp
;---------------------------------end of display--------------------


main PROC
	;call Clrscr					;clear screen
	
	
	mov ecx, sizeof name1
	mov ebx, offset name1
	call getname

	call getgrades
	
	mov eax, ebx			;first sum is in eax!
	mov ecx, sizeof name2
	mov ebx, offset name2

	call getname

	mov ecx, ebx
	call getgrades
	;ebx has 2nd sum, ecx has first sum.

	call display

	

	exit
main ENDP

END main