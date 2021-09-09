1.

unordered_map<int, int> hash 哈希表

unordered_map<int, int>::iterator 迭代器 

 

7.

`if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && pop > 7) return 0;`

`if (ans < -INT_MAX / 10 || ans == -INT_MAX / 10 && pop < -8) return 0;`



13.

20.

148.

快慢指针确定链表中点

Merge排序链表

```ListNode* merge(ListNode* l1, ListNode* l2) {
     ListNode dummyHead(0);
     auto p = &dummyHead;
     while (l1 && l2) {
       if (l1->val < l2->val) {
         p->next = l1;
         p = l1;
         l1 = l1->next;
       }
       else {
         p->next = l2;
         p = l2;
         l2 = l2->next;
       }
     }
     p->next = l1 ? l1 : l2;
     return dummyHead.next;
}
```



 

283.

双指针

`stable_sort(nums.begin(), nums.end(), [](int a, int b) {return b == 0; });`



303.

前缀和