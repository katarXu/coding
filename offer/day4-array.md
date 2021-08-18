#### [和为 k 的子数组](https://leetcode-cn.com/problems/QTMn0o/)

给定一个整数数组和一个整数 `k` **，**请找到该数组中和为 `k` 的连续子数组的个数。



若是正整数可以考虑双指针，o(n)

这题可能有非正整数，每当遍历到$i$时，需要遍历所有$j$满足$sum[i]-sum[j-1]==k$，也就是计算$sum[j-1]=sum[i]-k$的个数，故使用hash表

当$k=0$的时候可能多算，故后增加hash值

```c++
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    int res = 0, sum = 0;
    hash[0] = 1;
    for(int &x : nums){
        sum += x;
        if(hash.count(sum - k))
            res += hash[sum - k];         
        hash[sum]++;
    }
    return res;
}
```

#### [0 和 1 个数相同的子数组](https://leetcode-cn.com/problems/A1NYOS/)

给定一个二进制数组 `nums` , 找到含有相同数量的 `0` 和 `1` 的最长连续子数组，并返回该子数组的长度。



和上面题一样的思路

```c++
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> hash;
    int res = 0, sum = 0;
    hash[0] = -1;
    for(int i = 0; i < nums.size(); ++i){
        sum += nums[i] == 1 ? 1 : -1;
        if(!hash.count(sum))
            hash[sum] = i;
        else
            res = max(res, i - hash[sum]);
    }
    return res;
}
```

#### [左右两边子数组的和相等](https://leetcode-cn.com/problems/tvdfij/)

给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

```c++
int pivotIndex(vector<int>& nums) {
    int sum = 0, save = 0;
    for(int &x : nums)
        sum += x;
    for(int i = 0; i < nums.size(); ++i){
        sum -= nums[i];
        if(save == sum)
            return i;
        save += nums[i];
    }
    return -1;
}
```

#### [二维子矩阵的和](https://leetcode-cn.com/problems/O4NDxx/)

给定一个二维矩阵`matrix`，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的左上角为 `(row1, col1)` ，右下角为 `(row2, col2)` 。
实现 `NumMatrix` 类：

`NumMatrix(int[][] matrix) `给定整数矩阵 `matrix` 进行初始化
`int sumRegion(int row1, int col1, int row2, int col2)` 返回左上角 `(row1, col1)` 、右下角 `(row2, col2) `的子矩阵的元素总和。



有手就行

```c++
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }
```

