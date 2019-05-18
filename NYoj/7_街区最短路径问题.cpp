#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//*****************�����Ƿ���1������ö��******************
//����룬
//����maxX��maxY���������n��ס��������x���������y����

/*
int distance(int selectedX, int selectedY, int *x, int *y, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = sum + fabs(selectedX - x[i]) + fabs(selectedY - y[i]);
    }
    return sum;
}


int main()
{
    int n, m;
    int maxX = 0, maxY = 0;
    cin.sync_with_stdio(false);
    cin >> n;
    while((n--)>0)
    {
        //��ʼ��ס������
        //������ά���飬x�洢����x��ֵ��y�洢����y��ֵ
        cin >> m;
        int *x = new int[m];
        int *y = new int[m];
        for(int i = 0; i < m; i++)
        {
             //�������ݣ����õ����ֵ�ס���е�����xֵ��yֵ
            cin >> x[i] >> y[i];
            if(maxX < x[i])
            {
                maxX = x[i];
            }
            if(maxY < y[i])
            {
                maxY = y[i];
            }
        }

        int sum = 1e9;

        //����ö�١���ס����x��y�ϴ�ʱ��Ч�ʷǳ���
        for(int i = 1; i <= maxX; i++)
        {
            for (int j = 1; j <= maxY; j++)
            {
                int temp = distance(i, j, x, y, m);
                if(temp <= sum)
                {
                    sum = temp;
                }
            }
        }
        cout << sum << endl;
        delete []x;
        delete []y;
    }
    return 0;
}*/



bool compare(int a, int b)
{
    return a < b; //�������У�����Ϊa>b����Ϊ��������
}

int main()
{
    int n, m;
    cin >> n;
    while( n-- )
    {
        cin >> m;
        int *x = new int[m];
        int *y = new int[m];
        for (int i = 0;i < m; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x, x+m, compare);
        sort(y, y+m, compare);
        int sum = 0;
        for (int i = 0; i < m/2; i++)
        {
            sum = sum + (x[m-i-1] - x[i]) + (y[m-i-1] - y[i]);
        }
        cout << sum << endl;
        delete []x;
        delete []y;
    }
}
