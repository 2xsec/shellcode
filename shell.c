#include <unistd.h>

/*
 * build machine - 64 bit
 * In order to build 32 bit binary on 64 bit machine, -m32 and -mpreferred-stack-boundary=2 options are used
 * -m32 / -m64 is needed to install gcc-multilib package
 *
 * 32 bit build
 * gcc -o shell shell.c -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -static
 *
 * 64 bit build
 * gcc -o shell shell.c -m64 -fno-stack-protector -mpreferred-stack-boundary=4 -static
 */
int main() {
	char *name[2] = {"sh", NULL};
	execve("/bin/sh", name, NULL);
	return 0;
}
