#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		int front = 0, cur = 0, maxn = 0;
		for (int i = 0; i < n; ++i) {
			front = 0;
			cur = -1;
			for (int j = i; j < n; ++j) {
				if (s[j] == '(') front++;
				else if (s[j] == ')') front--;
				if (front < 0) break;
				else if (front == 0) cur = j;
			}
			if (cur != -1)
				maxn = max(maxn, cur - i + 1);
		}
		return maxn > 1 ? maxn : 0;
	}
	//贪心
	int longestValidParentheses1(string s) {
		int left = 0, right = 0, maxlength = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') 
				left++;
			else 
				right++;
			if (left == right) 
				maxlength = max(maxlength, 2 * right);
			else if (right > left) 
				left = right = 0;
		}
		left = right = 0;
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			if (s[i] == '(') 
				left++;
			else 
				right++;
			if (left == right) 
				maxlength = max(maxlength, 2 * left);
			else if (left > right) 
				left = right = 0;
		}
		return maxlength;
	}  
	//dp
	/*
	(): dp[i] = dp[i - 2];
	)) && s[i - dp[i - 1] - 1] == '(': dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
	*/
	int longestValidParentheses2(string s) {
		int maxans = 0, n = s.length();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}
	//栈，确定最右未被匹配的右括号
	int longestValidParentheses(string s) {
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();
				if (stk.empty()) {
					stk.push(i);
				}
				else {
					maxans = max(maxans, i - stk.top());
				}
			}
		}
		return maxans;
	}

};


int main() {

}