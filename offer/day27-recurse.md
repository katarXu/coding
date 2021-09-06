#### [所有子集](https://leetcode-cn.com/problems/TVdhkn/)

给定一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的子集（幂集）。

解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。



### 回溯

```c++
vector<vector<int>> res;
int n;
void dfs(vector<int> &cur, vector<int>& nums, int i){
    if(i == n){
        res.emplace_back(cur);
        return;
    }
    dfs(cur, nums, i + 1);
    cur.emplace_back(nums[i]);
    dfs(cur, nums, i + 1);
    cur.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> cur;
    n = nums.size();
    dfs(cur, nums, 0);
    return res;
}
```

### leecode

```c++
vector<vector<int>> &ret;
vector<int> & cur;
void helper(vector<int>& nums, int index){
	ret.emplace_back(curStr);
	if (index == nums.size())
		return;

	for (int i = index; i < nums.size(); i++){
		cur.emplace_back(nums[i]);
		helper(nums, i + 1);
		cur.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	helper(nums, 0);
	return ret;
}
```



#### [含有 k 个元素的组合](https://leetcode-cn.com/problems/uUsW3B/)

给定两个整数 `n` 和 `k`，返回 `1 ... n` 中所有可能的 `k` 个数的组合。

```c++
vector<vector<int>> res;
int n;
int k;
void dfs(vector<int> &cur, int i, int j){
    if(i == n || j == k){
        if(j == k)
            res.emplace_back(cur);
        return;
    }
    dfs(cur, i + 1, j);
    cur.emplace_back(i + 1);
    dfs(cur, i + 1, j + 1);
    cur.pop_back();
}


vector<vector<int>> combine(int n, int k) {
    vector<int> cur;
    this->n = n;
    this->k = k;
    dfs(cur, 0, 0);
    return res;
}
```

### leecode

```c++
vector<vector<int>> ans;
vector<int> temp;
void dfs(int n, int k, int t) {
	if (!k) {
		ans.push_back(temp);
		return;
	}
	for (int i = t; i <= n - k + 1; i++) {
		temp.push_back(i);
		dfs(n, k - 1, i + 1);
		temp.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	dfs(n, k, 1);
	return ans;
}
```

#### [允许重复选择元素的组合](https://leetcode-cn.com/problems/Ygoe9J/)

给定一个**无重复元素**的正整数数组 `candidates` 和一个正整数 `target` ，找出 `candidates` 中所有可以使数字和为目标数 `target` 的唯一组合。

`candidates` 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 `target` 的唯一组合数少于 `150` 个。

```c++
vector<vector<int>> res;
vector<int> cur;
void dfs(vector<int>& nums, int sum, int i){
    if(!sum){
        res.emplace_back(cur);
        return;
    }
    if(i == nums.size() || sum < nums[i])
        return;
    dfs(nums, sum, i + 1);
    cur.emplace_back(nums[i]);
    dfs(nums, sum - nums[i], i);
    cur.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return res;
}
```

