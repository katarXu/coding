#### [含有所有字符的最短字符串](https://leetcode-cn.com/problems/M1oyTv/)

给定两个字符串 `s` 和 `t` 。返回 `s` 中包含 `t` 的所有字符的最短子字符串。如果 `s` 中不存在符合条件的子字符串，则返回空字符串 `""` 。

如果 `s` 中存在多个符合条件的子字符串，返回任意一个。

**注意：** 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。



哈希+滑动窗口

```c++
string minWindow(string s, string t) {
	if (t.size() > s.size()) return string("");
	bool flag = false;
	int left = -1, right = s.size();
	vector<int> map(128);
	for (char &x : t)
		map[x]++;
	for (int i = 0; i < t.size(); ++i)
		map[s[i]]--;
	for (int i = t.size(), j = 0; i <= s.size(); ++i) {
		flag = true;
		for (int &x : map)
			if (x > 0) {
				flag = false;
				break;
			}
		if (flag) {
			while (map[s[j]] < 0)
				map[s[j++]]++;
			if (i - j < right - left) {
				right = i;
				left = j;
			}
			do {
				map[s[j++]]++;
			} while (map[s[j]] < 0);
		}
		i == s.size() ? 0 : map[s[i]]--;
	}
	return left == -1 ? string("") : s.substr(left, right - left);
}
```

#### [有效的回文](https://leetcode-cn.com/problems/XltzEq/)

给定一个字符串 `s` ，验证 `s` 是否是 **回文串** ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 **回文串** 。

几个函数(iostream 或 type.c)

> isalpha ：判断一个字符是否为字母，如果是则返回true，否则返回false；
> isdigit : 判断一个字符是否表示数字，如果是则返回true，否则返回false；
> isalnum : 判断一个字符是否表示数字或者字母，如果是则返回true，否则返回false;
> islower : 判断一个字符是否为小写字母，如果是则返回true，否则返回false;
> isupper : 判断一个字符是否为大写字母，如果是则返回true，否则返回false；
> tolower : 若字符为字母则转化为小写字母；
> toupper : 若字符为字母则转化为大写字母；



双指针

```c++
bool isPalindrome(string s) {
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (!isalnum(s[i])) 
			i++;
		else if (!isalnum(s[j])) 
			j--;
		else {
			if (tolower(s[i]) != tolower(s[j])) 
				return false;
			else 
				i++, j--;
		}
	}
	return true;
}
```

#### [最多删除一个字符得到回文](https://leetcode-cn.com/problems/RQku0D/)

给定一个非空字符串 `s`，请判断如果 **最多** 从字符串中删除一个字符能否得到一个回文字符串。

```c++
bool isPal(string &s, int i, int j){
    while(i < j)
        if(s[i++] != s[j--]) return false;
    return true;
}
bool validPalindrome(string &s) {
    int i = 0, j = s.size() - 1;
    while(i < j)
        if(s[i] != s[j])
            return isPal(s, i, j - 1) || isPal(s, i + 1, j);
        else
            i++, j--;
    return true;
}
```

#### [回文子字符串的个数](https://leetcode-cn.com/problems/a7VOhD/)

给定一个字符串 `s` ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。



dp

$dp[i][j] = (s[i] == s[j]) \and dp[i + 1][j - 1]$

```c++
int countSubstrings(string &s) {
    int n = s.size();
    int res = n;
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for(int j = 1; j < n; ++j){
        for(int i = j - 1; i >= 0; --i){
            dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            if(dp[i][j]) res++;
        }
    }
    return res;
}
```

中心扩展

选取中心点然后两边遍历即可

```c++
int countSubstrings(string &s) {
    int n = s.size();
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += cntPal(s, i, i) + cntPal(s, i, i + 1);
    return res;
}
int cntPal(string &s, int i, int j){
    int cnt = 0;
    while(i >= 0 && j < s.size()){
        if(s[i--] == s[j++]) ++cnt;
        else break;
    }
    return cnt;
}
```

