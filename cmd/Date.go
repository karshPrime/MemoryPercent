
package cmd

import (
    "time"
)

const (
    Day int = iota
    Week
    Month
    Year
)

//- Helper Functions -----------------------------------------------------------

func get_time( aDate *string ) time.Time {
    var Result time.Time;

    // prarse user input - break it down into the syntax required by the
    // time library

    return Result;
}

func ask_date() string {
    var Result string;

    return Result;
}

//- External Calls -------------------------------------------------------------

func Time_Since( aBirthdate string, aOnDate string, aTimeDuration int ) float64 {
    var lBirthdate string;
    if ( aBirthdate == "" ) {
        lBirthdate = ask_date();
    } else {
        lBirthdate = aBirthdate;
    }

    // add similar logic for On Date

    lTimeStart := get_time( &lBirthdate );
    lCurrentTime := time.Now()

    lDifference := lCurrentTime.Sub(lTimeStart).Hours()

    switch (aTimeDuration) {
        case Day:
            return lDifference * 24;

        case Week:
            return lDifference * 24 * 7;

        case Month:
            // 30.4375 avg number of days in a month
            return lDifference * 24 * 7 * 30.4375;

        case Year:
            return lDifference * 24 * 7 * 365.25;
    }

    return lDifference;
}

