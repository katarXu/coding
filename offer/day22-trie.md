#### [最短的单词编码](https://leetcode-cn.com/problems/iSwD2y/)

单词数组 `words` 的 **有效编码** 由任意助记字符串 `s` 和下标数组 `indices` 组成，且满足：

- `words.length == indices.length`
- 助记字符串 `s` 以 `'#'` 字符结尾
- 对于每个下标 `indices[i]` ，`s` 的一个从 `indices[i]` 开始、到下一个 `'#'` 字符结束（但不包括 `'#'`）的 **子字符串** 恰好与 `words[i]` 相等

给定一个单词数组 `words` ，返回成功对 `words` 进行编码的最小助记字符串 `s` 的长度 。

```c++
int minimumLengthEncoding(vector<string>& words) {
	for (auto & s : words) 
		reverse(s.begin(), s.end());
	sort(words.begin(), words.end());
	auto prefix = [](string & pre, string & s) {
		int n = pre.size(), m = s.size();
		if (n <= m) {
			return pre == s.substr(0, n);
		}
		return false;
	};
	words.push_back("");
	int n = words.size(), result = 0;
	for (int i = 0; i < n - 1; i++) 
		if (!prefix(words[i], words[i + 1])) 
			result += words[i].length() + 1;
	return result;
}
```



```c++
class Trie {
public:
    vector<Trie*> children;
    Trie () : children(26, nullptr) {}
};

class Solution {
private:
    int total;

    Trie* buildTrie(const vector<string>& words) {
        Trie* root = new Trie();
        for (const string &str : words) {
            Trie* node = root;
            for (int i = str.size() - 1; i >= 0; --i) {
                if (node->children[str[i] - 'a'] == nullptr) {
                    node->children[str[i] - 'a'] = new Trie();
                }
                node = node->children[str[i] - 'a'];
            }
        }
        return root;
    }

    void dfs(Trie* root, int len) {
        bool isLeaf = true;
        for (Trie *&child : root->children) {
            if (child != nullptr) {
                isLeaf = false;
                dfs(child, len + 1);
            }
        }
        if (isLeaf)
            total += len;
    }
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* root = buildTrie(words);
        total = 0;
        dfs(root, 1);
        return total;
    }
};
```

```c++
class Trie {
public:
	vector<Trie*> children;
	int cnt;
	Trie() : children(26, nullptr), cnt(0) {}
};

class Solution {
private:
	Trie* buildTrie(const vector<string>& words) {
		Trie* root = new Trie();
		for (const string &str : words) {
			Trie* node = root;
			for (int i = str.size() - 1; i >= 0; --i) {
				if (node->children[str[i] - 'a'] == nullptr)
					node->children[str[i] - 'a'] = new Trie();
				node = node->children[str[i] - 'a'];
				node->cnt++;
			}
		}
		return root;
	}


	int search(Trie *& trie, string &str) {
		Trie *node = trie;
		for (int i = str.size() - 1; i >= 0; --i)
			node = node->children[str[i] - 'a'];
		return node->cnt--;
	}

public:
	int minimumLengthEncoding(vector<string>& words) {
		Trie* trie = buildTrie(words);
		int res = 0;
		for (string &str : words)
			if (search(trie, str) == 1)
				res += str.size() + 1;
		return res;
	}
};
```



#### [单词之和](https://leetcode-cn.com/problems/z1R5dt/)

实现一个 `MapSum` 类，支持两个方法，`insert` 和 `sum`：

- `MapSum()` 初始化 `MapSum` 对象
- `void insert(String key, int val)` 插入 `key-val` 键值对，字符串表示键 `key` ，整数表示值 `val` 。如果键 `key` 已经存在，那么原来的键值对将被替代成新的键值对。
- `int sum(string prefix)` 返回所有以该前缀 `prefix` 开头的键 `key` 的值的总和。

```c++
class Trie {
public:
	vector<Trie*> children;
	int cnt, val;
	bool isWord;
	Trie() : children(26, nullptr), cnt(0), val(0), isWord(false) {}
};

class MapSum {
public:
	Trie *trie;

	MapSum() {
		trie = new Trie();
	}

	void insert(string key, int val) {
		Trie *node = trie;
		bool flag = true;
		int nVal = val;
		for (char &ch : key) {
			if (node->children[ch - 'a'] == nullptr) {
				flag = false;
				break;
			}
			node = node->children[ch - 'a'];
		}
		if (flag && node->isWord)
            nVal = val - node->val;
		node = trie;
		for (char &ch : key) {
			if (node->children[ch - 'a'] == nullptr)
				node->children[ch - 'a'] = new Trie();
			node = node->children[ch - 'a'];
			node->cnt += nVal;
		}
		node->val = val;
		node->isWord = true;
	}

	int sum(string prefix) {
		Trie *node = trie;
		for (char &ch : prefix) {
			if (node->children[ch - 'a'] == nullptr)
				return 0;
			node = node->children[ch - 'a'];
		}
		return node->cnt;
	}
};
```

