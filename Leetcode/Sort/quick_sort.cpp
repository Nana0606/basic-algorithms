# include <iostream>;
using namespace std;

void quickSort(int arr[], int left, int right){
	int i = left, j = right;
	int temp = arr[left];
	if (i > j){
		return;
	}
	while (i < j){
		while ((arr[j] >= temp) && (i < j)){
			j--;
		}
		while ((arr[i]<=temp) && (i < j)){
			i++;
		}
		if (i < j){
			//交换arr[i]和arr[j]
			int swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
		}
	}
	// i == j,和枢纽交换位置
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}

int main(){
	int p[] = { 4, 5, 2, 9, 1, 8 };
	quickSort(p, 0, 5);
	for (int i = 0; i < sizeof(p)/sizeof(p[0]); i++){
		cout << p[i] << " ";
	}
	cout << endl;
}