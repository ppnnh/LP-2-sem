.586
.model flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.stack 4096

.const
.data
a byte 5h
b byte 4h
MB_OK EQU 0
STR1 DB "Результат сложения:", 0
v byte "0", 0
HW DD ?

.code

main PROC 
    mov ah, a
    add ah, b
    add v, ah
    INVOKE MessageBoxA, HW, offset v, offset STR1, MB_OK

    push 0
    call ExitProcess
main ENDP

end main