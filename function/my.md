## 位操作

- 将最右位的1变为0

  ```c++
  return n & (n - 1);
  ```

- 获取最低位的1

  ```c++
  return x & (-x);
  ```

  