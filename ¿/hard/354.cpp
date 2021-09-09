#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (!n)
			return 0;
		stack<pair<int, int>> s;
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			if (s.empty() || i != n && s.top().first <= heights[i]) {
				s.push(make_pair(heights[i], i));
			}
			else {
				while (!s.empty() && (i == n || s.top().first > heights[i])) {
					int height = s.top().first;
					int right = i - 1;
					s.pop();
					int left = s.empty() ? -1 : s.top().second;
					ans = max(ans, (right - left)*height);
				}
				if (i != n)
					s.push(make_pair(heights[i], i));
			}
		}
		return ans;
	}
};

int main() {
	vector<int> heights{ 2,1,5,6,2,3 };
	Solution s;
	cout << s.largestRectangleArea(heights) << endl;
	system("pause");
	return 0;
}