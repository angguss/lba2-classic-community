				.386P
				.model SMALL, SYSCALL

				.data
;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

			;// Offsets Y sur ecran Hercule
			extrn	SYSCALL	HTabY:DWORD
			extrn	SYSCALL	ModeHercule:DWORD
			extrn	SYSCALL	HCurY:DWORD
			extrn	SYSCALL	HCurX:DWORD

			;// Fonction de detection de la presence d'une
			;// carte hercule

			public	SYSCALL	TestHercule

			;// Fonctions textes
			public	SYSCALL      HCls
			public	SYSCALL      HPrintCar
			public	SYSCALL      HPrintCarC
			public	SYSCALL      HString
			public	SYSCALL      HStringC

			public	SYSCALL	HScrollUp
			public	SYSCALL	HScrollDown

			;// Fonctions Semi-Graphiques
			public	SYSCALL      HLineH
			public	SYSCALL      HLineV
			public	SYSCALL      HColor
			public	SYSCALL      HColorBox
			public	SYSCALL      HClsBox

SCRBASE		EQU	0B0000h

				.code


;/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;			栩栩栩� 栩� 栩� 栩栩栩� 栩栩栩�
;                       青栩敖� 栩杰栩� 青栩敖� 青栩敖�
;                         栩�   栩栩栩�   栩�     栩�
;                         栩�   栩无栩�   栩�     栩�
;                       栩栩栩� 栩垣栩� 栩栩栩�   栩�
;                       青陳陳� 青� 青� 青陳陳�   青�
;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	S32	TestHercule( void )

TestHercule	proc
		mov	eax, 01a00h
		int	10h

		cmp	al, 01ah
		jne	NoHerc		;// Fonction BIOS non support�e

		and	ebx, 0101h	;// regarde les 2 cartes videos possibles
		mov     [ModeHercule], ebx

		mov	eax, ebx	;// valeur de retour
		ret

NoHerc:         xor	eax, eax
		mov	[ModeHercule], eax
		ret

TestHercule	endp

;/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;	    栩栩栩� 栩� 栩� 栩栩栩� 栩栩栩� 栩� 栩� 栩栩栩� 栩栩栩�
;	    栩敖陳� 栩� 栩� 栩敖栩� 青栩敖� 栩杰栩� 栩敖陳� 栩敖陳�
;	    栩�     栩栩栩� 栩栩栩�   栩�   栩栩栩� 栩栩杰  栩栩栩�
;	    栩�     栩敖栩� 栩敖栩�   栩�   栩无栩� 栩敖潰  青陳栩�
;	    栩栩栩� 栩� 栩� 栩� 栩� 栩栩栩� 栩垣栩� 栩栩栩� 栩栩栩�
;	    青陳陳� 青� 青� 青� 青� 青陳陳� 青� 青� 青陳陳� 青陳陳�
;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HCls( void )

HCls		proc	uses edi

		xor	eax, eax
		mov	HCurX, eax
		mov	HCurY, eax

		mov	edi, SCRBASE
		mov	eax, 07000700h
		mov	ecx, 1000	;// 4000 octets
		rep	stosd

		ret

HCls		endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HPrintCar( S32 x, S32 y, char car )
;//			      eax    ebx      ecx

HPrintCar	proc

		mov	ebx, HTabY[ebx*4]
		shl	eax, 1
		add	ebx, eax
		mov	byte ptr [ebx], cl

		ret

HPrintCar	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HPrintCarC( S32 x, S32 y, U8 attr, char car )
;//			       eax    ebx    ecx        edx

HPrintCarC	proc

		mov	ebx, HTabY[ebx*4]
		shl	eax, 1
		add	ebx, eax
		mov	dh, cl
		mov	word ptr [ebx], dx

		ret

HPrintCarC	endp


;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HString( S32 x, S32 y, char *string )
;//		            eax    ebx      ecx

HString		proc

		mov	ebx, HTabY[ebx*4]
		shl	eax, 1
		add	ebx, eax

another:	mov	al, byte ptr [ecx]
		or	al, al
		jz	fin
		mov	byte ptr [ebx], al
		inc	ecx
		add	ebx, 2
		jmp	another

fin:		ret

HString		endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HStringC( S32 x, S32 y, U8 attr, char *string )
;//		            eax    ebx     ecx         edx

HStringC	proc

		mov	ebx, HTabY[ebx*4]
		shl	eax, 1
		add	ebx, eax

		mov	ah, cl

another:	mov	al, byte ptr [edx]
		or	al, al
		jz	fin
		mov	word ptr [ebx], ax
		inc	edx
		add	ebx, 2
		jmp	another

fin:		ret

HStringC	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HScrollUp( void )

HScrollUp	proc

		;// Copy les 24 dernieres lignes � la premiere ligne
		mov	esi, SCRBASE+160
		mov	edi, SCRBASE
		mov	ecx, 1000-40	;// 4000 octets - 160 octets
		rep	movsd

		;// Efface la derniere ligne
		mov	edi, SCRBASE+24*160
		mov	eax, 07000700h
		mov	ecx, 40	;// 160 octets
		rep	stosd

		ret

HScrollUp	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HScrollDown( void )

HScrollDown	proc

		;// Copie les 24 premieres lignes � la deuxieme ligne
		mov	esi, SCRBASE+24*160-4
		mov	edi, SCRBASE+25*160-4
		mov	ecx, 1000-40	;// 4000 octets - 160 octets
		std
		rep	movsd
		cld

		;// Efface la premiere ligne
		mov	edi, SCRBASE
		mov	eax, 07000700h
		mov	ecx, 40	;// 160 octets
		rep	stosd

		ret

HScrollDown	endp

;/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;	栩栩栩� 栩栩栩� 栩栩栩� 栩栩栩� 栩� 栩� 栩栩栩� 栩栩栩� 栩栩栩�
;	栩敖陳� 栩敖栩� 栩敖栩� 栩敖栩� 栩� 栩� 青栩敖� 栩敖陳� 栩敖陳�
;	栩額栩� 栩栩栩� 栩栩栩� 栩栩栩� 栩栩栩�   栩�   栩�     栩栩栩�
;	栩垣栩� 栩无框� 栩敖栩� 栩敖陳� 栩敖栩�   栩�   栩�     青陳栩�
;	栩栩栩� 栩垣栩� 栩� 栩� 栩�     栩� 栩� 栩栩栩� 栩栩栩� 栩栩栩�
;	青陳陳� 青� 青� 青� 青� 青�     青� 青� 青陳陳� 青陳陳� 青陳陳�
;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HLineH( S32 y, S32 x0, S32 x1, char car )
;//			   eax    ebx     ecx       edx

HLineH		proc

		mov	eax, HTabY[eax*4]
		sub	ecx, ebx		;// x1-x0
		inc	ecx
		shl	ebx, 1
		add	eax, ebx

bclh:		mov	byte ptr [eax], dl
		add	eax, 2
		dec	ecx
		jnz	bclh

		ret

HLineH		endp


;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HLineV( S32 x, S32 y0, S32 y1, char car )
;//			   eax    ebx     ecx       edx

HLineV		proc

		sub	ecx, ebx		;// y1-y0
		inc	ecx
		mov	ebx, HTabY[ebx*4]
		shl	eax, 1
		add	ebx, eax

bclv:		mov	byte ptr [ebx], dl
		add	ebx, 160
		dec	ecx
		jnz	bclv

		ret

HLineV		endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HColor( S32 y, S32 x0, S32 x1, U8 attr )
;//			   eax    ebx     ecx     edx

HColor		proc

		mov	eax, HTabY[eax*4]
		sub	ecx, ebx		;// x1-x0
		inc	ecx
		shl	ebx, 1
		add	eax, ebx
		inc	eax			;// passe sur l'attribut

bclc:		mov	byte ptr [eax], dl
		add	eax, 2
		dec	ecx
		jnz	bclc

		ret

HColor		endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HColorBox( S32 x0, S32 y0, S32 x1, S32 y1, U8 attr )
;//			      esi     eax     ebx     ecx     edx

HColorBox	proc

		sub	ebx, esi		;// x1-x0
		inc	ebx
		sub	ecx, eax		;// y1-y0
		inc	ecx

		mov	eax, HTabY[eax*4]	;// calcul adresse de debut
		shl	esi, 1
		add	eax, esi
		inc	eax			;// passe sur l'attribut

		mov	esi, 80			;// offset pour passer � la
		sub	esi, ebx		;// ligne suivante
		shl	esi, 1

bclcy: 		mov	edi, ebx		;// restore dx
bclcx:		mov	byte ptr [eax], dl
		add	eax, 2
		dec	edi
		jnz	bclcx
		add	eax, esi		;// passe � la ligne suivante
		dec	ecx
		jnz	bclcy

		ret

HColorBox	endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;//	void	HClsBox( S32 x0, S32 y0, S32 x1, S32 y1, U8 attr )
;//		            esi     eax     ebx     ecx     edx

HClsBox		proc

		sub	ebx, esi		;// x1-x0
		inc	ebx
		sub	ecx, eax		;// y1-y0
		inc	ecx

		mov	eax, HTabY[eax*4]	;// calcul adresse de debut
		shl	esi, 1
		add	eax, esi

		shl	edx, 8			;// passe attribut sur poids fort
		mov	dl, 32			;// espace

		mov	esi, 80			;// offset pour passer � la
		sub	esi, ebx		;// ligne suivante
		shl	esi, 1

bclcy: 		mov	edi, ebx		;// restore dx
bclcx:		mov	word ptr [eax], dx
		add	eax, 2
		dec	edi
		jnz	bclcx
		add	eax, esi		;// passe � la ligne suivante
		dec	ecx
		jnz	bclcy

		ret

HClsBox		endp

;*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
;				The
				End
