#### [合并区间](https://leetcode-cn.com/problems/SsGoHC/)

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

```c++
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});
	int start = intervals[0][0];
	int end = intervals[0][1];
	for (auto &a : intervals) {
		if (a[0] > end) {
			res.push_back({ start, end });
			start = a[0];
			end = a[1];
		}
		else
			end = max(end, a[1]);
	}
	res.push_back({ start, end });
	return res;
}
```

#### [数组相对排序](https://leetcode-cn.com/problems/0H97ZC/)

给定两个数组，`arr1` 和 `arr2`，

- `arr2` 中的元素各不相同
- `arr2` 中的每个元素都出现在 `arr1` 中

对 `arr1` 中的元素进行排序，使 `arr1` 中项的相对顺序和 `arr2` 中的相对顺序相同。未在 `arr2` 中出现过的元素需要按照升序放在 `arr1` 的末尾。



```c++
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	unordered_map<int, int> mp;
	for (int i = 0; i < arr2.size(); ++i)
		mp[arr2[i]] = i;
	sort(arr1.begin(), arr1.end(), [&](const int& a, const int&b) {
		if (mp.find(a) != mp.end())
			return mp.find(b) != mp.end() ? mp[a] < mp[b] : true;
		return mp.find(b) != mp.end() ? false : a < b;
	});
	return arr1;
}
```

