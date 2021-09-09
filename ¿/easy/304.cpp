#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

class NumMatrix {
public:
	vector<vector<int>> sum;
	NumMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row) {
			int col = matrix[0].size();
			sum.resize(row + 1, vector<int>(col + 1));
			for (int i = 0; i < row; ++i)
				for (int j = 0; j < col; ++j)
					sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
	}
};
int main() {
	vector<int> ans;
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
	return 0;
}