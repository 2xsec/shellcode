/*
 * build 32 bit binary(-m32) on 64 bit machine
 * assembly : intel syntex (-masm=intel)
 *
 * gcc -o asm_trampolining_shell_x86_intel asm_trampolining_shell_x86_intel.c -m32 -masm=intel -fno-stack-protector -mpreferred-stack-boundary=2 -static -Wl,--omagic
 *
 * This shell code must write some codes to code section. So, write permission is needed in code section.
 * To change permission of code section, we can use "-Wl,--omagic" compile option.
 *
 * We can check the permission of code section using "readelf -S". => Flg field in Section Headers:
 * AX : read / execute
 * WAX : read / write / execute  
*/
void main()
{
	__asm__(
       		"jmp call;"
	"shell: pop esi;"
       		"mov BYTE PTR [esi+0x7], 0x0;"
       		"mov DWORD PTR [esi+0x8], esi;"
       		"mov DWORD PTR [esi+0xc], 0x0;"
       		"mov eax, 0xb;"
       		"mov ebx, esi;"
       		"lea ecx, DWORD PTR [esi+0x8];"
       		"mov edx, 0x0;"
       		"int 0x80;"
       		"mov eax, 0x1;"
       		"mov ebx, 0x0;"
       		"int 0x80;"
	"call:  call shell;"
      		".string \"/bin/sh\""
	);
}
