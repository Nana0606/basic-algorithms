#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double* account = new double [12];
    double sum = 0.00;
    for (int i = 0; i < 12; i++)
    {
        cin >> account[i];
        sum += account[i];
    }
    cout << "$" << setiosflags(ios::fixed) << setprecision(2) << sum/12.00 << endl;
    return 0;
}
