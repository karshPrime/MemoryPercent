
package main

import (
    "os"
    "github.com/karshPrime/MemoryPercentage/cmd"
)

func main() {
    lBirthDate := "";
    lOnDate := "";
    lTests := [...]bool{ false, false, false, false }

    // fix the check - upgrade with a loop to account for valid
    // varying sized input args

	if len(os.Args) > 2 {
        switch os.Args[1] {
            case "-b":
                lBirthDate = os.Args[2];

            case "-d": lTests[cmd.Day]   = true;
            case "-m": lTests[cmd.Month] = true;
            case "-w": lTests[cmd.Week]  = true;
            case "-y": lTests[cmd.Year]  = true;
        }
	}

    // add logic to call the function with appropriate variables

    cmd.Time_Since( lBirthDate, lOnDate, cmd.Day   );
    cmd.Time_Since( lBirthDate, lOnDate, cmd.Week  );
    cmd.Time_Since( lBirthDate, lOnDate, cmd.Month );
    cmd.Time_Since( lBirthDate, lOnDate, cmd.Year  );
}

