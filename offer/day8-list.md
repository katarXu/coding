#### [反转链表](https://leetcode-cn.com/problems/UHnkqh/)

给定单链表的头节点 `head` ，请反转链表，并返回反转后的链表的头节点。



```c++
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head, *next;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
```

#### [链表中的两数相加](https://leetcode-cn.com/problems/lMSNwu/)

给定两个 **非空链表** `l1`和 `l2` 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

### 翻转链表

翻转后相加再翻转回来即可

```c++
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head, *next;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
	l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode *p1 = l1, *p2 = l2;
    bool carry = false;
    while(p2 != nullptr || carry){
		p1->val += (p2 == nullptr ? 0 : p2->val) + carry;
        if(p1->val >= 10){
            p1->val -= 10;
            carry = true;
        }
        else carry = false;
        p2 == nullptr ? 0 : p2 = p2->next;
        if(p1->next == nullptr && (p2 != nullptr || carry))
            p1->next = new ListNode(0);
        p1 = p1->next;
    }
    return reverseList(l1);
}
```

若要求不能翻转链表则考虑用栈来处理



#### [重排链表](https://leetcode-cn.com/problems/LGjMqU/)

给定一个单链表 `L` 的头节点 `head` ，单链表 `L` 表示为：

` L0 → L1 → … → Ln-1 → Ln `
请将其重新排列后变为：

`L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …`

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



翻转后半段链表后重排即可

```c++
ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head, *next;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void reorderList(ListNode* head) {
    ListNode *tmp = new ListNode(-1, head);
    ListNode *slow = tmp, *fast = tmp, *next;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *headB = slow->next;
    slow->next = nullptr;
    headB = reverseList(headB);
    slow = head;
    fast = headB;
    while(fast != nullptr){
        next = slow->next;
        slow->next = fast;
        fast->next = slow->next;
        slow = fast->next;
        fast = next;
    }
    delete tmp;
}
```

