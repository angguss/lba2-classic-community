;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

		.386p

		.model SMALL, SYSCALL


;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

		.CODE

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

		public	SYSCALL	Distance2D
		public	SYSCALL	Distance3D

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

		extrn	SYSCALL	QSqr:PROC

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;U32	Distance2D(S32 x0, S32 y0, S32 x1, S32 y1)	;

;#pragma aux Distance2D	"*"			\
;	parm		[eax] [ecx] [ebx] [edx]	\
;	modify		[esi edi]

Distance2D	proc

		sub	eax, ebx		; Dx = x0-x1
		sub	ecx, edx		; Dy = y0-y1
		imul	eax			; Dx�
		mov	esi, eax
		mov	eax, ecx
		mov	edi, edx
		imul	eax			; Dy�
		add	eax, esi		; Dx� + Dy�
		adc	edx, edi		; ...

		jmp	QSqr			; eax = � (Dx�+Dy�)

Distance2D	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;U32	Distance3D(S32 x0, S32 y0, S32 z0, S32 x1, S32 y1, S32 z1)	;

;#pragma aux Distance3D	"*"					\
;	parm		[eax] [ecx] [ebx] [edx]	[esi] [edi]	\
;       modify		[esi edi]

Distance3D	proc

		sub	eax, edx
		sub	ecx, esi
		imul	eax			; Dx�
		sub	ebx, edi
		mov	esi, eax
		mov	eax, ecx
		mov	edi, edx
		imul	eax			; Dy�
		add	esi, eax
		mov	eax, ebx
		adc	edi, edx
		imul	eax			; Dz�
		add	eax, esi
		adc	edx, edi

		jmp	QSqr			; eax = � (Dx�+Dy�+Dz�)

Distance3D	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
		;The
		 End

