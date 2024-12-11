

// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_input.h"

//- Helper Functions -------------------------------------------------------------------------------


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

    return Result;
}

// comprehend entered date
time_t parse_input_date( char* aDate )
{
}

