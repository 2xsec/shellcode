/*
 * build 32 bit(-m32) binary on 64 bit machine
 * assembly : intel syntax
 *
 * gcc -o asm_optimization_shell_23_intel asm_optimization_shell_23_intel.c -m32 -masm=intel -mpreferred-stack-boundary=2
 */
void main()
{
	__asm__(
	"xor eax, eax;"
	"push eax;"
	"push 0x68732f2f;"
	"push 0x6e69622f;"
	"mov ebx, esp;"
	"mov ecx, eax;"
	"mov edx, eax;"
	"mov al, 0xb;"
	"int 0x80;"
	);
}
