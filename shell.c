#include <unistd.h>

/*
 * build machine - 64 bit
 * In order to build 32 bit binary on 64 bit machine, -m32 and -mpreferred-stack-boundary=2 options are used
 * -m32 / -m64 is needed to install gcc-multilib package
 *
 * gcc -o shell shell.c -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -static
 */
int main() {
	char *name[2] = {"/bin/sh", NULL};
	execve(name[0], name, NULL);
	return 0;
}
