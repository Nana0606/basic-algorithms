# include <iostream>
# include <stack>
using namespace std;

/**
s1存储所有元素，s2存储在依次存储过程中，不断出现的当前最小值
*/

class MinStack{
	stack<int> s1;
	stack<int> s2;
public:
	/*MinStack(){}*/

	void push(int x){
		s1.push(x);
		// 注意s2.empty()主要是若s2为空，则无论push什么值都是最小值，否则当x <= s2.top()时push到s2
		//注意：要<=，如-2， -1 ，-2输入，则在s2的-2删除之后，里面应该还有一个-2
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

	//元素输出
	while (!minStack.empty()){
		value = minStack.top();
		cout << value << endl;
		minStack.pop();
	}
	return 0;
}
