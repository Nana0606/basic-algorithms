#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {

    //若.和*都不在p中，则完全匹配
    if( (p.find(".")==string::npos) && (p.find("*")==string::npos)){
        cout << "jinrr" << endl;
        return s.compare(p) == 0 ? true : false;
    }else{

    }
    return false;
}

int main()
{
    string s = "aaab", p = "aaab";
    cout << isMatch(s, p) << endl;
    return 0;
}
