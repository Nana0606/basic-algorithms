#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Student{
    string name;
    int bonus;
};

//计算每个学生的获奖金额
int CalcBonus(int finalScore, int evaluatScore, char isCadre, char isWestern, int paperNum)
{
    int bonus = 0;
    if(finalScore > 80 && paperNum >= 1) bonus += 8000;
    if(finalScore > 85 && evaluatScore > 80) bonus += 4000;
    if(finalScore > 90) bonus += 2000;
    if(finalScore > 85 && isWestern == 'Y') bonus += 1000;
    if(evaluatScore > 80 && isCadre == 'Y') bonus += 850;
    return bonus;
}

int main()
{
    //N表示组数，X表示每组的人数
    int N, X;
    string name;
    int finalScore, evaluatScore, paperNum;
    char isCadre, isWestern;
    cin.sync_with_stdio(false);
    cin >> N;
    while( N-- )
    {
        cin >> X;
        string maxName;
        int maxBonus = 0, sum = 0, count = 0;
        Student s;
        Student *student = new Student[X];
        for( int i = 0; i < X; i++)
        {
            cin >> name >> finalScore >> evaluatScore >> isCadre >> isWestern >> paperNum;
            s.name = name;
            s.bonus = CalcBonus(finalScore, evaluatScore, isCadre, isWestern, paperNum);
            if(maxBonus < s.bonus)
            {
                //记录金额最大的人
                maxBonus = s.bonus;
                maxName = s.name;
            }
            //汇总金额
            sum += s.bonus;
            student[count++] = s;
        }
        /*
        for(int i = 0; i < X; i++)
        {
            cout << student[i].name << " " << student[i].bonus << endl;
        }*/
        cout << maxName << endl;
        cout << maxBonus << endl;
        cout << sum << endl;
        delete[] student;
    }
    return 0;
}
