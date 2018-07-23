#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

/*
* ��������
* ���ݸ�����vector����һ���������õ���β�巨��
*/
ListNode* buildNodes(vector<int> valVec){
    ListNode* head = NULL, *tail = NULL;
    for( int i = 0; i < valVec.size(); ++i){
        //��ͷ��㲻Ϊ�գ���ʹ��β�巨���롣��Ҫ����tail
        if(head!=NULL){
            tail->next = new ListNode(valVec[i]);
            tail = tail->next;
        }else{
            //��ͷ���Ϊ�գ�ͷ���Ӧ��������ֵ������β�ڵ�ָ��ͷ��㡣
            head = new ListNode(valVec[i]);
            tail = head;
        }
    }
    return head;
}

/*
* ��ͣ�����ÿ��λ�ö�Ӧ�ĺʹ�ŵ�valVec�У���ע�⣺��λ�ڱ������в�������λ����roundVals�����д���ģ�
*/
vector<int> getVals(ListNode* l1, ListNode* l2){
    vector<int> valVec;
    int sum = 0;
    //��l1��l2��Ϊ��ʱֹͣ����
    while( (l1 != NULL) || (l2 != NULL)){
            //������Ϊ�գ�������Ӧλ��֮��
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            //���������vector
            valVec.push_back(sum);
            //���һ�ֵ���ͽ��
            sum = 0;
    }
    return valVec;
}

/*
* ��������������Ҫ�ǽ�λ��������Ҫע��������һλ����
*/
void roundVals(vector<int> &valVec){
    //��Ϊ��δ������漰�±�i+1�Ĳ���������ѭ��ֻ�ܵ�i < valVec.size()-1
    for(int i = 0; i < valVec.size()-1; ++i){
        if(valVec[i]>=10){
            valVec[i] -= 10;
            valVec[i+1] += 1;
        }
    }
    //�����һλ����10�Ĵ���
    if(valVec[valVec.size()-1] >= 10){
        valVec[valVec.size()-1] -= 10;
        valVec.push_back(1);
    }
}

//��������ĺ�������ͣ�����������
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
