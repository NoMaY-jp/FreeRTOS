#include "platform.h"

void *malloc( size_t );
void free( void * );
int8_t *sbrk(size_t size);

void *malloc( size_t xWantedSize )
{
    return pvPortMalloc( xWantedSize );
}

void free( void *pv )
{
    vPortFree( pv );
}

int8_t *sbrk( size_t size )
{
    ( void ) size;
    return (int8_t *)-1;
}

#if defined(__ICCRX__)

void main( void );

/* Never called but necessary for linking without an undefined error. */
void main( void )
{
    /* Nothing to do. */
}

#endif /* defined(__ICCRX__) */
