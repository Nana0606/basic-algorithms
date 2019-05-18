#include <iostream>
#include <set>
using namespace std;

struct Cuboid{
    //����һ���ṹ�壬���б�š����Ϳ�3������
    int id;
    int length;
    int width;

    //�����������Ĳ�����
    bool operator< (const Cuboid& c) const
    {
        /*
        �������1.���ձ�Ŵ�С��������
                  2.���ڱ����ȵĳ����Σ����ճ����εĳ�����
                  3.�����źͳ�����ͬ�����ճ����εĿ�����
        */
        if(id < c.id)
        {
            //���жϱ�ţ�����ǰ��ű�c������С���򷵻�true
            return true;
        }
        //��������ǰ��ű�c�����Ŵ󣬷���false
        else if(id > c.id)
        {
            return false;
        }
        //����ǰ��ź�c��������ȣ�����Ҫ�ٽ�һ���жϳ����εĳ�
        else
        {
            //����ǰ����ĳ�С��c����ĳ����򷵻�true������<������
            if(length < c.length)
            {
                return true;
            }
            //��������ǰ����ĳ�����c����ĳ����򷵻�false
            else if (length > c.length)
            {
                return false;
            }
            //��������ǰ����ĳ�����c����ĳ������һ���Ƚϳ����εĿ�
            else
            {
                //�������εı�źͳ�����ȣ���ȽϿ�Ĵ�С
                return width < c.width ? true : false;
            }
        }
    }
};


int main()
{
    int n, m, tempx, tempy;
    cin.sync_with_stdio(false);
    cin >> n;
    while(n-- )
    {
        set<Cuboid> cuboids;
        cin >> m;
        Cuboid cuboid;
        //set�ĳ�ʼ����
        for (int i = 0; i < m; i++)
        {
            cin >> cuboid.id >> tempx >> tempy;
            //�����š���������ͬ����ֻ����һ����������������,ɾ������ĳ����Σ�
            cuboid.length = tempx > tempy ? tempx : tempy;
            cuboid.width = tempx > tempy ? tempy : tempx;
            cuboids.insert(cuboid);
        }
        //ʹ�õ��������
        set<Cuboid>::iterator it;
        for(it = cuboids.begin(); it != cuboids.end(); it++)
        {
            cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;
        }

        /*
        //�������ʹ�õĵ���������
        cout << "************" << endl;
        set<Cuboid>::reverse_iterator it;
        for(it = cuboids.rbegin(); it != cuboids.rend(); it++)
        {
            cout << (*it).id <<" " << (*it).length << " " << (*it).width << endl;
        }
        */
    }
    return 0;
}
