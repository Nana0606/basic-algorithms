# include <iostream>
using namespace std;

int a[10], book[10], n;

void dfs(int step){
	int i;
	if (step == n + 1){   //如果站在第n+1个盒子面前，说明前n个位置已经确定
		for (i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		return;    //一定要return，return之后返回最近一次调用dfs的地方
	}

	for (i = 1; i <= n; i++){   //按照1、2、3...的顺序开始尝试
		if (book[i] == 0){
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;  //将扑克牌收回
		}
	}
	return;
}

int main(){
	n = 4;
	dfs(1);
	return 0;
}