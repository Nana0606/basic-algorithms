#include <iostream>

using namespace std;

int remainder(int n){
    int temp = n%1000007;
    int res = temp > 0 ? temp: (temp+1000007);
    return res;
}

int funDiGui(int f1, int f2, int a, int b, int c, int n){
    if(n==1){
        return remainder(f1);
    }
    else if(n==2){
        return remainder(f2);
    }
    else{
        return remainder(a*funDiGui(f1, f2, a, b, c, n-2) + b*funDiGui(f1, f2, a, b, c, n-1) + c);
    }
}

int funDiTui(int f1, int f2, int a, int b, int c, int n){
    int *p = new int[n];
    p[0] = remainder(f1);
    p[1] = remainder(f2);
    for ( int j = 2; j < n; ++j){
            p[j] = remainder(a*p[j-2] + b*p[j-1] + c);
    }
    return p[n-1];
}

int main()
{

    int T; //T表示测试数据的组数
    cin >> T;
    while(T--){
            unsigned int *p = new unsigned int[6];
            for (int i = 0; i < 6; ++i){
                cin >> p[i];
            }
           cout << funDiTui(p[0], p[1], p[2], p[3], p[4], p[5]) << endl;
    }
    return 0;
}
