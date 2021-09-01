#### [只出现一次的数字 ](https://leetcode-cn.com/problems/WGki4K/)

给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。

**进阶：**你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

## 位运算

统计每位1的个数模3即可，注意`INT_MIN`左移是未定义行为，最好用`unsigned`

```c++
int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int mask = 1; mask != 0; mask <<= 1) {
		int cnt = 0;
		for (int &x : nums)
			if (x & mask) cnt++;
		if (cnt % 3) res |= mask;
	}
	return res;
}
```

### leecode上的更优解

对某一位具体分析，由于模3有余0、1、2三种情况，故使用两个二进制数$[two,one]$来记录，通过$(00),(01),(10)$表示三进制的0、1、2

先看one，易有`one = (one ^ num) & ~two`

在新one的基础上算two，有`two = (two ^ num) & ~one`（最好是画真值表等方法推导）

最后one是出现1次的，two是出现两次的

```c++
int singleNumber(vector<int>& nums) {
	int two = 0, one = 0;
	for (int &num : nums) {
		one = (one ^ num) & ~two;
		two = (two ^ num) & ~one;
	}
	return one;
}
```





#### [单词长度的最大乘积](https://leetcode-cn.com/problems/aseY1I/)

给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

## 哈希

用哈希表确定单词是否含字母，由于最多26个单词，可以用int类型整数当哈希表

```c++
int maxProduct(vector<string>& words){
    int n = (int)words.size();
    int res = 0;
    vector<int> mask(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < words[i].size(); ++j)
            mask[i] |= 1 << (words[i][j] - 'a');
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            if((mask[i] & mask[j]) == 0)
                res = max(res, int(words[i].size() * words[j].size()));
    return res;
}
```

#### [排序数组中两个数字之和](https://leetcode-cn.com/problems/kLl5u1/)

给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 0 开始计数 ，所以答案数组应当满足 0 <= answer[0] < answer[1] < numbers.length 。

假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。

## 双指针

```c++
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = (int)numbers.size() - 1;
    while(numbers[left] + numbers[right] != target){
        if(numbers[left] + numbers[right] > target) right--;
        else left++;
    }
    return vector<int>{left, right};
}
```

