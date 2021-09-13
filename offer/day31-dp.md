#### [粉刷房子](https://leetcode-cn.com/problems/JEj789/)

假如有一排房子，共 `n` 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 `n x 3` 的正整数矩阵`costs`来表示的。

例如，`costs[0][0]` 表示第 0 号房子粉刷成红色的成本花费；`costs[1][2]` 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。

```c++
int minCost(vector<vector<int>>& costs) {
    int dp0 = 0, dp1 = 0, dp2 = 0;
    for(int i = 0; i < costs.size(); ++i){
        tie(dp0, dp1, dp2) = tuple<int, int, int>{
            min(dp1, dp2) + costs[i][0],
            min(dp0, dp2) + costs[i][1],
            min(dp0, dp1) + costs[i][2]
        };
    }
    return min(min(dp0, dp1), dp2);
}
```

#### [翻转字符](https://leetcode-cn.com/problems/cyJERH/)

如果一个由 `'0'` 和 `'1'` 组成的字符串，是以一些 `'0'`（可能没有 `'0'`）后面跟着一些 `'1'`（也可能没有 `'1'`）的形式组成的，那么该字符串是 **单调递增** 的。

我们给出一个由字符 `'0'` 和 `'1'` 组成的字符串 s，我们可以将任何 `'0'` 翻转为 `'1'` 或者将 `'1'` 翻转为 `'0'`。

返回使 s **单调递增** 的最小翻转次数。



#### 统计左侧的1和右侧的0

 ```c++
int minFlipsMonoIncr(string s) {
    int n = s.size();
    int res = INT_MAX;
    vector<int> a(n), b(n);
    for(int i = 1; i < n; ++i)
        a[i] = a[i - 1] + (s[i - 1] == '1');
    for(int i = n - 2; i >= 0; --i)
        b[i] = b[i + 1] + (s[i + 1] == '0');
    for(int i = 0; i < n; ++i)
        res = min(res, a[i] + b[i]);
    return res;
}
 ```

#### dp

按照最右是0还是1来dp

```c++
int minFlipsMonoIncr(string s) {
    int dp0 = 0, dp1 = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '0'){
            dp1 = min(dp0, dp1) + 1;
        }
        else{
            dp1 = min(dp0, dp1);
            dp0++;
        }
    }
    return min(dp0, dp1);
}
```

最长上升序列

```c++
int minFlipsMonoIncr(string s) {
    int pos = 0, len = 0; //pos是1应该插入的位置，len是序列长度
    for(char &c : s){
        if(c == '0'){
            if(pos == len)
                len++;
            pos++;
        }
        else
            len++;
    }
    return s.size() - len;
}
```

#### [最长斐波那契数列](https://leetcode-cn.com/problems/Q91FMA/)

给定一个**严格递增**的正整数数组形成序列 `arr` ，找到 `arr` 中最长的斐波那契式的子序列的长度。如果一个不存在，返回 0 。

```c++
int lenLongestFibSubseq(vector<int>& arr) {
	vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
	unordered_map<int, int> mp;
	for (int i = 0; i < arr.size(); ++i) {
		mp[arr[i]] = i;
	}

	int ret = 0;
	for (int i = 1; i < arr.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			int temp = arr[i] - arr[j];
			// 存在 k 使得 A[i] = A[j] + A[k] (0 <= k < j < i)
			if (mp.count(temp) && mp[temp] < j) {
				dp[i][j] = dp[j][mp[temp]] + 1;
			}
			// 不存在 k 使得 A[i] = A[j] + A[k] (0 <= k < j < i)
			else {
				dp[i][j] = 2;
			}
			ret = max(ret, dp[i][j]);
		}
	}

	return ret > 2 ? ret : 0;
}
```

