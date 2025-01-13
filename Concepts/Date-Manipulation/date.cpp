#include <iostream>
#include <ctime> // Library Used in Date Manipulation
#include <locale.h>
using namespace std;

int main()
{
    /** Get The Current Time */

    time_t now = time(0); // Gives the Current Time in Seconds
    // cout << now << endl; // Since 1970-01-01

    tm *ltm = localtime(&now); // Make Sure You Pass the address of the now;
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;

    /** Adding Days */
    tm *date = localtime(&now);
    cout << "Current Date: " << endl;
    cout << 1900 + date->tm_year << "-" << 1 + date->tm_mon << "-" << date->tm_mday << endl;

    int days = 45;

    date->tm_mday += days;
    date->tm_mon += 12;

    // Normalise the date(if after adding days it's get overflowed);
    time_t future = mktime(date);
    date = localtime(&future);

    cout << "After " << days << " The Date: "<< endl;
    cout << 1900 + date->tm_year << "-" << 1 + date->tm_mon << "-" << date->tm_mday << endl;

    /** Calculate Difference Between Dates */
    tm date1 = {0}, date2 = {0};

    // Changing Dates
    date1.tm_year = 2025-1900;
    date1.tm_mon = 0; // Indicates January
    date1.tm_mday = 9;

    date2.tm_year = 2025 - 1900;
    date2.tm_mon = 4;
    date2.tm_mday = 10;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    double diff = difftime(time2, time1)/ (60 * 60 * 24);
    cout << "difference in days: " << diff << endl;

    /** Formatting Days */ 
    time_t currtime = time(0);

    tm *currLocalTime = localtime(&currtime);

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", currLocalTime); // Function Used to Format the Date

    cout << "Formatted Date : " << buffer << endl;
    tm *localTime = localtime(&now);

    // Create a French locale
    locale_t frenchLocale = newlocale(LC_TIME, "fr_FR.utf8", NULL);

    // Buffer to store the formatted date
    char buffer2[80];

    // Format the date in French locale
    strftime_l(buffer2, 80, "%A, %d %B %Y", localTime, frenchLocale);

    // Print the formatted date
    cout << "Formatted Date (French): " << buffer2 << endl;

    // Free the locale
    freelocale(frenchLocale);
    return 0;
}