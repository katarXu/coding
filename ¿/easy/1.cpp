#include<iostream>
#include<unordered_map>
#include<vector>

#define INF (0x7fffff)

using namespace std;



vector<int> solve(vector<int>& nums, int target) {
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); ++i) {
		unordered_map<int, int>::iterator it = hash.find(target - nums[i]);
		if (it != hash.end())
			return { it->second,i };
		hash[nums[i]] = i;
	}
	return {};
}

int main() {
	vector<int> nums = { 2,7,11,15 };
	vector<int> ans = solve(nums, 9);
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
}
