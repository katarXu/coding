#### [向下的路径节点之和](https://leetcode-cn.com/problems/6eUYwP/)

给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。



### dfs

```c++
unordered_map<int, int> mp;
int targetSum;

int pathSum(TreeNode* root, int targetSum) {
    this->targetSum = targetSum;
    mp[0] = 1;
    return dfs(root, 0);
}

int dfs(TreeNode* root, int sum){
    if(!root) return 0;
    int tmp = 0;
    sum += root->val;
    if(mp.count(sum - targetSum))
        tmp += mp[sum - targetSum];
    mp[sum]++;
    tmp += dfs(root->left, sum) + dfs(root->right, sum);
    mp[sum]--;
    return tmp;
}
```

#### [节点之和最大的路径](https://leetcode-cn.com/problems/jC7MId/)

**路径** 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 **至多出现一次** 。该路径 **至少包含一个** 节点，且不一定经过根节点。

**路径和** 是路径中各节点值的总和。

给定一个二叉树的根节点 `root` ，返回其 **最大路径和**，即所有路径上节点值之和的最大值。

```c++
int res;

int dfs(TreeNode *root){
    if(!root) return 0;
    int lval = max(dfs(root->left), 0);
    int rval = max(dfs(root->right), 0);
    res = max(res, root->val + lval + rval);
    return root->val + max(lval, rval);
}

int maxPathSum(TreeNode* root) {
    res = INT_MIN;
    dfs(root);
    return res;
}
```

#### [展平二叉搜索树](https://leetcode-cn.com/problems/NYBBNL/)

给你一棵二叉搜索树，请 **按中序遍历** 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

```c++
TreeNode* head = nullptr;
TreeNode* pre = nullptr;
void dfs(TreeNode *root){
    if(!root) return;
    dfs(root->left);
    if(pre == nullptr)
        head = pre = root;
    else{
        root->left = nullptr;
        pre->right = root;
        pre = root;
    }
    dfs(root->right);
}

TreeNode* increasingBST(TreeNode* root) {
    dfs(root);
    return head;
}
```

```c++
TreeNode* dummy;
TreeNode* pre;
void dfs(TreeNode *root){
    if(!root) return;
    dfs(root->left);
    root->left = nullptr;
    pre->right = root;
    pre = root;
    dfs(root->right);
}

TreeNode* increasingBST(TreeNode* root) {
    dummy = new TreeNode(-1);
    pre = dummy;
    dfs(root);
    return dummy->right;
}
```

