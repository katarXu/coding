#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

class NumArray {
public:
	vector<int> sum;
	NumArray(vector<int>& nums) {
		int n = nums.size();
		sum.resize(n + 1);
		for (int i = 0; i < n; ++i)
			sum[i + 1] = sum[i] + nums[i];
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};
int main() {
	vector<int> ans;
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
	return 0;
}