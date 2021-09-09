#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

#define INF (0x7fffff)

using namespace std;


int getValue(char ch) {
	switch (ch) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;
	}
}

int romanToInt(string s) {
	int sum = 0, temp = 0;
	for (unsigned i = 0; i < s.length(); ++i) {
		temp = getValue(s[i]);
		if (s.length() - 1 == i)
			sum += temp;
		else if (temp < getValue(s[i + 1]))
			sum -= temp;
		else
			sum += temp;
	}
	return sum;
}

int main() {
	cout << romanToInt("XXVI") << endl;
	system("pause");
}
