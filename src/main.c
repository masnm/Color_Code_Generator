#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/lerp.h"

int* colour_to_int_ar ( char* ch )
{
	int* ar = (int*) malloc ( sizeof(int) * 3 );
	char st[3];
	st[2] = '\0';
	for ( int i = 1, j = 0 ; i < 7 ; i += 2, ++j ) {
		st[0] = ch[i];
		st[1] = ch[i+1];
		ar[j] = strtol ( st, NULL, 16 );
	}
	return ar;
}

void int_ar_to_colour ( int* ar )
{
	printf ( "#" );
	for ( int i = 0 ; i < 3 ; ++i )
		printf ( "%02X", ar[i] );
	printf ( "\n" );
}

int main ( int argc, char** argv )
{
	if ( argc != 3 ) {
		fprintf ( stderr, "usage: %s <%s> <%s>\n", *argv, "A", "B" );
		return 0;
	}
	++argv;
	int* a = colour_to_int_ar ( *argv++ );
	int* b = colour_to_int_ar ( *argv++ );
	int* c = (int*) malloc ( sizeof(int) * 3 );

	for ( float stp = 0 ; stp <= 1.1 ; stp += 0.1 ) {
		for ( int ind = 0 ; ind < 3 ; ++ind ) {
			c[ind] = (int)roundf(lerp ( a[ind], b[ind], stp ));
		}
		int_ar_to_colour ( c );
	}

	free ( a );
	free ( b );
	free ( c );

	return 0;
}

