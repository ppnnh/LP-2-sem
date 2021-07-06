.586
.model flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.stack 4096

.const

.data
   myBytes BYTE 10h, 20h, 30h, 40h
   myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
   myDoubles DWORD 1, 2, 3, 4, 5, 6
   myPointer DWORD myDoubles
   myarray DD 1, 2, 3, 4, 5, 6, 7
   sum byte 0h
   v DD "0", 0
   HW DD ?
   STR1 byte "Буранко В.Д., 1 курс, 5 группа", 0
   MB_OK EQU 1

.code

main PROC
start:
    mov ESI, 0
    mov EAX, myDoubles[ESI]
    mov EDX, [myDoubles+ESI]

  	mov ECX,7
	mov EAX,0
	mov EDX,0
CYCLE:
	add EAX,[myarray+EDX]
	cmp [myarray+EDX],0
	jz jzx
metka:
	add EDX,4
loop CYCLE
	jmp jznx
jzx:
	mov ebx,0
	jmp metka
oneebx:
	mov ebx,1
	jmp fin
jznx:
	cmp ebx,0
	jnz oneebx
fin:

	add v,EBX

    INVOKE MessageBoxA, HW, offset v, offset STR1, MB_OK
    
    push -1
    call ExitProcess
main ENDP

end main