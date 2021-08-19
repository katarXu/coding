#### [字符串中的变位词](https://leetcode-cn.com/problems/MPnaiL/)

给定两个字符串 `s1` 和 `s2`，写一个函数来判断 `s2` 是否包含 `s1` 的某个变位词。

换句话说，第一个字符串的排列之一是第二个字符串的 **子串** 。



哈希+滑动窗口即可

```c++
bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    int i = 0, j = 0;
    bool flag = false;
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for(char &x : s1)
        map1[x]++;
    for(i = 0; i < s1.size(); ++i)
        map2[s2[i]]++;
    for(int j = 0;i <= s2.size(); ++i, ++j){
        flag = true;
        for(auto &x : map1){
            if(x.second != map2[x.first]){
                flag = false;
                break;
            }
        }
        if(flag) return true;
        i == s2.size() ? 0 : map2[s2[i]]++;
        map2[s2[j]]--;
    }
    return false;
}
```

实际上可以单哈希，貌似用数组更快

```c++
bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    bool flag = false;
    vector<int> map(26);
    for(char &x : s1)
        map[x - 'a']++;
    for(int i = 0; i < s1.size(); ++i)
        map[s2[i] - 'a']--;
    for(int i = s1.size(), j = 0;i <= s2.size(); ++i, ++j){
        flag = true;
        for(int &x : map)
            if(x != 0){
                flag = false;
                break;
            }
        if(flag) return true;
        i == s2.size() ? 0 : map[s2[i] - 'a']--;
        map[s2[j] - 'a']++;
    }
    return false;
}
```

#### [字符串中的所有变位词](https://leetcode-cn.com/problems/VabMRr/)

给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

变位词 指字母相同，但排列不同的字符串。

```c++
vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return vector<int>{};
    bool flag = false;
    vector<int> res;
    vector<int> map(26);
    for(char &x : p)
        map[x - 'a']++;
    for(int i = 0; i < p.size(); ++i)
        map[s[i] - 'a']--;
    for(int i = p.size(), j = 0;i <= s.size(); ++i, ++j){
        flag = true;
        for(int &x : map)
            if(x != 0){
                flag = false;
                break;
            }
        if(flag) res.emplace_back(j);
        i == s.size() ? 0 : map[s[i] - 'a']--;
        map[s[j] - 'a']++;
    }
    return res;
}
```

#### [不含重复字符的最长子字符串](https://leetcode-cn.com/problems/wtcaE1/)

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长连续子字符串** 的长度。

```c++
int lengthOfLongestSubstring(string s) {
	int res = 0;
	vector<bool> map(128);
	for (int i = 0, j = 0; i < s.size(); ++i) {
		if (map[s[i]]) {
			while (s[j] != s[i])
				map[s[j++]] = false;
			j++;
		}
		else map[s[i]] = true;
		res = max(res, i - j + 1);
	}
	return res;
}
```

