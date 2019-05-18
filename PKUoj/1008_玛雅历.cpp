#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const static string HaabMonths[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
const static string TzolkinDayNames[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int countDays(int day, int month, int year)
{
    int days = 0;
    days += year *365;
    days += 20*(month-1) + day + 1;
    return days;
}

string TzolkinCalc(int days)
{
    int front = 0, back = 0;
    //TzolkinCalc的一年有13*20=260天
    int year = days / 260;
    int other = days % 260;
    if(other == 0 )
    {
        ostringstream os;
        os << 13;
        os << " ahau ";
        os << (year - 1);
        return os.str();
        //return 13 + " " + "ahau" + (year -1);
    }
    else
    {
        front = other % 13;
        if(front == 0) front = 13;
        back = other % 20;
        ostringstream os;
        os << front;
        os << " ";
        os << TzolkinDayNames[(back+19)%20];
        os << " ";
        os << year;
        return os.str();
        //return front + " " + TzolkinDayNames[back] + " " + year;
    }
}

int main()
{
    int n; //n为输入的样例个数
    cin >> n;
    cout << n << endl;
    while ( n-- )
    {
        string tempDay, tempMonth;
        int year;
        cin >> tempDay >> tempMonth >> year;

        int day;
        int position = tempDay.find(".");
        tempDay = tempDay.substr(0, position);
        stringstream ss;
        ss << tempDay;
        ss >> day;

        int month;
        for ( int i=0; i < 19; i++)
        {
            //月份1-19
            if(HaabMonths[i] == tempMonth)  month = i+1;
        }
        //cout << "day = " << day << ", month = " << month << ", year = " << year  << endl;
        //cout << "总天数为：" << countDays(day, month, year) << endl;
        int days = countDays(day, month, year);
        cout << TzolkinCalc(days) << endl;
    }
    return 0;
}
