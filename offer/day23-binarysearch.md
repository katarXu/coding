#### [查找插入位置](https://leetcode-cn.com/problems/N6YdxV/)

给定一个排序的整数数组 `nums` 和一个整数目标值` target` ，请在数组中找到 `target `，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 `O(log n)` 的算法。

- mid = left + ((right - left) >> 1) 的写法比 mid = (left + right) / 2 好，因为 left + right 可能会溢出，同时位运算的效率更高；
- 当出现 nums[mid] >= target 的情况，还需要加一个判断 mid == 0 || nums[mid - 1] < target，若成立则说明，前一个数比 target 小，那么就找到了位置。若在 while 循环内都未找到符合要求的位置，那么说明 target 比所有的数都要大，需要插入到数组的最后一个数字之后，即返回 nums.size()。

```c++
int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}
```

#### [山峰数组的顶部](https://leetcode-cn.com/problems/B1IidL/)

符合下列属性的数组 `arr` 称为 **山峰数组**（**山脉数组）** ：

- `arr.length >= 3`
- 存在 `i`（`0 < i < arr.length - 1`）使得：
  - `arr[0] < arr[1] < ... arr[i-1] < arr[i]`
  - `arr[i] > arr[i+1] > ... > arr[arr.length - 1]`

```c++
int peakIndexInMountainArray(vector<int>& arr) {
    int left = 1;
    int right = arr.size() - 2;
    while(left <= right){
        int mid = left + (right - left >> 1);
        if(arr[mid] < arr[mid + 1])
            left = mid + 1;
        else if(arr[mid] < arr[mid - 1])
            right = mid - 1;
        else
            return mid;
    }
    return 0;
}
```



#### [排序数组中只出现一次的数字](https://leetcode-cn.com/problems/skFtm2/)

给定一个只包含整数的有序数组 `nums` ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。



二分查找第一个不相等的数对

```c++
int singleNonDuplicate(vector<int>& nums) {
	int left = 0;
	int right = nums.size() / 2 - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		int i = mid << 1;
		if (nums[i] != nums[i + 1]) {
			if (i == 0 || nums[i - 1] == nums[i - 2])
				return nums[i];
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return nums.back();
}
```

