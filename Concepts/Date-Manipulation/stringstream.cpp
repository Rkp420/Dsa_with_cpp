#include <iostream>
#include <sstream>

using namespace std;

string newDate(const string &date, int noOfDays)
{
    int year, mon, day;
    stringstream ss(date); // Converts Date into a string stream
    char delimeter;

    // Extracting data
    ss >> year >> delimeter >> mon >> delimeter >> day;

    int monEnd[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Handling the case of leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        monEnd[1] = 29;

    // Now add Dates
    day += noOfDays;
    while (day > monEnd[mon - 1])
    {
        day -= monEnd[mon - 1];
        mon++;

        if (mon > 12)
        {
            mon = 1;
            year++;
        }
    }

    // Now it's time to Convert new Day year month into a String
    stringstream newDate;
    newDate << year << "-" << (mon < 10 ? "0" : "") << mon << "-" << (day < 10 ? "0" : "") << day;

    return newDate.str();
}

int main()
{
    // Testing
    cout << newDate("2025-01-08", 45) << endl;

    // Checking Extraction Success :
        stringstream s("123 abc");
        int num;
        if (s >> num)
        {
            cout << "Extracted number: " << num << endl;
        }
        else
        {
            cout << "Failed to extract number!" << endl;
        }

        string data = "C++|is|powerful";
        stringstream ss(data);
        string token;

        // Read tokens
        while (getline(ss, token, '|'))
        {
            cout << "Extracted: " << token << endl;
        }

        // Rewind the stream
        ss.clear();  // Clear error flags
        ss.seekg(0); // Reset cursor to the beginning

        cout << "\nRe-reading tokens after rewind:\n";
        while (getline(ss, token, '|'))
        {
            cout << "Extracted: " << token << endl;
        }
    return 0;
}