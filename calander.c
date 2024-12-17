#include <stdio.h>

int main() 
{
    int month, year, daysInMonth, startDay, currentDay, i;

    // Days in each month for non-leap years
    int daysInEachMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Array of day names
    char *daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Get user input for month and year
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Check for valid month
    if (month < 1 || month > 12) 
	{
    	
        printf("Invalid month. Please enter a month between 1 and 12.\n");
        return 1;
    }

    // Leap year calculation (if February has 29 days)
    if (month == 2) 
	{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		 {
            daysInEachMonth[1] = 29;  // Set February to 29 days for leap year
        }
    }

    // Zeller's Congruence to find the starting day of the month
    int d = 1, m = month, y = year;
    if (m <= 2) 
	{
        m += 12;
        y--;
    }

    startDay = (d + (13 * (m + 1)) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    startDay = (startDay + 5) % 7;  // Adjust to make Sunday = 0, Monday = 1, etc.

    // Print the month and year
    printf("\n  %s %d\n", (month == 1) ? "January" : 
                        (month == 2) ? "February" : 
                        (month == 3) ? "March" : 
                        (month == 4) ? "April" : 
                        (month == 5) ? "May" : 
                        (month == 6) ? "June" : 
                        (month == 7) ? "July" : 
                        (month == 8) ? "August" : 
                        (month == 9) ? "September" : 
                        (month == 10) ? "October" : 
                        (month == 11) ? "November" : "December", year);
    printf("  -----------------------------\n");

    // Print day names (Sun, Mon, ..., Sat)
    for (i = 0; i < 7; i++)
	{
        printf("%s ", daysOfWeek[i]);
    }
    printf("\n");

    // Print leading spaces for the first day
    currentDay = 1;
    for (i = 0; i < startDay; i++) 
	{
        printf("    ");
    }

    // Print days of the month
    for (i = startDay; currentDay <= daysInEachMonth[month - 1]; i++) 
	{
        printf("%3d ", currentDay++);
        if (i == 6) 
		{  // End of week
            i = -1;
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}

