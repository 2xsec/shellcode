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
#if 0
	char *name[2] = {"sh", NULL};
	execve("/bin/sh", name, NULL);
#else
	/* On Linux, argv can be specified as NULL, which has the same effect as specifying this argument as a pointer to a list containing a single NULL pointer.
	   Do not take advantage of this misfeature! It is nonstandard and nonportable: on most other UNIX systems doing this will result in an error (EFAULT).
	   (https://linux.die.net/man/2/execve)

	   execve()의 두번째 파라미터를 NULL로 설정할 경우 shell code의 byte수를 줄이는 효과가 있지만, 위와 같은 이유로,
	   일부 system에서 두번째 파라미터가 null일 경우 정상적으로 동작하지 않을 가능성도 있다.

	   => build warning
	   shell.c: In function ‘main’:
	   shell.c:26:2: warning: null argument where non-null required (argument 2) [-Wnonnull]
	     execve("/bin/sh", NULL, NULL);
	     ^
	 */
	execve("/bin/sh", NULL, NULL);
#endif
	return 0;
}
