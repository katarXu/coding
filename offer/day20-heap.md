#### [数据流的第 K 大数值](https://leetcode-cn.com/problems/jBjn9C/)

设计一个找到数据流中第 `k` 大元素的类（class）。注意是排序后的第 `k` 大元素，不是第 `k` 个不同的元素。

请实现 `KthLargest` 类：

- `KthLargest(int k, int[] nums)` 使用整数 `k` 和整数流 `nums` 初始化对象。

- `int add(int val)` 将 `val` 插入数据流 `nums` 后，返回当前数据流中第 `k` 大的元素。



 ### top k 问题

- `priority_queue`中的comp\<type\>参数是返回值为true时继续向下查找结点

```c++
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int &x : nums)
            add(x);
    }
    
    int add(int val) {
        if(q.size() < k)
            q.emplace(val);    
        else if(val > q.top()){
            q.pop();
            q.emplace(val);
        }
        return q.top();
    }
};
```

#### [出现频率最高的 k 个数字](https://leetcode-cn.com/problems/g5c51o/)

给定一个整数数组 `nums` 和一个整数 `k` ，请返回其中出现频率前 `k` 高的元素。可以按 **任意顺序** 返回答案。

```c++
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> mp;
	vector<int> res(k);
	typedef pair<int, int> pi;
	struct cmp {
		bool operator()(const pi &a, const pi &b) { return a.second > b.second; }
	};
	priority_queue <pi, vector<pi>, cmp> q;
	for (int &x : nums) mp.count(x) ? mp[x]++ : mp[x] = 1;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (q.size() < k)
			q.emplace(make_pair(it->first, it->second));
		else if (it->second > q.top().second) {
			q.pop();
			q.emplace(make_pair(it->first, it->second));
		}
	}
	for (int i = 0; i < k; ++i) {
		res[i] = q.top().first;
		q.pop();
	}
	return res;
}
```

#### [和最小的 k 个数对](https://leetcode-cn.com/problems/qn8gGX/)

给定两个以升序排列的整数数组 `nums1` 和 `nums2` , 以及一个整数 `k` 。

定义一对值 `(u,v)`，其中第一个元素来自 `nums1`，第二个元素来自 `nums2` 。

请找到和最小的 `k` 个数对 `(u1,v1)`, ` (u2,v2)` ...  `(uk,vk)` 。

 

```c++
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

	typedef pair<int, int> pi;
	struct cmp {
		bool operator()(const pi &a, const pi &b) { 
			return a.first + a.second < b.first + b.second; 
		}
	};
	priority_queue<pi, vector<pi>, cmp> heap;
	for (int i = 0; i < nums1.size() && i < k; ++i) {
		for (int j = 0; j < nums2.size() && j < k; ++j) {
			if (heap.size() < k) {
				heap.push({ nums1[i], nums2[j] });
			}
			else if (nums1[i] + nums2[j] < heap.top().first + heap.top().second) {
				heap.pop();
				heap.push({ nums1[i], nums2[j] });
			}
		}
	}
	int size = heap.size();
	vector<vector<int>> res(size, vector<int>(2, 0));
	for (int i = 0; i < size; ++i) {
		res[size - 1 - i][0] = heap.top().first;
		res[size - 1 - i][1] = heap.top().second;
		heap.pop();
	}
	return res;
}
```

