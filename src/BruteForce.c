/*
The MIT License (MIT)

Copyright (c) 2015 Lorhan Sohaky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <BruteForce.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bruteForce( int leng, int opt, char *prog ) {
    /*
            leng use when you know the length of the password
            -1 it's use when you don't know the length of the password
            ----------------------------
            opt it's the option to
            if opt does not exists the default opt it's the 4
            opt-> 1 - Number
            opt-> 2 - Letter
            opt-> 3 - Number & Letter
            opt-> 4 - All
            ----------------------------
            if prog!=null so prog matches the name of the program to check the combination with
       password
    */
    Settings sets;
    sets.checker = NULL;
    sets.point = NULL;
    sets.length = -1;
    sets.len = false;
    sets.option = 4;

    if( leng > -1 ) {
        sets.length = leng;
        sets.len = true;
    }

    if( opt > 0 && opt < 5 ) {
        sets.option = opt;
    }
    sets.checker = prog;
    if( A( &sets ) ) {
        return sets.point;
    } else {
        free( sets.point );
        return NULL;
    }
}

bool A( Settings *sets ) {
    ( *sets ).point = (char *)malloc( ( ( ( *sets ).length ) + 1 ) * sizeof( char ) );
    if( ( *sets ).point != NULL ) {
        while( true ) {
            if( !B( sets, 0 ) ) {
                if( !( *sets ).len ) {
                    char *p = (char *)realloc( ( *sets ).point,
                                               sizeof( char ) * ( ( *sets ).length + 1 ) );
                    if( p != NULL ) {
                        ( *sets ).point = p;
                        ( *sets ).length++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                return true;
            }
        }
    }
    return false;
}

bool B( Settings *sets, int position ) {
    unsigned int imin = 0, imax = 0;
    // ASCII TABLE
    if( ( *sets ).option == 1 ) { // NUMBERS
        imin = 48;
        imax = 57;
    } else if( ( *sets ).option == 2 ) { // LETTERS
        imin = 64;
        imax = 122;
    } else if( ( *sets ).option == 3 ) { // NUMBERS AND LETTERS
        imin = 47;
        imax = 122;
    } else if( ( *sets ).option == 4 ) { // ALL
        imin = 32;
        imax = 126;
    }
    unsigned int i;

    for( i = imin; i <= imax; i++ ) {
        if( imax == 122 && i == 33 ) {
            i = imin + 1;
        } else if( imax == 122 && i == imin ) {
            i = 32;
        } else if( imin == 47 && imax == 122 && i == 58 ) {
            i = 65;
        } else if( imax == 122 && i == 91 ) {
            i = 97;
        }
        ( *sets ).point[position] = i;
        ( *sets ).point[position + 1] = '\0';
        if( strlen( ( *sets ).point ) == ( *sets ).length ) {
            if( check( ( *sets ).point, ( *sets ).checker ) ) {
                return true;
            }
        } else if( position + 1 < ( *sets ).length ) {
            if( B( sets, position + 1 ) ) {
                return true;
            }
        }
    }
    return false;
}

bool check( char *point, char *checker ) {
    if( checker != NULL ) {
        char t[strlen( checker ) + strlen( point ) + 2];
        sprintf( t, "%s %s", checker, point );
        int c = system( t );
        if( c == 1 ) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
