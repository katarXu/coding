#### [二叉搜索树中两个节点之和](https://leetcode-cn.com/problems/opLdQZ/)

给定一个二叉搜索树的 **根节点** `root` 和一个整数 `k` , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 `k` 。假设二叉搜索树中节点的值均唯一。

### 哈希

```c++
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> aset;
    stack<TreeNode*> astack;
    TreeNode *cur = root;
    while(cur != nullptr || !astack.empty()){
        while(cur != nullptr){
            astack.emplace(cur);
            cur = cur->left;
        }
        cur = astack.top();
        astack.pop();
        if(aset.count(k - cur->val)) return true;
        aset.insert(cur->val);
        cur = cur->right;
    }
    return false;
}
```

### 中序遍历

通过中序遍历把树转换为有序数组

见[二叉搜索树迭代器](https://leetcode-cn.com/problems/kTOapQ/)



#### [值和下标之差都在给定的范围内](https://leetcode-cn.com/problems/7WqeDu/)

给你一个整数数组 `nums` 和两个整数 `k` 和 `t` 。请你判断是否存在 **两个不同下标** `i` 和 `j`，使得 `abs(nums[i] - nums[j]) <= t` ，同时又满足 `abs(i - j) <= k` 。

如果存在则返回 `true`，不存在返回 `false`。

 

显然有暴力方法，时间复杂度是o(nk)，主要问题出在后面的k上，因此思考能否优化到logk，这个过程是在后续k个元素中找到存在$[nums[i] - t, nums[i] + t]$间的元素，故可以用二叉搜索树，在c++里有set和map来实现，本题不会出现重复情况，采用set

```c++
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	set<int> st;
	for (int i = 0; i < nums.size(); ++i) {
		int lowerLimit = max(nums[i], INT_MIN + t) - t;
		int upperLimit = min(nums[i], INT_MAX - t) + t;
		auto it = st.lower_bound(lowerLimit);
		if (it != st.end() && *it <= upperLimit)
			return true;
		st.insert(nums[i]);
		if (i >= k)
			st.erase(nums[i - k]);
	}
	return false;
}
```

#### [日程表](https://leetcode-cn.com/problems/fi9suh/)

请实现一个 `MyCalendar` 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。

`MyCalendar` 有一个 `book(int start, int end)`方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 `[start, end)`, 实数 `x` 的范围为，  `start <= x < end`。

当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。

每次调用 `MyCalendar.book`方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 `true`。否则，返回 `false` 并且不要将该日程安排添加到日历中。

```c++
class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = events.lower_bound(start);
        if (it != events.end() && it->first < end)
            return false;
        if (it != events.begin() && (--it)->second > start) 
            return false;
        events[start] = end;
        return true;
    }
};
```

