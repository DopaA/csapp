	.file	"3_59_store_prod.c"
	.text
	.globl	store_prod
	.type	store_prod, @function
store_prod:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %r8
	sarq	$63, %rax
	movq	%rax, %r9
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	sarq	$63, %rax
	movq	%rax, %rbx
	movq	%r9, %rdx
	imulq	%rcx, %rdx
	movq	%rbx, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rsi
	movq	%r8, %rax
	mulq	%rcx
	leaq	(%rsi,%rdx), %rcx
	movq	%rcx, %rdx
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	nop
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	store_prod, .-store_prod
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
