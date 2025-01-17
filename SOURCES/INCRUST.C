#include	"c_extern.h"

/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*
     �    栩� � 桎烝� 桎烝� �   � 栩烝� 烝桎�       桎烝�  �    栩烝� 桎烝�
     栩   栩炳� 栩    栩炳� 栩  � 烝烝�   栩        栩  �  栩   烝烝� 栩烝�
     烝   烝  � 烝烝� 烝  � 烝烝� 烝烝�   烝  烝烝� 烝烝   烝   烝烝� 烝
 *様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/
/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/

void	InitIncrustDisp(	WORD type,
				WORD num,
				WORD x, WORD y,
				WORD info,
				WORD move,
				WORD timeout	)
{
	T_INCRUST_DISP	*ptrdisp ;
	WORD	n ;

	ptrdisp = ListIncrustDisp ;

	for( n=0; n<MAX_INCRUST_DISP; n++, ptrdisp++ )
	{
		if( ptrdisp->Num == -1 )	/* slot libre */
		{
			ptrdisp->Num = num ;

			ptrdisp->X = x ;
			ptrdisp->Y = y ;

			ptrdisp->Type = type ;
			ptrdisp->Info = info ;

			ptrdisp->Move = move ;

			ptrdisp->TimerEnd = TimerRef + 50 * timeout ;

			return ;
		}
	}
}

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/

void	ChangeIncrustPos( WORD xp0, WORD yp0, WORD xp1, WORD yp1 )
{
	T_INCRUST_DISP	*ptrdisp ;
	WORD	n ;
	WORD	dx, dy ;

        dx = xp1 - xp0 ;
	dy = yp1 - yp0 ;

	ptrdisp = ListIncrustDisp ;

	for( n=0; n<MAX_INCRUST_DISP; n++, ptrdisp++ )
	{
		if( ptrdisp->Type == INCRUST_NUM )
		{
			ptrdisp->X += dx ;
			ptrdisp->Y += dy ;
		}
	}
}

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/

WORD	LastNumBulle = -1 ;
WORD	SpriteBulle = 91 ;

void	DrawBulle( WORD numobj )
{
	LONG	dx, dy ;

	ProjettePoint(	ListObjet[numobj].PosObjX - WorldXCube,
			ListObjet[numobj].PosObjY + ListObjet[numobj].Ymax - WorldYCube,
			ListObjet[numobj].PosObjZ - WorldZCube ) ;

	if( LastNumBulle != numobj )
	{
		SpriteBulle ^= 1 ;
		LastNumBulle = numobj ;
	}

	GetDxDyGraph( 0, &dx, &dy, HQR_Get(HQRPtrSpriteExtra, SpriteBulle ) ) ;

	if( SpriteBulle == 90 )	ScreenXmin = Xp + 10 ;
	else			ScreenXmin = Xp - 10 - dx ;

	ScreenYmin = Yp - 20 ;


	ScreenXmax = ScreenXmin + dx -1 ;
	ScreenYmax = ScreenYmin + dy -1 ;

	SetClip( ScreenXmin, ScreenYmin, ScreenXmax, ScreenYmax ) ;

	AffGraph( 0, ScreenXmin, ScreenYmin, HQR_Get(HQRPtrSpriteExtra, SpriteBulle) ) ;
	if( ClipXmin <= ClipXmax
	AND ClipYmin <= ClipYmax )
	{
		CopyBlockPhys( ClipXmin, ClipYmin, ClipXmax, ClipYmax ) ;
	}

	UnSetClip() ;
}

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
