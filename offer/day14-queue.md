#### [滑动窗口的平均值](https://leetcode-cn.com/problems/qIsx9U/)

给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 `MovingAverage` 类：

- `MovingAverage(int size)` 用窗口大小 `size` 初始化对象。

- `double next(int val)` 成员函数 `next` 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 `size` 个值的移动平均值，即滑动窗口里所有数字的平均值。

 

```c++
class MovingAverage {
public:
    int size, sum;
    queue<int> q;
    
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        if(size < q.size()){
            sum -= q.front();
            q.pop();
        }
        sum += val;
        return (double)sum / q.size();
    }
};
```

#### [最近请求次数](https://leetcode-cn.com/problems/H8086Q/)

写一个 `RecentCounter` 类来计算特定时间范围内最近的请求。

请实现 `RecentCounter` 类：

- `RecentCounter()` 初始化计数器，请求数为 0 。

- `int ping(int t)` 在时间 `t` 添加一个新请求，其中 `t` 表示以毫秒为单位的某个时间，并返回过去 `3000` 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 `[t-3000, t]` 内发生的请求数。

**保证** 每次对 `ping` 的调用都使用比之前更大的 `t` 值。

```c++
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        t -= 3000;
        while(q.front() < t)
            q.pop();
        return q.size();
    }
};
```

#### [往完全二叉树添加节点](https://leetcode-cn.com/problems/NaqhDT/)

完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 `n` 层有 `2n-1` 个节点）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 `CBTInserter`，它支持以下几种操作：

- `CBTInserter(TreeNode root)` 使用根节点为 `root` 的给定树初始化该数据结构；

- `CBTInserter.insert(int v)` 向树中插入一个新节点，节点类型为 `TreeNode`，值为 `v` 。使树保持完全二叉树的状态，**并返回插入的新节点的父节点的值**；
- `CBTInserter.get_root()` 将返回树的根节点。

```c++
class CBTInserter {
private:
    queue<TreeNode*> que;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        que.push(root);
        while (que.front()->left != nullptr && que.front()->right != nullptr) {
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        TreeNode* fa = que.front();
        if (fa->left == nullptr) {
            fa->left = node;
        }
        else {
            fa->right = node;
            que.push(fa->left);
            que.push(fa->right);
            que.pop();
        }
        return fa->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};
```

```c++
class CBTInserter {
public:
    TreeNode* root;
    int num;
    CBTInserter(TreeNode* root) {
        this->root = root;
        num = 0;
        cnt(root);
    }
    
    void cnt(TreeNode* root){
        if(root){
            num++;
            cnt(root->left);
            cnt(root->right);
        }
    }

    int insert(int v) {
        stack<int> s;
        int n = ++num / 2;
        TreeNode* t = root;
        while(n != 1){
            s.push(n);
            n /= 2;
        }
        while(!s.empty()){
            if(s.top() & 1) t = t->right;
            else t = t->left;
            s.pop();
        }
        if(t->left) t->right = new TreeNode(v);
        else t->left = new TreeNode(v);
        return t->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
```

