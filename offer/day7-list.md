#### [删除链表的倒数第 n 个结点](https://leetcode-cn.com/problems/SLwz0R/)

给定一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。



### 遍历两次 or 快慢指针

```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *tmp = new ListNode(-1, head);
    ListNode *fast = tmp, *slow = tmp;
    for(int i = 0; i < n; ++i)
        fast = fast-> next;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    head = tmp->next;
    return head;
}
```

#### [链表中环的入口节点](https://leetcode-cn.com/problems/c32eOV/)

给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 `next` 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 `null`。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意，`pos` 仅仅是用于标识环的情况，并不会作为参数传递到函数中。**



### 快慢指针

若快慢指针相遇则有环（floyd判环法）

设表头到环入口距离a，还入口到相遇点距离b，相遇点回到环入口距离c

则有$2(a+b+n(b+c))=a+b+m(b+c)$，其中m、n是快慢指针走的环数

整理得$a=(m-2n-1)(b+c)+c$，也就是从表头到环入口的距离正好是相遇点到环入口的距离加上若干个环，故新快慢指针必会在环入口处相遇

```c++
ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode *slow = head->next, *fast = slow->next;
    while(slow != fast){
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;        
}
```

#### [两个链表的第一个重合节点](https://leetcode-cn.com/problems/3u1WK4/)

给定两个单链表的头节点 `headA` 和 `headB` ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。

题目数据 **保证** 整个链式结构中不存在环。



### 哈希

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> mp;
    for(ListNode *p = headA; p != nullptr; p = p->next)
        mp[p] = true;
    for(ListNode *p = headB; p != nullptr; p = p->next)
        if(mp[p]) return p;
    return nullptr;
}
```

### 双指针

- 链表存在交点的情况：若两链表长度相同，那么两个指针会在移动的过程中相遇;但是若两个链表长度不相同，则它们第一次遍历无法相遇。继续规定第一个指针遍历完第一个链表后遍历第二个链表，第二个指针遍历完第二个链表后遍历第一个链表，如此肯定能保证两个指针到达交点的路程相同，则它们会相遇。

- 链表无交点的情况：若两个链表长度相同，则两个指针遍历完各自的链表，最后同时指向 nullptr 可以判断不存在交点。若两个链表长度不相同，则两个指针遍历完各自的链表遍历另一个链表，最后也会同时指向 nullptr 可以判断不存在交点。

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* p1 = headA, p2 = headB;
	while (p1 != p2) {
		p1 = (p1 == nullptr) ? headB : p1->next;
		p2 = (p2 == nullptr) ? headA : p2->next;
	}
	return p1;
}
```

