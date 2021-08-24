#### [后缀表达式](https://leetcode-cn.com/problems/8Zf90G/)

根据[ 逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437)，求该后缀表达式的计算结果。

有效的算符包括 `+`、`-`、`*`、`/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 ```c++
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for(string &x : tokens){
        if(x.size() > 1 || isdigit(x[0]))
            s.push(stoi(x));
        else{
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            switch(x[0]){
            case '+': s.push(num1 + num2); break;
            case '-': s.push(num1 - num2); break;
            case '*': s.push(num1 * num2); break;
            case '/': s.push(num1 / num2); break;
            }
        }
    }
    return s.top();
}
 ```

#### [小行星碰撞](https://leetcode-cn.com/problems/XagZNi/)

给定一个整数数组 `asteroids`，表示在同一行的小行星。

对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。

找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

```c++
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    for(int &x : asteroids){
        if(x >= 0)
            res.emplace_back(x);
        else{
            int tmp = -x;
            while(!res.empty() && res.back() >= 0 && tmp > res.back())
                res.pop_back();
            if(res.empty() || res.back() < 0)
                res.emplace_back(x);
            else if(tmp == res.back())
                res.pop_back();
        }
    }
    return res;
}
```



#### [每日温度](https://leetcode-cn.com/problems/iIQa4I/)

请根据每日 `气温` 列表 `temperatures` ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

 

单调栈

逆序：

递减栈，找到右侧比当前元素大的递增序列

```c++
vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> res(t.size());
    stack<int> s;
    for(int i = (int)t.size() - 1; i >= 0; --i){
        while(!s.empty() && t[s.top()] <= t[i])
            s.pop();
        res[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }
    return res;
}
```

顺序：

递减栈，遇到比栈顶元素大时更新

```c++
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ret(temperatures.size(), 0);
    stack<int> sta;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
            ret[sta.top()] = i - sta.top();
            sta.pop();
        }
        sta.push(i);
    }
    return ret;
    }\
```

