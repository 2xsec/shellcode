/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : at&t syntax (default)
 *
 * gcc -o asm_shell_x86_atnt asm_shell_x86_atnt.c -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -static -Wl,--omagic
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
	"movl $.LC0, %esi;"
	"movb $0x0, 0x7(%esi);"
	"movl %esi, 0x8(%esi);"
	"movl $0x0, 0xc(%esi);"
	"movl $0xb, %eax;"
	"movl %esi, %ebx;"
	"leal 0x8(%esi), %ecx;"
	"movl $0x0, %edx;"
	"int $0x80;"
	"movl $0x1, %eax;"
	"movl $0x0, %ebx;"
	"int $0x80;"

	".LC0: .string \"/bin/sh\";"
	);
}
