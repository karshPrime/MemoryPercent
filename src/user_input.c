

// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_input.h"

//- Helper Functions -------------------------------------------------------------------------------

// numericalise string
int _hash_input( const char* aString )
{
    int Result = 5381;
    int lSingleChar;

    while ( ( lSingleChar = *aString++ ) )
    {
        Result = ((Result << 5) + Result) + lSingleChar;
    }

    return Result;
}


//- Exported Functions -----------------------------------------------------------------------------

// break user input arguments
Flags parse_input_flags( int aInputLen, char* aInputs[] )
{
    Flags Result = {
        .Days = true,
        .Weeks = true,
        .Months = true,
        .Years = true
    };

    for ( int i = 0; i < aInputLen; i++ )
    {
        switch ( _hash_input( aInputs[i] ) )
        {
            case 5861494:    // -d
            case 1950218832: // --days
                Result.Weeks = false;
                Result.Months = false;
                Result.Years = false;
                break;

            case 5861513:
            case -44633666:   // --weeks
                Result.Days = false;
                Result.Months = false;
                Result.Years = false;
                break;

            case 5861503:     // -w
            case -1852072712: // --months
                Result.Days = false;
                Result.Weeks = false;
                Result.Years = false;
                break;

            case 5861515:     // -y
            case -42265949:   // --years
                Result.Days = false;
                Result.Weeks = false;
                Result.Months = false;
                break;

            case 5861492:     // -b
            case -288577802:  // --birthdate
                if ( i+1 < aInputLen )
                {
                    Result.InputDate = i+1;
                }
                else
                {
                    fprintf( stderr, "Missing birthdate.\n" );
                }
        }
    }

    return Result;
}

// comprehend entered date
time_t parse_input_date( char* aDate )
{
    struct tm Result;
    memset( &Result, 0, sizeof(struct tm) );

    // Parse the date string
    if ( sscanf( aDate, "%d/%d/%d", &Result.tm_mday, &Result.tm_mon, &Result.tm_year ) != 3 )
    {
        printf( "Invalid date format. Please use dd/mm/yyyy.\n" );
        exit( EXIT_FAILURE );
    }

    Result.tm_mon  -= 1;
    Result.tm_year -= 1900;

    return mktime( &Result );
}

