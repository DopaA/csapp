	.file	"3_63_switch_prob.c"
	.text
	.globl	switch_prob
	.type	switch_prob, @function
switch_prob:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	subq	$60, %rax
	cmpq	$5, %rax
	ja	.L2
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L7:
	movq	-24(%rbp), %rax
	salq	$3, %rax
	movq	%rax, -8(%rbp)
	jmp	.L8
.L6:
	movq	-24(%rbp), %rax
	sarq	$3, %rax
	movq	%rax, -8(%rbp)
	jmp	.L8
.L5:
	movq	-24(%rbp), %rax
	movl	$4, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %ecx
	salq	%cl, -24(%rbp)
.L3:
	movq	-24(%rbp), %rax
	imulq	-24(%rbp), %rax
	movq	%rax, -24(%rbp)
.L2:
	movq	-24(%rbp), %rax
	addq	$75, %rax
	movq	%rax, -8(%rbp)
.L8:
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	switch_prob, .-switch_prob
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
