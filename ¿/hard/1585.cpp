#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	bool isTransformable(string s, string t) {
		int n = s.size();
		vector<queue<int>> vec(10);
		for (int i = 0; i < n; ++i)	//±éÀús
			vec[s[i] - '0'].push(i);
		for (int i = 0; i < n; ++i) {
			int cur = t[i] - '0';
			if (vec[cur].empty())
				return false;
			else
				for (int j = 0; j < cur; ++j)
					if (!vec[j].empty() && vec[j].front() < vec[cur].front())
						return false;
			vec[cur].pop();
		}
		return true;
	}
};

int main() {

}