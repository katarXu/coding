#### [含有重复元素集合的组合](https://leetcode-cn.com/problems/4sjJUc/)

给定一个可能有重复数字的整数数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 

```c++
vector<vector<int>> res;
vector<int> cur;
void dfs(vector<int>& nums, int sum, int i){
    if(!sum){
        res.emplace_back(cur);
        return;
    }
    if(i >= nums.size() || sum < nums[i])
        return;
    int j = i;
    while(j < nums.size() && nums[j] == nums[i]) ++j;
    dfs(nums, sum, j);
    cur.emplace_back(nums[i]);
    dfs(nums, sum - nums[i], i + 1);
    cur.pop_back();
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return res;
}
```



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

