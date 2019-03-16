//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//void Encrypt (char aucPassword[], char aucResult[]){
//    for(int i = 0; i < strlen(aucPassword); i++){
//        if(aucPassword[i] >= 'a' && aucPassword[i] <= 'y'){
//            aucResult[i] = char(aucPassword[i] + 1 - 'a' + 'A');
//            cout << aucResult[i];
//        }
//        else if(aucPassword[i] == 'z'){
//            aucResult[i] = 'A';
//            cout << aucResult[i];
//        }
//        else if(aucPassword[i] >= 'A' && aucPassword[i] <= 'Y'){
//            aucResult[i] = char(aucPassword[i] + 1 - 'A' + 'a');
//            cout << aucResult[i];
//        }
//        else if(aucPassword[i] == 'Z'){
//            aucResult[i] = 'a';
//            cout << aucResult[i];
//        }
//        else if(aucPassword[i] >= '0' & aucPassword[i] <= '9' ){
//            int remain = (aucPassword[i] - '0' + 1) % 10;
//            aucResult[i] = char(remain + '0');
//            cout << aucResult[i];
//        }
//    }
//    cout << endl;
//}
//
//void unEncrypt (char result[], char password[]){
//    for(int i = 0; i < strlen(result); i ++){
//        if(result[i] >= 'b' && result[i] <= 'z'){
//            password[i] = char(result[i] - 1 - 'a' + 'A');
//            cout << password[i];
//        }
//        else if(result[i] == 'a'){
//            password[i] = 'Z';
//            cout << password[i];
//        }
//        else if(result[i] >= 'B' && result[i] <= 'Z'){
//            password[i] = char(result[i] - 1 - 'A' + 'a');
//            cout << password[i];
//        }
//        else if(result[i] == 'A'){
//            password[i] = 'z';
//            cout << password[i];
//        }
//        else if (result[i] >= '0' && result[i] <= '9'){
//            int remain = (result[i] - '0' + 9) % 10;
//            password[i] = char(remain + '0');
//            cout << password[i];
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    string data;
//    cin >> data;
//    char * aucPassword= new char[data.size() + 1];
//    char * aucResult = new char[data.size() + 1];
//    for(int i = 0; i < data.size(); i++){
//        aucPassword[i] = data[i];
//    }
//    aucPassword[data.size()] = '\0';
//    Encrypt(aucPassword, aucResult);
//    cin >> data;
//    char * result = new char[data.size() + 1];
//    char * password = new char[data.size() + 1];
//    for(int i = 0; i < data.size(); i++){
//        result[i] = data[i];
//    }
//    result[data.size()] = '\0';
//    unEncrypt(result, password);
//    return 0;
//}

/**
 * Ac: 注意最后需要while，否则会说输出为空
 */
#include <iostream>
#include <string>
using namespace std;

void Encrypt (string aucPassword){
    // cout << "aucPassword：：" << aucPassword << endl;
    string res= "";
    for(int i = 0; i < aucPassword.size(); i++){
        if(aucPassword[i] >= 'a' && aucPassword[i] <= 'y'){
            res += char(aucPassword[i] + 1 - 'a' + 'A');
        }
        else if(aucPassword[i] == 'z'){
            res += 'A';
        }
        else if(aucPassword[i] >= 'A' && aucPassword[i] <= 'Y'){
            res += char(aucPassword[i] + 1 - 'A' + 'a');
        }
        else if(aucPassword[i] == 'Z'){
            res += 'a';
        }
        else if(aucPassword[i] >= '0' & aucPassword[i] <= '9' ){
            int remain = (aucPassword[i] - '0' + 1) % 10;
            res += char(remain + '0');
        }
    }
    cout << res<< endl;
}

void unEncrypt (string result){
    //cout << " result is::" << result << endl;
    string res = "";
    for(int i = 0; i < result.size(); i ++){
        if(result[i] >= 'b' && result[i] <= 'z'){
            res += char(result[i] - 1 - 'a' + 'A');
        }
        else if(result[i] == 'a'){
            res += 'Z';
        }
        else if(result[i] >= 'B' && result[i] <= 'Z'){
            res += char(result[i] - 1 - 'A' + 'a');
        }
        else if(result[i] == 'A'){
            res += 'z';
        }
        else if (result[i] >= '0' && result[i] <= '9'){
            int remain = (result[i] - '0' + 9) % 10;
            res += char(remain + '0');
        }
    }
    cout << res << endl;
}

int main() {
    string data1, data2;
    while(cin >> data1 >> data2){
        Encrypt(data1);
        unEncrypt(data2);
    }
    return 0;
}