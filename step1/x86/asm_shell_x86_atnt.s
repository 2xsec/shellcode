movl $.LC0, %esi;
movb $0x0, 0x7(%esi);
movl %esi, 0x8(%esi);
movl $0x0, 0xc(%esi);
movl $0xb, %eax;
movl %esi, %ebx;
leal 0x8(%esi), %ecx;
movl $0x0, %edx;
int $0x80;
movl $0x1, %eax;
movl $0x0, %ebx;
int $0x80;

.LC0: .string "/bin/sh"
