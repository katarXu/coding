#### [变位词组](https://leetcode-cn.com/problems/sfvd7V/)

给定一个字符串数组 `strs` ，将 **变位词** 组合在一起。 可以按任意顺序返回结果列表。

**注意：**若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。



排序后哈希即可

```c++
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        groups[key].emplace_back(str);
    }
    vector<vector<string>> ret;
    for (auto it = groups.begin(); it != groups.end(); ++it) 
        ret.emplace_back(it->second);
    return ret;
}
```

#### [外星语言是否排序](https://leetcode-cn.com/problems/lwyVBB/)

某种外星语也使用英文小写字母，但可能顺序 `order` 不同。字母表的顺序（`order`）是一些小写字母的排列。

给定一组用外星语书写的单词 `words`，以及其字母表的顺序 `order`，只有当给定的单词在这种外星语中按字典序排列时，返回 `true`；否则，返回 `false`。

(用vector实现哈希表比unoreder_map占用内存少很多)

```c++
vector<int> index;

bool isLess(string &a, string& b){
    int i = 0;
    while(i < a.size() && i < b.size()){
        if(a[i] != b[i]) return index[a[i] - 'a'] <= index[b[i] - 'a'];
        i++;
    }
    return a.size() <= b.size();
}

bool isAlienSorted(vector<string>& words, string &order) {
    int i = 0;
    index.resize(26);
    for(char &ch : order)
        index[ch - 'a'] = i++;
    for(int i = 0, j = 1; j < words.size(); ++i, ++j)
        if(!isLess(words[i], words[j]))
            return false;
    return true;
}
```

#### [每日温度](https://leetcode-cn.com/problems/iIQa4I/)

请根据每日 `气温` 列表 `temperatures` ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

 

单调栈

逆序：

递减栈，找到右侧比当前元素大的递增序列

```c++
vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> res(t.size());
    stack<int> s;
    for(int i = (int)t.size() - 1; i >= 0; --i){
        while(!s.empty() && t[s.top()] <= t[i])
            s.pop();
        res[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }
    return res;
}
```

顺序：

递减栈，遇到比栈顶元素大时更新

```c++
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ret(temperatures.size(), 0);
    stack<int> sta;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
            ret[sta.top()] = i - sta.top();
            sta.pop();
        }
        sta.push(i);
    }
    return ret;
    }\
```

