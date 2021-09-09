#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x7ffff
using namespace std;


int maxTurbulenceSize(vector<int>& arr) {
	int up = 1, down = 1, ans = 1;
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] > arr[i - 1]) {
			up = down + 1;
			down = 1;
		}
		else if (arr[i] < arr[i - 1]) {
			down = up + 1;
			up = 1;
		}
		else
			up = down = 1;
		ans = max(ans, max(up, down));
	}
	return ans;
}

int main() {
	vector<int> a = { 9,4,2,10,7,8,8,1,9 };
	cout << maxTurbulenceSize(a) << endl;
	system("pause");

}