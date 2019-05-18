#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

int main()
{
    int N; //N表示共有N组数据
    cin >> N;
    //cout << "N = " << N << endl;
    for (int i =0; i<N; i++)
    {
        double X;
        double Y;
        cin >> X >> Y;
        double area =  PI * (X*X + Y*Y)/2.00;
        cout << "Property " << i+1 << ": This property will begin eroding in year " << (int)(area/(double)50+1) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
