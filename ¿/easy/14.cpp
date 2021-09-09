#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

#define INF (0x7fffff)

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
	string res = strs.empty() ? "" : strs[0];
	for (string s : strs)
		while (s.find(res) != 0) res = res.substr(0, res.length() - 1);
	return res;
}

int main() {
	system("pause");
}
