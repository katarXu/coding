#include<iostream>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int gastotal = 0, costtotal = 0, start = 0, left = 0;
	for (int i = 0; i < gas.size(); ++i) {
		gastotal += gas[i];
		costtotal += cost[i];
		left += gas[i] - cost[i];
		if (left < 0) {
			start = i + 1;
			left = 0;
		}
	}
	if (gastotal < costtotal)
		return -1;
	return start;
}

int main() {
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << canCompleteCircuit(gas, cost) << endl;
	system("pause");

}