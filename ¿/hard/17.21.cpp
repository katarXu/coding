#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (0 == n)
			return 0;
		vector<int> left(n), right(n);
		left[0] = height[0];
		right[n - 1] = height[n - 1];
		for (int i = 1; i < n; ++i)
			left[i] = max(left[i - 1], height[i]);
		for (int i = n - 2; i >= 0; --i)
			right[i] = max(right[i + 1], height[i]);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans += min(left[i], right[i]) - height[i];
		return ans;
	}
};

int main() {
	vector<int> ans;
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
	return 0;
}