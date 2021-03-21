#### [买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

给定一个数组，它的第 `i` 个元素是一支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成**两笔**交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



# 方法一 动态规划

由于我们最多可以完成两笔交易，因此在任意一天结束之后，我们会处于以下五个状态中的一种：

> 未进行过任何操作
>
> 只进行过一次买操作	$$buy_1$$
>
> 进行了一次买操作和一次卖操作，即完成了一笔交易	$$sell_1$$
>
> 在完成了一笔交易的前提下，进行了第二次买操作	$$buy_2$$
>
> 完成了全部两笔交易	$$sell_2$$

第一种状态为0无需考虑，则有转移方程

$$buy_1[i]=max(buy_1[i-1],-price[i])$$

$$sell_1[i]=max(sell_1[i-1],buy_1[i-1]+price[i])$$

$$buy_2[i]=max(buy_2[i-1],sell_1[i-1]-price[i])$$

$$sell_2[i]=max(sell_2[i-1],buy_2[i-1]+price[i])$$

由于状态只涉及$$i$$和$$i-1$$，可以简化为

$$buy_1=max(buy_1,-price[i])$$

$$sell_1=max(sell_1,buy_1+price[i])$$

$$buy_2=max(buy_2,sell_1-price[i])$$

$$sell_2=max(sell_2,buy_2+price[i])$$

```c++

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
```

