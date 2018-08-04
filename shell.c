#include <unistd.h>

// 64 bit machine
// gcc -o shell shell.c -fno-stack-protector -mpreferred-stack-boundary=4 -static

int main() {
	char *name[2] = {"sh", NULL};
	execve("/bin/sh", name, NULL);
	return 0;
}
