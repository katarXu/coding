#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x7ffff
using namespace std;

/*
void moveZeroes(vector<int>& nums) {
	stable_sort(nums.begin(), nums.end(), [](int a, int b) {return b == 0; });
}
*/
void moveZeroes(vector<int>& nums) {
	int l = 0, r = 0;
	while (r < nums.size()) {
		if (nums[r]) {
			swap(nums[l], nums[r]);
			++l;
		}
		++r;
	}
}
int main() {
	vector<int> a = {0,3,12,0,9,0};
	moveZeroes(a);
	for (auto x : a)
		cout << x << ' ';
	system("pause");

}