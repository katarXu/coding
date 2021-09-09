#include"binary.h"
#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

#define LEFT(i) (1<<(i-'a'))

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
	vector<int> ans;
	unordered_map<int, int> hashmap;
	for (auto it = words.begin(); it != words.end(); ++it) {
		int temp = 0;
		for (auto iit = (*it).begin(); iit != (*it).end(); ++iit)
			temp |= LEFT(*iit);
		++hashmap[temp];
	}
	for (auto it = puzzles.begin(); it != puzzles.end(); ++it) {
		int temp = 0, num = 0;
		for (auto iit = (*it).begin() + 1; iit != (*it).end(); ++iit)
			temp |= LEFT(*iit);
		int subset = temp;
		do {
			int s = subset | LEFT((*it)[0]);
			if (hashmap.count(s))
				num += hashmap[s];
			subset = (subset - 1)&temp;
		} while (subset != temp);
		ans.push_back(num);
	}
	/*
		for (auto it = puzzles.begin(); it != puzzles.end(); ++it) {
		int temp = 0, num = 0;
		for (auto iit = (*it).begin(); iit != (*it).end(); ++iit)
			temp |= LEFT(*iit);
		for (int i = 0; i < words.size(); ++i) {
			if ((LEFT((*it)[0]) & binaryWords[i]) == LEFT((*it)[0]) && ((binaryWords[i] | temp) == temp))
				num++;
		}
		ans.push_back(num);
	}
	*/
	return ans;
}
int main() {
	vector<string> words{ "aaaa", "asas", "able", "ability", "actt", "actor", "access" };
	vector<string> puzzles{ "aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz" };
	vector<int> ans = findNumOfValidWords(words, puzzles);
	for (auto it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
	system("pause");
	return 0;
}