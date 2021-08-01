#### [分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)

给你一个字符串 `s`，请你将 `s` 分割成一些子串，使每个子串都是回文。

返回符合要求的 **最少分割次数** 。

 

## 动态规划

$dp[i]$ := $s[0...i]$的最少分割次数

有$dp[i]=min_{0\le j \lt i}dp[j]+1$，其中满足$s[j+1...i]$为回文串

故需要预处理$s$，求出回文串的位置



$dp1[i][j]$ := $s[i...j]$是否是回文串

$dp1[i][j]=dp[i+1][j-1]\and s[i]==s[j]$



```c++
int minCut(string s) {
	int n = (int)s.size();
	vector<vector<bool>> dp1(n, vector<bool>(n, true));
	vector<int> dp(n, INT_MAX);
	for (int i = n - 1; i >= 0; --i) 
		for (int j = i + 1; j < n; ++j) 
			dp1[i][j] = dp1[i + 1][j - 1] && s[i] == s[j];

	for (int i = 0; i < n; ++i) {
		if (dp1[0][i]) {
			dp[i] = 0;
			continue;
		}
		for (int j = 0; j < i; ++j) {
			if (dp1[j + 1][i])
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[n - 1];
}
```

