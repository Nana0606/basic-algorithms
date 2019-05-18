#include <iostream>
#include <cstring>
using namespace std;

#define mod 1000007
#define N 3
typedef long long LL;

struct Matrix{
    LL mat[N][N];
};

Matrix unit_matrix = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};  //单位矩阵

Matrix mul(Matrix a, Matrix b){  //矩阵相乘
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for ( int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j){
            res.mat[i][j] = 0;
            for (int k = 0; k < N; ++k){
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                res.mat[i][j] = (res.mat[i][j] + mod)%mod;  //取模
            }
        }
    return res;
}

Matrix pow_matrix(Matrix a, LL n){  //矩阵快速幂
    Matrix res = unit_matrix;
    for (; n; n >>= 1){
        if(n&1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int main()
{
    Matrix x, y;
    LL T, f1, f2, a, b, c, n; //T表示测试数据的组数
    cin >> T;
    while(T--){
            cin >> f1 >> f2 >> a >> b >> c >> n;
            memset(x.mat, 0, sizeof(x.mat));
            memset(y.mat, 0, sizeof(y.mat));
            x.mat[0][0] = b;   //注意，在C++中，数组的下标从0开始，所以要特别注意
            x.mat[0][1] = a;
            x.mat[0][2] = c;
            x.mat[1][0] = 1;
            x.mat[1][1] = 0;
            x.mat[1][2] = 0;
            x.mat[2][0] = 0;
            x.mat[2][1] = 0;
            x.mat[2][2] = 1;
            y.mat[0][0] = f2;
            y.mat[1][0] = f1;
            y.mat[2][0] = 1;
            if (n == 1){
                cout << (f1+mod)%mod << endl;
            }
            else if ( n == 2){
                cout << (f2+mod)%mod << endl;
            }
            else{
                x = pow_matrix(x, n-2);
                x = mul(x, y);
                cout << (x.mat[0][0] + mod)%mod << endl;
            }
    }
    return 0;
}
