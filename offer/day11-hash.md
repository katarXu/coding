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



#### [最小时间差](https://leetcode-cn.com/problems/569nqc/)

给定一个 24 小时制（小时:分钟 **"HH:MM"**）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。



```c++
int findMinDifference(vector<string>& timePoints) {
    vector<bool> arr(1440);
    for(string &s : timePoints){
        int tmp = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
        if(arr[tmp]) return 0;
        arr[tmp] = true;
    }
    int first = -1, pre = -1, cur = -1, res = 1440;
    for(int i = 0; i < 1440; ++i){
        if(arr[i]){
            if(pre == -1) pre = first = cur = i;
            else{
                pre = cur;
                cur = i;
                res = min(res, cur - pre);
            }
        }
    }
    return min(res, 1440 - (cur - first));
}
```



转换时间也可以这么写：

```c++
for (auto t : timePoints)
    mins.push_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3)));
```



