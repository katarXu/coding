#### [数组中和为 0 的三个数](https://leetcode-cn.com/problems/1fGaJU/)

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。

 

直接搜索比较难去重（set、map没有对vector实现哈希函数），因此考虑排序后搜索，去掉与上次相同的搜索即可

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = (int)nums.size();
	vector<vector<int>> res;
	for (int i = 0; i < n; ++i) {
        if(i > 0 && nums[i - 1] == nums[i])
            continue;
		int left = i + 1, right = n - 1, last = nums[0] - 1;
		while (left < right) {
			int tmp = nums[i] + nums[left] + nums[right];
			if (tmp > 0) right--;
			else if (tmp < 0) left++;
			else {
				if (nums[left] != last) {
					last = nums[left];
					res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
				}
				left++, right--;
			}
		}
	}
	return res;
}
```

#### [和大于等于 target 的最短子数组](https://leetcode-cn.com/problems/2VG8Kg/)

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



## 双指针

```c++
int minSubArrayLen(int target, vector<int>& nums) {
	int n = (int)nums.size();
	if (!n) return 0;
	int left = 0, right = 1, sum = nums[0], res = n + 1;
	while (true) {
		if (sum < target) {
			if (right != n) right++;
			else return res == n + 1 ? 0 : res;
			sum += nums[right - 1];
		}
		else {
			res = min(res, right - left);
			sum -= nums[left++];
		}
	}
	return 0;
}
```

好看一点的：

```c++
int minSubArrayLen(int target, vector<int>& nums) {
	int left = 0;
	int sum = 0;
	int minLen = INT_MAX;
	for (int right = 0; right < nums.size(); ++right) {
		sum += nums[right];
		while (left <= right && sum >= target) {
			minLen = min(minLen, right - left + 1);
			sum -= nums[left++];
		}
	}
	return (minLen == INT_MAX) ? 0 : minLen;
}
```





#### [乘积小于 K 的子数组](https://leetcode-cn.com/problems/ZVAVXX/)

给定一个正整数数组 `nums`和整数 `k` ，请找出该数组内乘积小于 `k` 的连续的子数组的个数。

## 双指针

同上

```c++
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	long long mul = 1;
	int left = 0;
	int res = 0;
	for (int right = 0; right < nums.size(); ++right) {
		mul *= nums[right];
		while (left <= right && mul >= k)
			mul /= nums[left++];
		res += (left <= right) ? right - left + 1 : 0;
	}
	return res;
}
```

