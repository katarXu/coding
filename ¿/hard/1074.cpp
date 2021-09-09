#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		if (0 == r)
			return 0;
		int c = matrix[0].size();
		int sum[301][301];
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) 
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
		int count = 0;
		for (int i = 0; i < r; ++i)
			for (int j = i; j < r; ++j)
				for (int k = 0; k < c; ++k)
					for (int l = k; l < c; ++l)
						if (sum[j + 1][l + 1] - sum[j + 1][k] - sum[i][l + 1] + sum[i][k] == target)
							++count;
		return count;
	}
};
int main() {
	vector<int> ans;
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
	return 0;
}