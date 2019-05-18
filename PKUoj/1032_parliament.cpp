#include <iostream>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int i = 2;
        int sum = 0;
        int temp = 0;
        for ( i = 2; i <= N; i++)
        {
            sum += i;
            if(sum <= N && (sum+(i+1))>N)
            {
                temp = i;
                //cout << "temp = " << temp << endl;
                //cout << "sum = " << sum << endl;
                break;
            }
        }
        int other = N - sum;
        int *p = new int[temp-1];
        for ( int j = 0; j < temp -1; j++ )
        {
              p[j] = j+2;
              //cout << p[j] << " " ;
        }
        //cout << "ÄãºÃÀ²!!!" <<endl;
        for ( int k = temp-2; k >= 0; k--)
        {
            p[k] += other / (temp-1);
        }
        for ( int q = temp - 2; q >= (temp-2-(other%(temp-1))+1); q--)
        {
            p[q] += 1;
        }
        for ( int q = 0; q < temp -1; q++)
        {
            cout << p[q] << " ";
        }
        cout <<endl;
        delete[] p;
    }
    return 0;
}
