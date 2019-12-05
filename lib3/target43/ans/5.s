movq %rsp,%rax
movq %rax,%rdi
popq %rax
mov %eax,%ecx
mov %ecx,%edx
mov %edx,esi
lea (%rdi,%rsi,1),%rax
mov %rax,%rdi
