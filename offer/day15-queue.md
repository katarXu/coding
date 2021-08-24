#### [二叉树每层的最大值](https://leetcode-cn.com/problems/hPov7L/)

给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层的最大值。

```c++
vector<int> largestValues(TreeNode* root) {
	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int maxNum = INT_MIN;
		int cnt = q.size();
		for (int i = 0; i < cnt; ++i) {
			maxNum = max(maxNum, q.front()->val);
			if (q.front()->left)
				q.push(q.front()->left);
			if (q.front()->right)
				q.push(q.front()->right);
		}
		res.emplace_back(maxNum);
		q.pop();
	}
	return res;
}
```

#### [二叉树最底层最左边的值](https://leetcode-cn.com/problems/LwUNpT/)

给定一个二叉树的 **根节点** `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

```c++
int findBottomLeftValue(TreeNode* root) {
    int res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        res = q.front()->val;
        int cnt = q.size();
        for(int i = 0; i < cnt; ++i){
			if (q.front()->left)
				q.push(q.front()->left);
			if (q.front()->right)
				q.push(q.front()->right);
            q.pop();
        }
    }
    return res;
}
```

#### [二叉树的右侧视图](https://leetcode-cn.com/problems/WNC0Lk/)

给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

```c++
vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int cnt = q.size();
        for(int i = 1; i <= cnt; ++i){
			if (q.front()->left)
				q.push(q.front()->left);
			if (q.front()->right)
				q.push(q.front()->right);
            if(i == cnt)
                res.emplace_back(q.front()->val);
            q.pop();
        }
    }
    return res;
}
```

