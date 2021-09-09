#include<iostream>
#include<unordered_map>
#include<vector>

#define INF (0x7fffff)

using namespace std;



int reverse(int x) {
	int ans = 0;
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && pop > 7) return 0;
		if (ans < -INT_MAX / 10 || ans == -INT_MAX / 10 && pop < -8) return 0;
		ans = ans * 10 + pop;
	}
	return ans;
}

int main() {
	cout << reverse(1534236469) << endl;
	system("pause");
}
