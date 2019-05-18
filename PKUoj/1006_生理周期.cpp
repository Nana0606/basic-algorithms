#include <iostream>
using namespace std;


/*
注意考虑特殊用例：
> //注意特殊测试数据
> //24 29 34 0           1
> //24 29 34 1           21252
> //24 29 34 2           21251
> //0  0  0  0           21252
*/

int main()
{
    int p, e, i, d;
    int count = 1;
    cin >> p >> e >> i >> d;
    while((p != -1)&&(e != -1)&&(i != -1)&&(d != -1))
    {
        int x = 0;
        for (x = 1; x <= 21252; x++)
        {
            if (((x-p)%23 == 0)&&((x-e)%28 == 0)&&((x-i)%33 == 0))
            {
                int result = x-d;
                if (result <= 0) result += 21252;
                cout << "Case " << count << ": the next triple peak occurs in " << result << " days."<<endl;
            }
        }
        count++;
        cin >> p >> e >> i >> d;
    }
    return 0;
}
