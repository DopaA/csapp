	.file	"3_58_decode.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	subq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	imulq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	salq	$63, %rax
	sarq	$63, %rax
	xorq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
	.globl	decode
	.type	decode, @function
decode:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	subq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	imulq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	salq	$63, %rdx
	sarq	$63, %rdx
	xorq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	decode, .-decode
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
