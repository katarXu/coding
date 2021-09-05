#### [数组中的第 k 大的数字](https://leetcode-cn.com/problems/xx4gT2/)

给定整数数组 `nums` 和整数 `k`，请返回数组中第 **`k`** 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。





小顶堆 o(nlogk) 快排 o(n)

```c++
int partition(vector<int>& nums, int start, int end) {
	int rad = rand() % (end - start + 1) + start;
	swap(nums[rad], nums[end]);
	int big = start - 1;
	for (int i = start; i < end; ++i) {
		if (nums[i] > nums[end]) {
			big++;
			swap(nums[big], nums[i]);
		}
	}
	big++;
	swap(nums[big], nums[end]);
	return big;
}

int findKthLargest(vector<int>& nums, int k) {
	int start = 0;
	int end = nums.size() - 1;
	int i = partition(nums, start, end);
	while (i != k - 1) {
		i < k - 1 ? start = i + 1 : end = i - 1;
		i = partition(nums, start, end);
	}
	return nums[k - 1];
}
```





