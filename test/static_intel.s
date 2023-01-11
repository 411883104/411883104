	.file	"static.cpp"
	.intel_syntax noprefix
.lcomm _ZStL8__ioinit,1,1
	.globl	num
	.data
	.align 4
num:
	.long	5
	.globl	_ZN4test3numE
	.align 4
_ZN4test3numE:
	.long	10
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1048:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	mov	eax, DWORD PTR num[rip]
	mov	edx, eax
	mov	rcx, QWORD PTR .refptr._ZSt4cout[rip]
	call	_ZNSolsEi
	mov	rdx, QWORD PTR .refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_[rip]
	mov	rcx, rax
	call	_ZNSolsEPFRSoS_E
	mov	eax, DWORD PTR _ZN4test3numE[rip]
	mov	edx, eax
	mov	rcx, QWORD PTR .refptr._ZSt4cout[rip]
	call	_ZNSolsEi
	mov	rdx, QWORD PTR .refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_[rip]
	mov	rcx, rax
	call	_ZNSolsEPFRSoS_E
	mov	eax, 0
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB1055:
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
.LFB1054:
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
	jne	.L4
	cmp	DWORD PTR 24[rbp], 65535
	jne	.L4
	lea	rcx, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitC1Ev
	lea	rcx, __tcf_0[rip]
	call	atexit
	nop
.L4:
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_num;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_num
_GLOBAL__sub_I_num:
.LFB1056:
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
	.quad	_GLOBAL__sub_I_num
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
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
