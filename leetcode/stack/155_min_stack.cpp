# include <iostream>
# include <stack>
using namespace std;

/**
s1�洢����Ԫ�أ�s2�洢�����δ洢�����У����ϳ��ֵĵ�ǰ��Сֵ
*/

class MinStack{
	stack<int> s1;
	stack<int> s2;
public:
	/*MinStack(){}*/

	void push(int x){
		s1.push(x);
		// ע��s2.empty()��Ҫ����s2Ϊ�գ�������pushʲôֵ������Сֵ������x <= s2.top()ʱpush��s2
		//ע�⣺Ҫ<=����-2�� -1 ��-2���룬����s2��-2ɾ��֮������Ӧ�û���һ��-2
		if (s2.empty() || x <= s2.top()){
			s2.push(x);
		}
	}

	void pop(){
		if (s1.top() == s2.top()) s2.pop();
		s1.pop();
	}

	int top(){
		return s1.top();
	}

	int getMin(){
		return s2.top();
	}

	bool empty(){
		return s1.empty();
	}
};

int main(){
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-1);
	int value = minStack.getMin();
	cout << value << endl;
	value = minStack.top();
	cout << value << endl;
	minStack.pop();
	value = minStack.getMin();
	cout << value << endl;

	//Ԫ�����
	while (!minStack.empty()){
		value = minStack.top();
		cout << value << endl;
		minStack.pop();
	}
	return 0;
}
