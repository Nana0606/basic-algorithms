#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry = 0;//½øÎ»
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    while(l1 || l2)
    {
        int a = (l1 != NULL) ? l1->val:0;
        int b = (l2 != NULL) ? l2->val:0;
        int sum = a + b + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode* node = new ListNode(sum);
        p->next = node;
        p = node;
        if(l1)
        {
            l1 = l1->next;
        }
        if(l2)
        {
            l2 = l2->next;
        }
        cout << "ttt" << endl;
    }
    if(carry > 0)
    {
        ListNode* node = new ListNode(carry);
        p->next = node;
        p = node;
    }
    return head->next;
}

int main()
{
    ListNode *head1 = new ListNode(-1),*head2 = new ListNode(-1),*p1,*p2;
    //head->next = NULL;
    p1 = head1;
    p2 = head2;
    int a[] = {5,3};
    int b[] = {5,0};
    for(int i = 0; i < 2; ++i)
    {
        ListNode* node1 = new ListNode(a[i]);
        p1->next = node1;  //Î²²å·¨
        p1 = node1;
    }
    for(int i = 0; i < 2; ++i)
    {
        ListNode* node2 = new ListNode(b[i]);
        p2->next = node2;
        p2 = node2;
    }
    //cout << p->val << endl;
    ListNode *p = head1->next;
    ListNode *q = head2->next;
    while(p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    cout << "==========" <<endl;
    while(q)
    {
        cout << q->val << endl;
        q = q->next;
    }
    cout << "===========" << endl;
    ListNode *result = addTwoNumbers(head1->next,head2->next);
    while(result)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}


