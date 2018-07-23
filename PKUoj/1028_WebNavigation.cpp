#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> s1;
    s1.push("http://www.acm.org/");
    stack<string> s2;
    string command;
    string website;
    cin >> command;
    while(command != "QUIT")
    {
        /*
        注意：VISIT : Push the current page on the top of the backward stack, and make the URL specified the new current page.
              The forward stack is emptied.
        */
        if(command == "VISIT")
        {
            cin >> website;
            /*
            int position = 7;
            while ( position < website.length()-1)
            {
                //入栈，原来想的复杂了，不需要这么复杂，直接入栈，不需要通过/分割
                position = website.find("/", position+1); //找到"/"的位置。
                cout << "position = " << position << endl;
                string site = website.substr(0, position+1);
                s1.push(site);
            }
            */
            s1.push(website);
            while(!s2.empty())
            {
                s2.pop();
            }
            cout << s1.top() << endl;
        }
        else if(command == "BACK")
        {
            if(s1.size() == 1)
            {
                cout << "Ignored" << endl;
            }
            else
            {
                //注意是先push在pop，否则找不到数据，
                string temp = s1.top();
                s2.push(temp);
                s1.pop();
                cout << s1.top() << endl;
            }
        }
        else if (command == "FORWARD")
        {
            if(s2.empty())
            {
                cout << "Ignored" << endl;
            }
            else
            {
                string temp = s2.top();
                s1.push(temp);
                s2.pop();
                cout << temp << endl;
            }
        }
        cin >> command;
    }
    return 0;
}
