/*
			FILES (c) Adeline 1993

		Functions:

			- OpenRead
			- OpenWrite
			- OpenReadWrite
			- Read
			- Write
			- Close
			- Seek
			- Delete
			- FileSize
			- AddExt
*/

//#include <i86.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "adeline.h"
#include "lib_sys.h"


/*--------------------------------------------------------------------------*/
LONG	OpenRead( char *name )
{
#ifdef DOS
	int	handle	;

	if ( _dos_open( name, O_RDONLY, &handle ))	handle = 0	;
	return(handle)	;
#else
	return 0;
#endif


}
/*--------------------------------------------------------------------------*/
LONG	OpenWrite( char *name )
{
#ifdef DOS
	int	handle	;

	if ( _dos_creat( name, _A_NORMAL, &handle ))	handle = 0	;
	return(handle)	;
#else
	return 0;
#endif
}
/*--------------------------------------------------------------------------*/
LONG	OpenReadWrite( char *name )
{
#ifdef DOS
	int	handle	;

	if ( _dos_open( name, O_RDWR, &handle ))	handle = 0	;
	return(handle)	;
#else
	return 0;
#endif
}
/*--------------------------------------------------------------------------*/
ULONG	Read( LONG handle, void *buffer, ULONG lenread  )
{
#ifdef DOS
	ULONG	howmuch	;

	if ( lenread == 0xFFFFFFFFL )	/*	-1L	*/
		lenread = 16000000L	;/* Ca Accelere !! 	*/
	_dos_read( handle, buffer, lenread, (unsigned int *)&howmuch )	;
	return( howmuch )	;
#else
	return 0;
#endif
}
/*--------------------------------------------------------------------------*/
ULONG	Write( LONG handle, void *buffer, ULONG lenwrite )
{
#ifdef DOS
	ULONG	howmuch	;

	_dos_write( handle, buffer, lenwrite, (unsigned int *)&howmuch )	;
	return( howmuch )	;
#else
	return 0;
#endif
}
/*--------------------------------------------------------------------------*/
void	Close( LONG handle )
{
#ifdef DOS
	_dos_close( handle )	;
#else
	return ;
#endif
}
/*--------------------------------------------------------------------------*/
LONG	Seek( LONG handle, LONG position, LONG mode )
{
#ifdef DOS
	return(lseek( handle, position, mode ))	;
#else
	return 0;
#endif
}
/*--------------------------------------------------------------------------*/
LONG	Delete( char *name )
{
	if ( remove( name ))	return(0)	;
	return(1)				;
}
/*--------------------------------------------------------------------------*/
ULONG	FileSize( char *name )
{
	int	handle	;
	ULONG	fsize	;

	handle = OpenRead( name )	;
	if ( handle == 0 ) return(0)	;

	fsize = Seek( handle, 0, SEEK_END );

	Close( handle )	;
	return( fsize )	;
}
/*-------------------------------------------------------------------------*/
void	AddExt( char *path, char *ext )
{
//	Version Loran


/*
	char	*pt	;
	pt = path	;
	while(( *pt != '.' ) AND ( *pt != 0 ))	pt++	;
	*pt = 0		;
	strcat( path, ext )	;
*/


	char	drive[_MAX_DRIVE] ;
	char	dir[_MAX_DIR] ;
	char	name[_MAX_FNAME] ;
	char	oldext[_MAX_EXT] ;

	_splitpath( path, drive, dir, name, oldext ) ;

	// makepath rajoute le point si necessaire

	// oldext[0] = '.' ;
	// if (*ext == '.' ) ext++ ;
	// strcpy(oldext+1, ext);
	// _makepath( path, drive, dir, name, oldext ) ;


	_makepath( path, drive, dir, name, ext ) ;
}
/*--------------------------------------------------------------------------*/
LONG	Copy( UBYTE *sname, UBYTE *dname )
{
	ULONG	n, size ;
	LONG	shandle ;
	LONG	dhandle ;
	UBYTE	c ;

	size = FileSize((char*)sname ) ;
	if( !size )	return 0L ;

	shandle = OpenRead((char*)sname ) ;
	if( !shandle )	return 0L ;

	dhandle = OpenWrite((char*)dname ) ;
	if( !dhandle )
	{
		Close( shandle ) ;
		return 0L ;
	}

	for( n=0; n<size; n++ )
	{
		Read( shandle, &c, 1L ) ;
		if( Write( dhandle, &c, 1L ) != 1L )
		{
			Close( shandle ) ;
			Close( dhandle ) ;
			return 0L ;
		}
	}

	Close( shandle ) ;
	Close( dhandle ) ;

	return 1L ;
}
/*--------------------------------------------------------------------------*/

LONG	CopyBak( char *name )
{
	char	string[256] ;

	strcpy( string, name ) ;
	AddExt( string, ".BAK" ) ;
	return Copy((unsigned char*) name, (unsigned char*)string ) ;
}


/*--------------------------------------------------------------------------*/
