#### [二叉搜索树中的中序后继](https://leetcode-cn.com/problems/P5rCT8/)

给定一棵二叉搜索树和其中的一个节点 `p` ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 `null` 。

节点 `p` 的后继是值比 `p.val` 大的节点中键值最小的节点，即按中序遍历的顺序节点 `p` 的下一个节点。

```c++
TreeNode *pre;
TreeNode *res;
void dfs(TreeNode *root, TreeNode *&p){
    if(!root || res) return;
    dfs(root->left, p);
    if(pre == p)
        res = root;
    pre = root;
    dfs(root->right, p);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    dfs(root, p);
    return res;
}
```

#### [所有大于等于节点的值之和](https://leetcode-cn.com/problems/w6cpku/)

给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

```c++
int sum;

void dfs(TreeNode *root){
    if(!root) return;
    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    dfs(root);
    return root;
}
```

#### [二叉搜索树迭代器](https://leetcode-cn.com/problems/kTOapQ/)

实现一个二叉搜索树迭代器类`BSTIterator` ，表示一个按中序遍历二叉搜索树（BST）的迭代器：

- `BSTIterator(TreeNode root)` 初始化 `BSTIterator` 类的一个对象。BST 的根节点 `root` 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
- `boolean hasNext()` 如果向指针右侧遍历存在数字，则返回 `true` ；否则返回 `false` 。
- `int next()`将指针向右移动，然后返回指针处的数字。

注意，指针初始化为一个不存在于 BST 中的数字，所以对 `next()` 的首次调用将返回 BST 中的最小元素。

可以假设 `next()` 调用总是有效的，也就是说，当调用 `next()` 时，BST 的中序遍历中至少存在一个下一个数字。

```c++
stack<TreeNode*> sta;
TreeNode* cur;

BSTIterator(TreeNode* root) {
	cur = root;
}

int next() {
	while (cur != nullptr) {
		sta.push(cur);
		cur = cur->left;
	}
	cur = sta.top();
	sta.pop();
	int ret = cur->val;
	cur = cur->right;
	return ret;
}

bool hasNext() {
	return cur != nullptr || !sta.empty();
}
```

