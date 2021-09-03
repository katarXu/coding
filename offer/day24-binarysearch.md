#### [按权重生成随机数](https://leetcode-cn.com/problems/cuyjEf/)

给定一个正整数数组 `w` ，其中 `w[i]` 代表下标 `i` 的权重（下标从 `0` 开始），请写一个函数 `pickIndex` ，它可以随机地获取下标 `i`，选取下标 `i` 的概率与 `w[i]` 成正比。

也就是说，选取下标 `i` 的概率为 `w[i] / sum(w)` 。



求前缀和后二分查找

```c++
class Solution {
public:
    vector<int> sum;
    Solution(vector<int>& w) {
        srand(time(0));
        sum.resize(w.size());
        sum[0] = w[0];
        for(int i = 1; i < w.size(); ++i)
            sum[i] = sum[i - 1] + w[i];
    }
    
    int pickIndex() {
        int res = rand() % sum[sum.size() - 1] + 1;
        return lower_bound(sum.begin(), sum.end(), res) - sum.begin();
    }
};
```

### leecode

```c++
class Solution {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;

public:
    Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};
```

#### [求平方根](https://leetcode-cn.com/problems/jJ0w9p/)

给定一个非负整数 `x` ，计算并返回 `x` 的平方根，即实现 `int sqrt(int x)` 函数。

正数的平方根有两个，只输出其中的正数平方根。

如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。



对[1, x)进行二分查找

```c++
int mySqrt(int x) {
	int left = 0, right = min(x, (int)1e6);
	while (left < right) {
		int mid = left + (right - left + 1 >> 1);
		if (mid <= x / mid)
			left = mid;
		else
			right = mid - 1;
	}
	return left;
}
```

#### [狒狒吃香蕉](https://leetcode-cn.com/problems/nZZqjQ/)

狒狒喜欢吃香蕉。这里有 `N` 堆香蕉，第 `i` 堆中有 `piles[i]` 根香蕉。警卫已经离开了，将在 `H` 小时后回来。

狒狒可以决定她吃香蕉的速度 `K` （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 `K` 根。如果这堆香蕉少于 `K` 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。 

狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 `H` 小时内吃掉所有香蕉的最小速度 `K`（`K` 为整数）。



根据速度k来二分查找

```c++
int computer(vector<int>& piles, int k){
    int cnt = 0;
    for(int &pile : piles)
        cnt += (pile - 1) / k + 1;
    return cnt;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while(left < right){
        int mid = left + (right - left >> 1);
        if(computer(piles, mid) <= h)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
```





## 避免二分查找临界值的情况

在满足条件的一侧使用`left or right = mid`，根据需要确定是否需要`right - left + 1`（一般来说，`left = mid`时需要`+ 1`

