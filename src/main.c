
// main.c

#include <stdio.h>

#include "datatypes.h"
#include "user_input.h"
#include "calculations.h"

int main( int argc, char* argv[] )
{
    Flags lInputSelected = parse_input_flags( argc, argv );

    if ( lInputSelected.InputDate == 0 ) fprintf ( stderr, "Please enter start date.\n" );

    time_t lBirthdate = parse_input_date( argv[lInputSelected.InputDate] );

    if ( lInputSelected.Days )    printf( "Days   = %f%%\n", percent_day( &lBirthdate ));
    if ( lInputSelected.Weeks )   printf( "Weeks  = %f%%\n", percent_week( &lBirthdate ));
    if ( lInputSelected.Months )  printf( "Months = %f%%\n", percent_month( &lBirthdate ));
    if ( lInputSelected.Years )   printf( "Years  = %f%%\n", percent_year( &lBirthdate ));

    return 0;
}

