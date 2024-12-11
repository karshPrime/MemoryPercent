
#include "calculations.h"

//- Helper Functions -------------------------------------------------------------------------------

double _difference_seconds ( time_t* aStartDate )
{
    time_t lToday = time( NULL );
    struct tm lTodayLocal = *localtime( &lToday );

    return difftime( lToday, *aStartDate );
}


//- Exported Functions -----------------------------------------------------------------------------

float percent_day( time_t* aStartDate )
{
    double lSecondDifference = _difference_seconds( aStartDate );

    return ( 100 * 60 * 60 * 24 ) / lSecondDifference;
}

float percent_week( time_t* aStartDate )
{
    double lSecondDifference = _difference_seconds( aStartDate );

    return ( 100 * 60 * 60 * 24 * 7 ) / lSecondDifference;
}

float percent_month( time_t* aStartDate )
{
    double lSecondDifference = _difference_seconds( aStartDate );

    return ( 100 * 60 * 60 * 24 * 30.4375 ) / lSecondDifference;
}

float percent_year( time_t* aStartDate )
{
    double lSecondDifference = _difference_seconds( aStartDate );

    return ( 100 * 60 * 60 * 24 * 365.25 ) / lSecondDifference;
}

