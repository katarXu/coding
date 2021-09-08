#### [生成匹配的括号](https://leetcode-cn.com/problems/IDBivT/)

正整数 `n` 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

```c++
vector<string> res;
string cur;

void dfs(int left, int right){
    if(left == 0 && right == 0){
        res.emplace_back(cur);
        return;
    }
    if(left > 0){
        cur.push_back('(');
        dfs(left - 1, right);
        cur.pop_back();
    }
    if(left < right){
        cur.push_back(')');
        dfs(left, right - 1);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    dfs(n, n);
    return res;
}
```



#### [分割回文子字符串](https://leetcode-cn.com/problems/M99OJA/)

给定一个字符串 `s` ，请将 `s` 分割成一些子串，使每个子串都是 **回文串** ，返回 s 所有可能的分割方案。

**回文串** 是正着读和反着读都一样的字符串。

```c++
void dfs(string &s, vector<vector<string>> &res, vector<string> &cur, vector<vector<bool>> &flag, int n){
    if(n == s.size()){
        res.emplace_back(cur);
        return;
    }
    for(int i = n; i < s.size(); ++i){
        if(flag[n][i]){
            cur.push_back(s.substr(n, i - n + 1));
            dfs(s, res, cur, flag, i + 1);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<bool>> flag(n, vector<bool>(n, true));
    for(int i = 1; i < n; ++i)
        for(int j = i - 1; j >= 0; --j)
            flag[j][i] = (s[i] == s[j]) && flag[j + 1][i - 1];
    dfs(s, res, cur, flag, 0);
    return res;
}
```

#### [复原 IP](https://leetcode-cn.com/problems/0on3uN/)

给定一个只包含数字的字符串 `s` ，用以表示一个 IP 地址，返回所有可能从 `s` 获得的 **有效 IP 地址** 。你可以按任何顺序返回答案。

**有效 IP 地址** 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 `0`），整数之间用 `'.'` 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 **有效** IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 **无效** IP 地址。

```c++
bool isLegal(string &s){
    return stoi(s) <= 255 && (s.size() == 1 || s[0] != '0');
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string tmp[4];
    for(int i = 0; i < 4 && i < s.size(); ++i){
        tmp[0] = s.substr(0, i + 1);
        if(!isLegal(tmp[0])) break;
        for(int j = i + 1; j < i + 5 && j < s.size(); ++j){    
            tmp[1] = s.substr(i + 1, j - i);
            if(!isLegal(tmp[1])) break;
            for(int k = max(j + 1, (int)s.size() - 5); \
                k < j + 5 && k < s.size() - 1; ++k){
                tmp[2] = s.substr(j + 1, k - j);
                tmp[3] = s.substr(k + 1);
                if(!isLegal(tmp[2]) || !isLegal(tmp[3])) continue;
                res.emplace_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
            }
        }
    }
    return res;
}
```

