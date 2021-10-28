#include	<system\adeline.h>
#include	<system\exit.h>
#include	<system\initimer.h>
#include	<system\timerdos.h>

#include	<ail\timer.h>

#ifdef	_WIN32
#ifdef HAS_RAD_TOOLS
#include	<ail\mssw.h>
#endif
#else//	_WIN32
#include	<ail\mss.h>
#endif//_WIN32

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
VOID_FUNC	ClearAIL;

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
void	InitAIL()
{
#ifdef HAS_RAD_TOOLS
	AIL_startup()	;

	RegisterInitClear( InitAIL, ClearAIL ) ;
#else
	// TODO: Implement
#endif
}

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
void	ClearAIL()
{
#ifdef HAS_RAD_TOOLS
	AIL_shutdown()	;
#else
	// TODO: Implement
#endif
}

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
#ifndef	_WIN32

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
S32	InitTimerAIL()
{
	HTIMER  HandleTimer ;

	LockVMMTimer();
	HandleTimer = AIL_register_timer( (AILTIMERCB)NewProc08 ) ;
	if (HandleTimer == -1)
	{
		return FALSE ;
	}

	AIL_set_timer_frequency( HandleTimer, 200 ) ;
	AIL_start_timer( HandleTimer ) ;

	RegisterInitClear( (VOID_FUNC *)InitTimerAIL, NULL ) ;

	return TRUE;
}

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
#endif//_WIN32

//лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
