# include <iostream>
# include <stack>
using namespace std;



class MyQueue {
	stack<int> input, output;    //使用input模拟存储的过程，但是在pop时需要逆序，应该借助ouput这个stack。(input存储deque逆序的元素，output存储和deque顺序的元素)
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
	int peek() {   //需要将input中的元素循环放入output，若output为空，在output最上面的元素即为所求
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