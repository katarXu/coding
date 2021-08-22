#### [插入、删除和随机访问都是 O(1) 的容器](https://leetcode-cn.com/problems/FortPu/)

设计一个支持在*平均* 时间复杂度 **O(1)** 下，执行以下操作的数据结构：

- `insert(val)`：当元素 `val` 不存在时返回 `true` ，并向集合中插入该项，否则返回 `false` 。

- `remove(val)`：当元素 `val` 存在时返回 `true` ，并从集合中移除该项，否则返回 `true` 。

- `getRandom`：随机返回现有集合中的一项。每个元素应该有 **相同的概率** 被返回。



```c++
private:
    unordered_map<int, int> numToLocation;
    vector<int> nums;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (numToLocation.count(val)) {
            return false;
        }
        numToLocation[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!numToLocation.count(val)) {
            return false;
        }    
        int location = numToLocation[val];
        numToLocation[nums.back()] = location;
        numToLocation.erase(val);
        nums[location] = nums.back();
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
```

#### [最近最少使用缓存](https://leetcode-cn.com/problems/OrIXps/)

运用所掌握的数据结构，设计和实现一个 [LRU (Least Recently Used，最近最少使用) 缓存机制](https://baike.baidu.com/item/LRU) 。

实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以正整数作为容量 `capacity` 初始化 LRU 缓存

- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。

- `void put(int key, int value)` 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。



一开始考虑用`vector<int>`实现，通过$cache[cur]$和$cur=(cur+1)%capacity$实现lru机制，但是重复调用老元素会导致需要将老元素后移，在数组中的复杂度为o(n)，故考虑使用双向链表

```c++
public:
    LRUCache(int capacity) {
        totalNum = capacity;
        curNum = 0;
        dummy = new ListNode();
        tail = dummy;
    }
    
    int get(int key) {
        if (!numToLocation.count(key)) {
            return -1;
        }
        moveToTail(key);
        return numToLocation[key]->val;
    }
    
    void put(int key, int value) {
        if (numToLocation.count(key)) {
            numToLocation[key]->val = value;
            numToLocation[key]->key = key;
            moveToTail(key);
        }
        else if (curNum < totalNum) {
            addTotail(key, value);
            curNum++;
        }
        else {
            deleteHead(key, value);
        }
    }

private:
    struct ListNode {
        int key = 0;
        int val = 0;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode(){}
        ListNode(int x, int y) : key(x), val(y) {}
    };

    int totalNum;
    int curNum;
    ListNode* dummy;
    ListNode* tail;
    unordered_map<int, ListNode*> numToLocation;

    void moveToTail(int key) {
        ListNode* node = numToLocation[key];
        if (node == tail) {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void addTotail(int key, int value) {
        ListNode* node = new ListNode(key, value);
        tail->next = node;
        node->prev = tail;
        tail = node;
        numToLocation[key] = node;
    }

    void deleteHead(int key, int value) {
        numToLocation.erase(dummy->next->key);
        dummy->next->key = key;
        dummy->next->val = value;
        numToLocation[key] = dummy->next;
        moveToTail(key);
    }
```

#### [有效的变位词](https://leetcode-cn.com/problems/dKk3P7/)

给定两个字符串 `s` 和 `t` ，编写一个函数来判断它们是不是一组变位词（字母异位词）。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同且**字符顺序不完全相同**，则称 `*s*` 和 `*t*` 互为变位词（字母异位词）。

```c++
    bool isAnagram(string s, string t) {
        if(s.size() != t.size() || s == t) return false;
        vector<int> c(26);
        for(int i = 0; i < s.size(); ++i){
            c[s[i] - 'a']++;
            c[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; ++i)
            if(c[i] != 0)
                return false;
        return true;
    }
```

