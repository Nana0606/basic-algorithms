# include <iostream>
# include <stack>
using namespace std;



class MyQueue {
	stack<int> input, output;    //ʹ��inputģ��洢�Ĺ��̣�������popʱ��Ҫ����Ӧ�ý���ouput���stack��(input�洢deque�����Ԫ�أ�output�洢��deque˳���Ԫ��)
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) { 
		input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int value = peek();
		output.pop();
		return value;
	}

	/** Get the front element. */
	int peek() {   //��Ҫ��input�е�Ԫ��ѭ������output����outputΪ�գ���output�������Ԫ�ؼ�Ϊ����
		if (output.empty()){  
			while (!input.empty()){
				output.push(input.top());
				input.pop();
			}
		}
		return output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (input.empty() && output.empty()){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(){
	MyQueue obj = MyQueue();
	obj.push(1);
	obj.push(2);
	int param_2 = obj.peek();
	cout << param_2 << endl;
	obj.push(3);
	int param_3 = obj.peek();
	cout << param_3 << endl;
	return 0;
}