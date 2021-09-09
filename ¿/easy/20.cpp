#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>

#define INF (0x7fffff)

using namespace std;

bool isValid(string s) {
	stack<char> st;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if ('(' == *it) st.push(')');
		else if ('[' == *it) st.push(']');
		else if ('{' == *it) st.push('}');
		else if (st.empty() || *it != st.top()) return false;
		else st.pop();
	}
	return st.empty();
}


int main() {
	cout << isValid("]") << endl;
	system("pause");
}
