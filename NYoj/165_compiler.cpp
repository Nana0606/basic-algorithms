#include <iostream>

using namespace std;

int main()
{
    int n; //n表示n个测试数据
    int m; //m表示要统计的关键字的个数
    cin >> n;
    while (n--){
        cin >> m;
        //建立并将关键词存入
        string *p = new string[m];
        for(int i = 0; i < m; ++i){
            cin >> p[i];
        }
        int count = 0;
        string temp="";
        cin>>temp;
        while(temp!="@"){
            for(int j =0; j < m; ++j){
                if(temp.compare(p[j])==0) count++;
            }
            cin >> temp;
        }
        cout << count << endl;
    }
    return 0;
}
