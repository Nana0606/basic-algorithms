#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//*****************下面是方法1：暴力枚举******************
//求距离，
//参数maxX和maxY代表输入的n个住户中最大的x坐标和最大的y坐标

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
        //初始化住户数组
        //借助二维数组，x存储所有x的值，y存储所有y的值
        cin >> m;
        int *x = new int[m];
        int *y = new int[m];
        for(int i = 0; i < m; i++)
        {
             //读入数据，并得到出现的住户中的最大的x值和y值
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

        //暴力枚举。当住户的x和y较大时，效率非常低
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
    return a < b; //升序排列，若改为a>b，则为降序排列
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
