#### [二叉树剪枝](https://leetcode-cn.com/problems/pOCWxh/)

给定一个二叉树 **根节点** `root` ，树的每个节点的值要么是 `0`，要么是 `1`。请剪除该二叉树中所有节点的值为 `0` 的子树。

节点 `node` 的子树为 `node` 本身，以及所有 `node` 的后代。

```c++
TreeNode* pruneTree(TreeNode* root) {
    if(root){
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left == nullptr && root->right == nullptr && root->val == 0){
            //delete root;
            return nullptr;
        }
    }
    return root;
}
```

#### [序列化与反序列化二叉树](https://leetcode-cn.com/problems/h54YBf/)

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

```c++
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
	if (!root) return "null";
	return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode *dfs(vector<string> &arr, int &i) {
	if (arr[i] == "null") return nullptr;
	TreeNode *root = new TreeNode(stoi(arr[i]));
	root->left = dfs(arr, ++i);
	root->right = dfs(arr, ++i);
	return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	vector<string> arr{ "" };
	for (char &ch : data) {
		if (ch == ',')
			arr.emplace_back("");
		else
			arr.back().push_back(ch);
	}
	int i = 0;
	return dfs(arr, i);
}
```

