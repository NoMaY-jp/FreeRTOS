#include "platform.h"
#include <stdlib.h>

/* Replacement to be thread-safe (in case of other than using heap_3.c). */
void *malloc( size_t xWantedSize )
{
    return pvPortMalloc( xWantedSize );
}

/* Replacement to be thread-safe (in case of other than using heap_3.c). */
void free( void *pv )
{
    vPortFree( pv );
}

#if defined(__GNUC__)

int8_t *sbrk( size_t size );

/* Maybe not called but necessary for linking without an undefined error. */
int8_t *sbrk( size_t size )
{
    ( void ) size;
    return (int8_t *)-1;
}

#endif /* defined(__GNUC__) */

#if defined(__ICCRX__)

void main( void );

/* Never called but necessary for linking without an undefined error. */
void main( void )
{
    /* Nothing to do. */
}

#endif /* defined(__ICCRX__) */
