//--------------------------------------------------------------------------
#ifndef	LIB_AIL_AIL
#define	LIB_AIL_AIL

//--------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------------
extern	S32		Sample_Driver_Enabled	;
extern	S32		Midi_Driver_Enabled	;
extern	S32		SamplingRate		;

//--------------------------------------------------------------------------
extern	char		MidiDriverName[]	;
extern	char		SampleDriverName[]	;

//--------------------------------------------------------------------------
#ifdef	_WIN32

//--------------------------------------------------------------------------
extern	VOID_FUNC	*PauseMidiPtr		;
extern	VOID_FUNC	*ResumeMidiPtr		;

extern	VOID_FUNC	*PauseSamplesPtr	;
extern	VOID_FUNC	*ResumeSamplesPtr	;

//--------------------------------------------------------------------------
extern	VOID_FUNC	PauseBothMiles		;

//--------------------------------------------------------------------------
extern	VOID_FUNC	ResumeBothMiles		;

// TODO: Unstub these, int is enough to get it building
#ifndef HAS_RAD_TOOLS
#define HSTREAM int
#define HTIMER int
#define HMDIDRIVER int
#define HDIGDRIVER int
#define HWAVESYNTH int
#define HSAMPLE int
#define WAVE_SYNTH int
#define HSEQUENCE int
#endif

//--------------------------------------------------------------------------
#endif//_WIN32

//--------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------
#endif//LIB_AIL_AIL

//--------------------------------------------------------------------------
