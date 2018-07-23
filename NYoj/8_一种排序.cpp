#include <iostream>
#include <set>
using namespace std;

struct Cuboid{
    //定义一个结构体，具有编号、长和宽3个属性
    int id;
    int length;
    int width;

    //正序输出定义的操作符
    bool operator< (const Cuboid& c) const
    {
        /*
        排序规则：1.按照编号从小到大排序
                  2.对于编号相等的长方形，按照长方形的长排序；
                  3.如果编号和长都相同，按照长方形的宽排序；
        */
        if(id < c.id)
        {
            //先判断编号，若当前编号比c对象编号小，则返回true
            return true;
        }
        //否则，若当前编号比c对象编号大，返回false
        else if(id > c.id)
        {
            return false;
        }
        //若当前编号和c对象编号相等，就需要再进一步判断长方形的长
        else
        {
            //若当前对象的长小于c对象的长，则返回true，满足<操作符
            if(length < c.length)
            {
                return true;
            }
            //否则，若当前对象的长大于c对象的长，则返回false
            else if (length > c.length)
            {
                return false;
            }
            //否则，若当前对象的长等于c对象的长，则进一步比较长方形的宽
            else
            {
                //若长方形的编号和长都相等，则比较宽的大小
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
        //set的初始化，
        for (int i = 0; i < m; i++)
        {
            cin >> cuboid.id >> tempx >> tempy;
            //如果编号、长、宽都相同，就只保留一个长方形用于排序,删除多余的长方形；
            cuboid.length = tempx > tempy ? tempx : tempy;
            cuboid.width = tempx > tempy ? tempy : tempx;
            cuboids.insert(cuboid);
        }
        //使用迭代器输出
        set<Cuboid>::iterator it;
        for(it = cuboids.begin(); it != cuboids.end(); it++)
        {
            cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;
        }

        /*
        //反序输出使用的迭代器操作
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
