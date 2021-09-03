## unity

### algorithm

```c++
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);
//二分查找[first, last)中第一个大于等于num的数字
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);
//二分查找[first, last)中第一个大于num的数字
ForwardIterator max_element (ForwardIterator first, ForwardIterator last,
                               Compare comp);
//返回[first, last)中最大的元素
typename iterator_traits<InputIterator>::difference_type
    count (InputIterator first, InputIterator last, const T& val);
//返回[first, last)中val出现的次数
```

### numeric	求和

```c++
OutputIterator partial_sum (InputIterator first, InputIterator last,
                               OutputIterator result, BinaryOperation binary_op);
//对[first, last)间的元素从头开始进行binary_op运算，结果存储到result中
```

### iterator	迭代器

```c++
typename iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last);
//返回迭代器间的距离
void advance (InputIterator& it, Distance n);
//将迭代器it前进n位
back_insert_iterator<Container> back_inserter (Container& x);
//创建一个使用push_back插入的迭代器
front_insert_iterator<Container> front_inserter (Container& x);
//创建一个使用push_front插入的迭代器
insert_iterator<Container> inserter (Container& x, Iterator it);
//创建一个插入到it前的迭代器
```

### random 随机数

```c++
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib(start, end);

int random_num = distrib(gen);	//call
```



## vector

## queue


