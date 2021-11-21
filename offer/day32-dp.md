#### [最少回文分割](https://leetcode-cn.com/problems/omKAoA/)

给定一个字符串 `s`，请将 `s` 分割成一些子串，使每个子串都是回文串。

返回符合要求的 **最少分割次数** 。

```c++
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> flag(n, vector<bool>(n, true));
    vector<int> res(n);
    for(int i = n - 2; i >= 0; --i){
        for(int j = i + 1; j < n; ++j){
            flag[i][j] = (s[i] == s[j]) && flag[i + 1][j - 1];
        }
    }
    for(int i = 0; i < n; ++i){
        if(flag[0][i]){
            res[i] = 0;
        }
        else{
            res[i] = i;
            for(int j = 1; j <= i; ++j){
                if(flag[j][i]){
                    res[i] = min(res[i], res[j - 1] + 1);
                }
            }
        }
    }
    return res[n - 1];
}
```

#### [最长公共子序列](https://leetcode-cn.com/problems/qJnOS7/)

```c++
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(text1[i] == text2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[n][m];
}
```

### optimal

```c++
int longestCommonSubsequence(string &text1, string &text2) {
    int n = text1.size();
    int m = text2.size();
    if(n < m){
        return longestCommonSubsequence(text2, text1);
    }
    vector<int> dp(m + 1, 0);
    for(int i = 0; i < n; ++i){
        int tmp1 = 0;
        int tmp2 = 0;
        for(int j = 0; j < m; ++j){
            tmp2 = dp[j + 1];
            if(text1[i] == text2[j]){
                dp[j + 1] = tmp1 + 1;
            }
            else{
                dp[j + 1] = max(dp[j + 1], dp[j]);
            }
            tmp1 = tmp2;
        }
    }
    return dp[m];
}
```

