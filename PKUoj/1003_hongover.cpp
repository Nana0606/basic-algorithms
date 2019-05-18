#include <iostream>

using namespace std;

double sum(int n){
    double result = 0.00;
    for (int i = 1; i <= n; i++){
        result += 1.0/(double)(i + 1);
    }
    return result;
}

int main()
{
    double a;
    while (cin >> a){
        int i = 1;
        if(a == 0.00) break;
        while(true){
            //cout << sum(i) << endl;
            if(a <= 0.50){
                cout <<  "1 card(s)" << endl;
                break;
            }
            else{
                if(sum(i) == a){
                    cout << i << " card(s)" << endl;
                    break;
                }else if(sum(i) < a && sum(i+1) > a){
                    cout <<(i+1) << " card(s)" << endl;
                    break;
                }else{
                    i++;
                }
             }
        }
    }
    return 0;
}
