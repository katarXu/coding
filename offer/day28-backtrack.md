#### [没有重复元素集合的全排列](https://leetcode-cn.com/problems/VvJkup/)

给定一个不含重复数字的整数数组 `nums` ，返回其 **所有可能的全排列** 。可以 **按任意顺序** 返回答案。



### 回溯

```c++
void helper(vector<int>& nums, int index, vector<vector<int>>& ret) {
	if (index == nums.size()) {
		ret.emplace_back(nums);
		return;
	}

	for (int i = index; i < nums.size(); ++i) {
        if(i != index && nums[index] == nums[i])
            continue;
		swap(nums[index], nums[i]);
		helper(nums, index + 1, ret);
		swap(nums[index], nums[i]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ret;
	helper(nums, 0, ret);
	return ret;
}
```

### 直接

```c++
bool next_permution(vector<int> &nums) {
	int i = nums.size() - 1;
	int j = nums.size() - 1;
	while (i > 0 && nums[i] < nums[i - 1])
		i--;
	if (--i < 0) return false;
	while (nums[j] < nums[i])
		--j;
	swap(nums[i], nums[j]);
	sort(nums.begin() + i + 1, nums.end());
	return true;
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	do {
		res.emplace_back(nums);
	} while (next_permution(nums));
	return res;
}
```

#### [含有重复元素集合的全排列 ](https://leetcode-cn.com/problems/7p8L0Z/)

给定一个可包含重复数字的整数集合 `nums` ，**按任意顺序** 返回它所有不重复的全排列。

```c++
bool next_permution(vector<int> &nums) {
	int i = nums.size() - 1;
	int j = nums.size() - 1;
	while (i > 0 && nums[i] <= nums[i - 1])
		i--;
	if (--i < 0) return false;
	while (nums[j] <= nums[i])
		--j;
	swap(nums[i], nums[j]);
	sort(nums.begin() + i + 1, nums.end());
	return true;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	do {
		res.emplace_back(nums);
	} while (next_permution(nums));
	return res;
}
```

