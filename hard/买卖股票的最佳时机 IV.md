#### [买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

## 动态规划

$buy[i][j]$ := 第$i$天时，进行了$j$次交易且手中持有股票的最大利润

$sell[i][j]$ := 第$i$天时，进行了$j$次交易且手中不持有股票的最大利润

状态转移方程：

> $buy[i][j]=\max(buy[i-1][j],sell[i-1][j]-prices[i])$
>
> $sell[i][j]=\max(sell[i-1][j],buy[i-1][j-1]+prices[i])$

考虑边界情况：

​	$i = 0$时，只有$buy[0][0]、sell[0][0]$是合法状态，此时$buy[0][0]=-prices[0],sell[0][0]=0$，对$buy[0][j]、sell[0][j],1\le j\le n$，均为不合法状态，可设置为$INT\_MIN/2$，防止溢出

​	$j =0$时，$buy[i][0]=\max(buy[i-1][0],-prices[i]),sell[i][0]=0$

```c++
int maxProfit(int k, vector<int>& prices) {
	int n = (int)prices.size();
    if(!n || !k) return 0;
    vector<vector<int>> buy(n, vector<int>(k + 1));
    vector<vector<int>> sell(n, vector<int>(k + 1));
    buy[0][0] = -prices[0];
    for(int i = 1; i <= k; ++i)
        buy[0][i] = sell[0][i] = INT_MIN / 2;
    for(int i = 1; i < n; ++i){
        buy[i][0] = max(buy[i - 1][0], -prices[i]);
        for(int j = 1; j <= k; ++j){
			buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
    	    sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        }
    }
    return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}
```

### 优化

- 可以看到第$i$天状态只和$i-1$天有关，故可以将二维数组优化为一维

  >$buy[i]=\max(buy[i-1],sell[i-1]-prices[i])$
  >
  >$sell[i]=\max(sell[i-1],buy[i-1]+prices[i])$

- 有收益的交易必然需要消耗大于等于两天，故可以取$k^\prime = \max(k,n/2)$

```c++
int maxProfit(int k, vector<int>& prices) {
	int n = (int)prices.size();
    if(!n || !k) return 0;
    k = min(k, n / 2);
    vector<int> buy(k + 1);
    vector<int> sell(k + 1);
    buy[0] = -prices[0];
    for(int i = 1; i <= k; ++i)
        buy[i] = sell[i] = INT_MIN / 2;
    for(int i = 1; i < n; ++i){
        buy[0] = max(buy[0], -prices[i]);
        for(int j = 1; j <= k; ++j){
            //这里buy、sell的更新顺序对结果无影响，相当于当天买当天卖
			buy[j] = max(buy[j], sell[j] - prices[i]);
    	    sell[j] = max(sell[j], buy[j - 1] + prices[i]);
        }
    }
    return *max_element(sell.begin(), sell.end());
}
```



## wqs二分

考虑图像交易次数与最大利润的图像$(k,g_k)$，显然该图像是上凸的

![188-1.png](https://pic.leetcode-cn.com/1608989504-mwUFxM-188-1.png)

当$k$处于左半段时，问题即是求当恰好交易$k$次时$g_k$的值；当$k$处于右半段时，此时达到最大利润无需交易$k$次，因此直接贪心即可

考虑第一种情况，当我们枚举斜率$c$时，与函数的切线记为$f-g_k=c(x-k)$，与纵轴的交点即为$g_k-ck$，可以视为每笔交易需要$c$的手续费时的最大利润，且切线时取到最大值，由于函数图像是上凹的，故$c$越小，取到的$k$越大，于是我们可以采用二分斜率$c$的方法，找到对应的$k$

考虑这个子问题**每笔交易需要$c$的手续费时的最大利润**

有前面的基础，我们很容易列出递推关系：

$buy = \max(buy,sell-prices[i])$

$sell=\max(sell,buy+prices[i]-c)$

```c++
int maxProfit(vector<int>& prices, int fee) {
    int n = (int)prices.size();
    int sell = 0, buy = -prices[0], cnt = 0;
    for (int i = 1; i < n; ++i) {
        buy = max(buy, sell - prices[i]);
        sell = max(sell, buy + prices[i] - fee);
    }
    return sell;
}
```

另一种贪心的思路是记录当前买入的最低值，买入时考虑手续费，在卖出时不考虑手续费

```c++
int maxProfit(vector<int>& prices, int fee) {
    int n = (int)prices.size();
    int buy = prices[0] + fee;
    int profit = 0;
    for (int i = 1; i < n; ++i) {
        if(buy > prices[i] + fee)
            buy = prices[i] + fee;
        else if(buy < prices[i]){
            profit += prices[i] - buy;
            buy = prices[i];
        }
    }
    return profit;
}
```

故总代码如下：

```c++
int maxProfit(int k, vector<int>& prices) {
	int n = (int)prices.size();
    if(!n || !k) return 0;
    int left = 0, right = *max_element(prices.begin(), prices.end());
    int res = 0;
    while(left <= right){
        int fee = (left + right) / 2;
    	int sell = 0, buy = -prices[0];
        int buyCnt = 0, sellCnt = 0;
        
    	for (int i = 1; i < n; ++i) {
    	    if(buy <= sell - prices[i]){
                buyCnt = sellCnt;
                buy = sell - prices[i];
            }
    	    if(sell <= buy + prices[i] - fee){
                sellCnt = buyCnt + 1;
    	        sell = buy + prices[i] - fee;
    	    }
    	}
        if(sellCnt >= k){
            res = sell + fee * k;
            left = fee + 1;
        }
        else
            right = fee - 1;
    }
    
    if(res == 0)
        for(int i = 1; i < n; ++i)
            res += max(0, prices[i] - prices[i - 1]);
    
    return res;
}
```

