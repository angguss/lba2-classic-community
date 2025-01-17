/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*

	栩栩栩� 栩� 栩� 栩栩栩� 栩栩栩� 栩� 栩� 栩栩栩�         栩� 栩�
	青栩敖� 栩杰栩� 青栩敖� 栩敖陳� 栩� 栩� 青栩敖�         栩� 栩�
	  栩�   栩栩栩�   栩�   栩栩杰  拙栩框�   栩�           栩栩栩�
	  栩�   栩无栩�   栩�   栩敖潰  栩敖栩�   栩�           栩敖栩�
	栩栩栩� 栩垣栩�   栩�   栩栩栩� 栩� 栩�   栩�     栩�   栩� 栩�
	青陳陳� 青� 青�   青�   青陳陳� 青� 青�   青�     青�   青� 青�

	Module commun aux mondes interieurs et exterieurs encapsulant
	certaines fonctions.

 *様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/

extern	S32	SaveVueOffsetX, SaveVueOffsetY, SaveVueOffsetZ ;
extern	S32	SaveAlphaCam, SaveBetaCam, SaveGammaCam ;
extern	S32	SaveVueDistance ;

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Game
extern	void	PtrInit3DGame() ;

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Objects
/*--------------------------------------------------------------------------*/
extern	S32	DrawRecover( S32 xw, S32 yw, S32 zw, S32 ymax, S32 zvmax ) ;

/*--------------------------------------------------------------------------*/
extern	void	DrawRecover3( S32 xw, S32 yw, S32 zw, S32 ymax, S32 zvmax ) ;

/*--------------------------------------------------------------------------*/

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Map
extern	void	RefreshGrille() ;
/*--------------------------------------------------------------------------*/
extern	U8	PtrWorldCodeBrick( S32 xw, S32 yw, S32 zw ) ;

/*--------------------------------------------------------------------------*/

#ifdef	LBA_EDITOR
extern	void	RefreshClippedGrille() ;
extern	void	PtrSearchFirstPseudo() ;
extern	S32	PtrGetScreenBrick( S32 xp, S32 yp ) ;
#endif

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Graph
/*--------------------------------------------------------------------------*/
extern	void	PtrProjectSprite( S32 xw, S32 yw, S32 zw, S32 sprite ) ;

/*--------------------------------------------------------------------------*/
extern	void	PtrGetDxDyGraph( S32 sprite, S32 *dx, S32 *dy ) ;

/*--------------------------------------------------------------------------*/
extern	void	PtrAffGraph( S32 xp, S32 yp, S32 sprite ) ;

/*--------------------------------------------------------------------------*/
extern	U8	*GetPtrSprite( S32 sprite ) ;

/*--------------------------------------------------------------------------*/

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// World
/*--------------------------------------------------------------------------*/
extern	S32	PtrProjectPoint( S32 xw, S32 yw, S32 zw ) ;

/*--------------------------------------------------------------------------*/
extern	void	CameraCenter( S32 flagbeta ) ;

/*--------------------------------------------------------------------------*/
extern	void	FlyCamera( 	S32 offx, S32 offy, S32 offz,
				S32 alpha, S32 beta, S32 gamma, S32 distance,
				S32 delay ) ;
/*--------------------------------------------------------------------------*/
extern	void	SaveCamera() ;
/*--------------------------------------------------------------------------*/
extern	void	RestoreCamera() ;
/*--------------------------------------------------------------------------*/
extern	S32	PtrCalculAltitudeY( S32 x, S32 z ) ;

/*--------------------------------------------------------------------------*/

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Tools (PERSO)
#ifdef	LBA_EDITOR
extern	void	GereBrickMouse() ;
extern	S32	PtrGereKeys( U32 key, U32 flagmenu ) ;
#endif

/*陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳*/
// Pointeurs de fonctions communs au deux mondes et initialis�s par PtrInit3DGame
//			(voir PTRFUNC.H)
/*--------------------------------------------------------------------------*/

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_ReajustPos	*PtrReajustPos ;

#pragma	aux	PtrReajustPos	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_GetShadow	*PtrGetShadow ;

#pragma	aux	PtrGetShadow	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_DoAnim	*PtrDoAnim ;

#pragma	aux	PtrDoAnim	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_WorldColBrick	*PtrWorldColBrick ;

#pragma	aux	PtrWorldColBrick	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_WorldColBrickVisible	*PtrWorldColBrickVisible ;

#pragma	aux	PtrWorldColBrickVisible	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_ProjectShadow	*PtrProjectShadow ;

#pragma	aux	PtrFunc_ProjectShadow	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_ReajustPosExtra	*PtrReajustPosExtra ;

#pragma	aux	PtrReajustPosExtra	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_Init3DView	*PtrInit3DView ;

#pragma	aux	PtrInit3DView	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
extern	Func_InitGrille	*PtrInitGrille ;

#pragma	aux	PtrInitGrille	"*"

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�
#ifndef	LBA_EDITOR
extern	Func_FullWorldColBrick	*PtrFullWorldColBrick ;

#pragma	aux	PtrFullWorldColBrick	"*"
#endif	// LBA_EDITOR

//烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝烝�

/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様*/
