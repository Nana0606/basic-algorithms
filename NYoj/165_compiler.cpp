#include <iostream>

using namespace std;

int main()
{
    int n; //n��ʾn����������
    int m; //m��ʾҪͳ�ƵĹؼ��ֵĸ���
    cin >> n;
    while (n--){
        cin >> m;
        //���������ؼ��ʴ���
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
