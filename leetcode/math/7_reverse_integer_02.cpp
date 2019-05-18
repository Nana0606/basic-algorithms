#include <iostream>
using namespace std;

#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483647

int reverse(int x){
    long long rev = 0;  //这个需要定义成long long类型的
    while ( x !=0 ){
        rev = rev * 10 + x % 10;
        x = x / 10;
        if (rev > MAX_VALUE || rev < MIN_VALUE){
            return 0;
        }
    }
    return (int)rev;
}

int main()
{
    int x;
    while(cin >> x){
        cout << reverse(x) << endl;
    }
    return 0;
}
