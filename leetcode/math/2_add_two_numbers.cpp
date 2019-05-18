#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

/*
* 构建链表
* 根据给出的vector构造一个链表，采用的是尾插法。
*/
ListNode* buildNodes(vector<int> valVec){
    ListNode* head = NULL, *tail = NULL;
    for( int i = 0; i < valVec.size(); ++i){
        //若头结点不为空，则使用尾插法插入。主要利用tail
        if(head!=NULL){
            tail->next = new ListNode(valVec[i]);
            tail = tail->next;
        }else{
            //若头结点为空，头结点应当首先有值，并将尾节点指向头结点。
            head = new ListNode(valVec[i]);
            tail = head;
        }
    }
    return head;
}

/*
* 求和，并将每个位置对应的和存放到valVec中，（注意：进位在本函数中不处理，进位是在roundVals函数中处理的）
*/
vector<int> getVals(ListNode* l1, ListNode* l2){
    vector<int> valVec;
    int sum = 0;
    //当l1和l2都为空时停止计算
    while( (l1 != NULL) || (l2 != NULL)){
            //若链表不为空，计算相应位置之和
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            //将结果存入vector
            valVec.push_back(sum);
            //清空一轮的求和结果
            sum = 0;
    }
    return valVec;
}

/*
* 本函数的作用主要是进位操作，需要注意的是最后一位数据
*/
void roundVals(vector<int> &valVec){
    //因为这段代码中涉及下标i+1的操作，所以循环只能到i < valVec.size()-1
    for(int i = 0; i < valVec.size()-1; ++i){
        if(valVec[i]>=10){
            valVec[i] -= 10;
            valVec[i+1] += 1;
        }
    }
    //若最后一位大于10的处理
    if(valVec[valVec.size()-1] >= 10){
        valVec[valVec.size()-1] -= 10;
        valVec.push_back(1);
    }
}

//调用上面的函数，求和，并返回链表
ListNode* addTwoNumbers(ListNode* l1, ListNode *l2){
    vector<int> vecVal = getVals(l1, l2);
    roundVals(vecVal);
    ListNode* result = buildNodes(vecVal);
    return result;
}


int main()
{
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,8,9};
    vector<int> valVec1(arr1, arr1+3);
    vector<int> valVec2(arr2, arr2+4);
    ListNode *p1 = buildNodes(valVec1);
    ListNode *p2 = buildNodes(valVec2);
    ListNode* result = addTwoNumbers(p1, p2);
    while(result){
        cout<< result->val << endl;
        result = result->next;
    }
    return 0;
}
