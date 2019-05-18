# include <iostream>
# include <vector>
using namespace std;

/*
�������ļ����Ի��ǱȽ�ǿ�ġ�
1�����ѭ����������������������������ұ߽磬���ǳ����ұ߽�ȷ��֮�⣬Ϊ��������̵����������Ҫ����Ҫ������߽�
2����߽������ͨ��sum -= nums[start++];�����ƣ�����������ж���Ҫʹ��while������if����ΪҪ�������������������
3����whileѭ��������ʱ��start����Ҫ��0��ʼ��ֱ�Ӵӵ�ǰֵ��ʼ������Ϊ��0��ʼ��whileѭ���Ѿ���������˵������һ����������������i++������ж������壩
*/

int minSubArrayLen(int s, vector<int>& nums) {
	int minLen = INT_MAX;
	int start = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++){
		sum += nums[i];
		while (sum >= s){
			minLen = (minLen > (i - start + 1) ? (i - start + 1) : minLen);
			sum -= nums[start++];
		}
	}
	return minLen == INT_MAX ? 0 : minLen;
}


int main(){
	int s = 9;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int minLen = minSubArrayLen(s, nums);
	cout << minLen << endl;
	return 0;
}