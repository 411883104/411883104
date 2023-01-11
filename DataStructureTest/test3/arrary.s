	.file	"arrary.cpp"
	.intel_syntax noprefix
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
.LC0:
	.ascii " \0"
	.text
	.globl	_Z5printPPi
	.def	_Z5printPPi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printPPi
_Z5printPPi:
.LFB1048:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR -4[rbp], 0
	jmp	.L2
.L5:
	mov	DWORD PTR -8[rbp], 0
	jmp	.L3
.L4:
	mov	eax, DWORD PTR -4[rbp]
	add	eax, 1
	imul	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR 16[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	rdx, rax
	mov	rcx, QWORD PTR .refptr._ZSt4cout[rip]
	call	_ZNSolsEPKv
	lea	rdx, .LC0[rip]
	mov	rcx, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	add	DWORD PTR -8[rbp], 1
.L3:
	cmp	DWORD PTR -8[rbp], 1
	jle	.L4
	mov	rdx, QWORD PTR .refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_[rip]
	mov	rcx, QWORD PTR .refptr._ZSt4cout[rip]
	call	_ZNSolsEPFRSoS_E
	add	DWORD PTR -4[rbp], 1
.L2:
	cmp	DWORD PTR -4[rbp], 1
	jle	.L5
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1049:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 48
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	mov	DWORD PTR -16[rbp], 1
	mov	DWORD PTR -12[rbp], 2
	mov	DWORD PTR -8[rbp], 3
	mov	DWORD PTR -4[rbp], 4
	mov	eax, 0
	add	rsp, 48
	pop	rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB1060:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	lea	rcx, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitD1Ev
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB1059:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	DWORD PTR 16[rbp], ecx
	mov	DWORD PTR 24[rbp], edx
	cmp	DWORD PTR 16[rbp], 1
	jne	.L9
	cmp	DWORD PTR 24[rbp], 65535
	jne	.L9
	lea	rcx, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitC1Ev
	lea	rcx, __tcf_0[rip]
	call	atexit
	nop
.L9:
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__Z5printPPi;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z5printPPi
_GLOBAL__sub_I__Z5printPPi:
.LFB1061:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	edx, 65535
	mov	ecx, 1
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z5printPPi
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
