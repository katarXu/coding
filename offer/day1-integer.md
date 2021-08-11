#### [整数除法](https://leetcode-cn.com/problems/xoh6Oh/)

给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。

 

注意：

- 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
- 假设我们的环境只能存储 32 位有符号整数，其数值范围是$ [−2^{31}, 2^{31}−1]$。本题中，如果除法结果溢出，则返回 $2^{31} − 1$



## 快速幂

```c++
int divide(int a, int b) {
	if (a == 0x80000000 && b == -1)
		return 0x7fffffff;
	if (a == 0x80000000 && b == 1)
		return 0x80000000;
	bool nagetive = (a >= 0) ^ (b >= 0);
	if (a >= 0) a = -a;
	if (b >= 0) b = -b;
	int res = 0, cnt = 1, tmp = b;
	while (tmp > 0xc0000000 && (tmp + tmp) >= a) {
		cnt <<= 1;
		tmp += tmp;
	}
	while (a <= b) {
		a -= tmp;
		res += cnt;
		while (a != 0 && tmp < a) {
			cnt >>= 1;
			tmp >>= 1;
		}
	}
	return nagetive ? -res : res;
}
```



#### [二进制加法](https://leetcode-cn.com/problems/JFETK5/)

给定两个 01 字符串 `a` 和 `b` ，请计算它们的和，并以二进制字符串的形式输出。

输入为 **非空** 字符串且只包含数字 `1` 和 `0`。

## 位运算

```c++
string addBinary(string a, string b) {
	bool carry = 0;
	int i = (int)a.size() - 1;
	int j = (int)b.size() - 1;
	string res;
	while (i >= 0 || j >= 0) {
		bool aa = i >= 0 ? a[i] - '0' : 0;
		bool bb = j >= 0 ? b[j] - '0' : 0;
		bool tmp = aa ^ bb ^ carry;
		carry = (aa & bb) + (aa & carry) + (bb & carry);
		res.push_back(tmp + '0');
		i--, j--;
	}
	if (carry)
		res.push_back('1');
	reverse(res.begin(), res.end());
	return res;
}	
```



#### [前 n 个数字二进制中 1 的个数](https://leetcode-cn.com/problems/w3tCBm/)

给定一个非负整数 `n` ，请计算 `0` 到 `n` 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。



## DP1

$n\&(n-1)$与$n$比，最右一位1变为了0，故可以由此计算1的数目

```c++
vector<int> countBits(int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i) {
        int j = i;
        while(j != 0){
            res[i]++;
            j = j & (j - 1);
        }
	}
	return res;
}
```

显然有递推关系$res[i]=res[i\&(i-1)]+1$

```c++
vector<int> countBits(int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i)
        res[i] = res[i & (i - 1)] + 1;
	return res;
}
```

## DP2

分奇偶讨论即可

```c++
vector<int> countBits(int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i) {
		if ((i & 1) == 1)
			res[i] = res[i - 1] + 1;
		else
			res[i] = res[i >> 1];
	}
	return res;
}
```

也可以写成

```c++
vector<int> countBits(int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i)
		res[i] = res[i >> 1] + (i & 1);
	return res;
}
```

