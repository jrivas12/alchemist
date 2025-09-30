TITLE MASM Homework6

INCLUDE Irvine32.inc

; Author:    Joe L. Rivas
; Date:      2024-10-04

.data
    myMessage BYTE "Please enter an integer: ", 0
    myMessage1 BYTE "Choose an option:", 0
    myMessage2 BYTE "1) Get Area", 0
    myMessage3 BYTE "2) Get Perimeter", 0ah, 0dh, 0
    subMessage BYTE "Choose a shape", 0
    subMessage1 BYTE "1) Rectangle", 0
    subMessage2 BYTE "2) Triangle", 0
    subMessage3 BYTE "3) Circle", 0ah, 0dh, 0
    piValue DWORD 314
    number DWORD ?
    len DWORD ?
    result DWORD ?

.code

;---------------------------- Area Logic ----------------------------

GetArea PROC

    ; area shape submenu
    mov edx, OFFSET subMessage
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage1
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage2
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage3
    call WriteString
    call ReadInt

    cmp eax, 1
    je getAreaRectangle
    cmp eax, 2
    je getAreaTriangle
    cmp eax, 3
    je getAreaCircle

    ret
GetArea ENDP

getAreaRectangle PROC
    mov eax, number
    mov ebx, eax
    add eax, eax
    mov len, eax

    ; calculate rectangle area
    mov eax, len
    mul ebx
    mov result, eax

    call WriteDec
    call Crlf
    ret
getAreaRectangle ENDP

getAreaTriangle PROC
    ; calculate triangle area
    mov eax, number
    mul eax
    mov result, eax
    
    call WriteDec
    call Crlf
    ret
getAreaTriangle ENDP

getAreaCircle PROC
    ; calculate circle area
    mov eax, number
    mov ebx, eax
    mul ebx

    ; Multiply by piValue
    mov ebx, piValue
    mul ebx

    mov ecx, 100
    div ecx
    mov result, eax

    call WriteDec
    call Crlf
    ret
getAreaCircle ENDP

;---------------------------- Perimeter Logic ----------------------------

GetPerimeter PROC

    ; perimeter shape submenu
    mov edx, OFFSET subMessage
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage1
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage2
    call WriteString
    call Crlf
    mov edx, OFFSET subMessage3
    call WriteString
    call ReadInt

    cmp eax, 1
    je getPerimeterRectangle
    cmp eax, 2
    je getPerimeterTriangle
    cmp eax, 3
    je getPerimeterCircle

    ret
GetPerimeter ENDP

getPerimeterRectangle PROC
    mov eax, number
    mov ebx, eax
    add eax, eax
    mov len, eax

    ; Calculate perimeter
    add eax, ebx
    add eax, eax 
    mov result, eax

    call WriteDec
    call Crlf
    ret
getPerimeterRectangle ENDP

getPerimeterTriangle PROC
    mov eax, number
    add eax, eax
    add eax, number
    mov result, eax

    call WriteDec
    call Crlf
    ret
getPerimeterTriangle ENDP

getPerimeterCircle PROC
    mov eax, number
    add eax, eax

    ; Multiply by piValue
    mov ebx, piValue
    mul ebx
 
    mov ecx, 100
    div ecx
    mov result, eax

    call WriteDec
    call Crlf
    ret
getPerimeterCircle ENDP
;---------------------------- main ----------------------------
main PROC

    call Clrscr

    ; user input
    mov edx, OFFSET myMessage
    call WriteString
    call ReadInt
    mov number, eax

    cmp eax, 1
    jl ExitProgram

    ; main menu prompt
    mov edx, OFFSET myMessage1
    call WriteString
    call Crlf
    mov edx, OFFSET myMessage2
    call WriteString
    call Crlf
    mov edx, OFFSET myMessage3
    call WriteString
    call ReadInt

    cmp eax, 1
    je GetArea
    cmp eax, 2
    je GetPerimeter

    jmp main

ExitProgram:
    call Crlf
    exit
main ENDP

END main