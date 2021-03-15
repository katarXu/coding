[最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

给你一个整数数组 `nums` ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的子序列。



## 方法一 动态规划

$$dp[i]$$ := 以第$$i$$个数字结尾的最长递增子序列的长度

$$dp[i]=max(dp[j])+1, 0 \le j \le i, nums[j] < nums[i]$$



```c++
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
```



时间复杂度：$$O(n^2)$$

空间复杂度：$$O(n)$$



# 方法二 贪心+二分查找

$$d[i]$$ := 长度为$$i$$的最长上升子序列末尾元素的最小值

$$d[i]$$关于$$i$$单调递增，若$$d[i]\le d[j]$$且$$i > j$$ ，从长度为$$i$$的最长上升子序列的末尾删除$$i-j$$个元素，则该序列长为$$j$$，且末尾元素$$d[k]<d[i]\le d[j]$$，矛盾

```c++
int lengthOfLIS(vector<int>& nums) {
	int *d = new int[nums.size()];
	for (int i = 0; i < nums.size(); ++i)
		d[i] = INF;
	for (int i = 0; i < nums.size(); ++i)
		*lower_bound(d, d + nums.size(), nums[i]) = nums[i];
	return lower_bound(d, d + nums.size(), INF) - d;
}
```



时间复杂度：$$O(n\log n)$$

空间复杂度：$$O(n)$$