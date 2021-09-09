#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<utility>
#include<string>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		if (s.empty())
			return 0;
		int res = 0, n = s.size(), temp = 0;
		bool flag = true;
		stack<bool> op;
		op.push(true);
		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ')
				continue;
			else if (s[i] == '(') {
				op.push(!flag^op.top());
				flag = true;
			}
			else if (s[i] == ')')
				op.pop();
			else if (s[i] == '-') flag = false; 
			else if (s[i] == '+') flag = true;
			else if (i == n - 1 || s[i + 1]<'0' || s[i + 1]>'9') {
				temp = temp * 10 + (s[i] - '0');
				res += !flag^op.top() ? temp : -temp;
				temp = 0;
			}
			else
				temp = temp * 10 + (s[i] - '0');
		}
		return res + temp;
	}
};

int main() {
	//vector<vector<int>> envelopes{ {5,4},{6,4},{6,7},{2,3} };
	string S("-(11+(4+5+2)-3)+(6+8)");
	Solution s;
	cout << s.calculate(S);
	system("pause");
	return 0;
}