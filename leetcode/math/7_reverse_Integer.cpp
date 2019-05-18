#include <iostream>
#include <sstream>
using namespace std;

int reverse(int x){
    string str,temp="";
    int flag = 0, result;
    if(x < 0){
        x = -x;
        flag = 1;
    }
    stringstream ss;
    ss << x;
    ss >> str;
    for(int i = str.length()-1; i >= 0; --i){
        temp += str[i];
    }
    if (temp.length()>= 10 && temp.compare("2147483647")>0){  //temp.compare("2147483647")>0，temp大于2147483647时返回正值
        return 0;
    }else{
        ss.clear();
        ss << temp;
        ss >> result;
        return flag == 1? -result : result;
    }
}

int main()
{
    int x;
    while(cin >> x){
        cout << reverse(x) << endl;
    }
    return 0;
}
