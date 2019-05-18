#include <iostream>
#include<sstream>
using namespace std;

string processedData(string rowStr){
    string temp="";
    int index = 0;
    for(int i = 0; i < (int)rowStr.length()-1; ++i){
            if(((rowStr[i]=='+')||(rowStr[i]=='-'))&&((rowStr[i+1]>='0')&&(rowStr[i+1]<='9'))){
                index = i;
                break;
            }
            if(i<=((int)rowStr.length()-3)){
                if((((rowStr[i]=='+')&&(rowStr[i+1]=='-'))||((rowStr[i]=='-')&&(rowStr[i+1]=='+')))&& ((rowStr[i+2]>='0') && (rowStr[i+2]<='9'))){
                  temp = "";
                  break;
                }
            }
    }
    for (int i = index; i < (int)rowStr.length(); ++i){
            if(((rowStr[i]>='0') &&(rowStr[i]<='9')) || (rowStr[i]=='-')){
                temp += rowStr[i];
            }else if(((rowStr[i]<'0') || (rowStr[i]>'9'))&&(temp.length()>0)){
                break;
            }
    }
    return temp;
}

int myAtoi(string str) {
    string temp = processedData(str);
    stringstream ss;
    int result;
    if (temp.length()==0){
        return 0;
    }else{
        ss << temp;
        ss >> result;
        return result;
    }
}

int main()
{
    cout << myAtoi("  +  413") << endl;
    return 0;
}
