/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : at&t syntax (default)
 *
 * gcc -o asm_trampolining_optimization_shell_x86_atnt asm_trampolining_optimization_shell_x86_atnt.c -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -static -Wl,--omagic
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
	"shell:  popl %esi;"
       		"xorl %eax, %eax;"
       		"movb %eax, 0x7(%esi);"
       		"movl %esi, 0x8(%esi);"
       		"movl %eax, 0xc(%esi);"
       		"movb $0xb, %al;"
       		"movl %esi, %ebx;"
       		"leal 0x8(%esi), %ecx;"
       		"xorl %edx, %edx;"
       		"int $0x80;"
       		"xorl %ebx, %ebx;"
       		"movl %ebx, %eax;"
       		"inc %eax;"
       		"int $0x80;"
	"call:   call shell;"
      		".string \"/bin/sh\""
	);
}
