#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x7ffff
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	int *dp = new int[nums.size()];
	for (int i = 0; i < nums.size(); ++i)
		dp[i] = INF;
	for (int i = 0; i < nums.size(); ++i)
		*lower_bound(dp, dp + nums.size(), nums[i]) = nums[i];
	return lower_bound(dp, dp + nums.size(), INF) - dp;
}

int main() {
	vector<int> a = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS(a) << endl;
	system("pause");

}

int lengthOfLIS(vector<int>& nums) {
	int n = (int)nums.size();
	if (n == 0) {
		return 0;
	}
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}