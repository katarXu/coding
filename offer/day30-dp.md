#### [爬楼梯的最少成本](https://leetcode-cn.com/problems/GzCJIP/)

数组的每个下标作为一个阶梯，第 `i` 个阶梯对应着一个非负数的体力花费值 `cost[i]`（下标从 `0` 开始）。

每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。

请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。

```c++
int minCostClimbingStairs(vector<int>& cost) {
    for(int i = cost.size() - 3; i >= 0; --i)
        cost[i] += min(cost[i + 1], cost[i + 2]);
    return min(cost[0], cost[1]);
}
```

如果是顺着dp需要额外空间存储到当前楼梯的最小值

```c++
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int dp0 = 0, dp1 = 0, tmp = 0;
    if(n == 2) return min(cost[0], cost[1]);
    for(int i = 2; i <= n; ++i){
        tmp = min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
        dp0 = dp1;
        dp1 = tmp;
    }
    return tmp;
}
```



#### [房屋偷盗](https://leetcode-cn.com/problems/Gu0c2T/)

一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响小偷偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。

给定一个代表每个房屋存放金额的非负整数数组 `nums` ，请计算 **不触动警报装置的情况下** ，一夜之内能够偷窃到的最高金额。



```c++
int rob(vector<int>& nums) {
	int dp0 = 0, dp1 = 0;
	for (int &num : nums) {
        int tmp = dp0 + num;
		dp0 = max(dp0, dp1);
        dp1 = tmp;
        //tie(dp0, dp1) = tuple<int, int>{ max(dp0, dp1), dp0 + num };
	}
	return max(dp0, dp1);
}
```

#### [环形房屋偷盗](https://leetcode-cn.com/problems/PzWKhm/)

一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 **围成一圈** ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警** 。

给定一个代表每个房屋存放金额的非负整数数组 `nums` ，请计算 **在不触动警报装置的情况下** ，今晚能够偷窃到的最高金额。

```c++
int rob(vector<int>& nums) {
	int dp0 = nums[0], dp1 = nums[0], res = 0;
	for (int i = 2; i < nums.size() - 1; ++i) {
        int tmp = dp0 + nums[i];
		dp0 = max(dp0, dp1);
        dp1 = tmp;
	}
    res = max(dp0, dp1);
    dp0 = 0;
    dp1 = 0;
    for(int i = 1; i < nums.size(); ++i){
        int tmp = dp0 + nums[i];
		dp0 = max(dp0, dp1);
        dp1 = tmp;
    }
    return max(res, max(dp0, dp1));
}
```

