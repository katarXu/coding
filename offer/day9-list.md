#### [回文链表](https://leetcode-cn.com/problems/aMhZSa/)

给定一个链表的 **头节点** `head` **，**请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。



翻转后半段比较

```c++
ListNode *reverseList(ListNode *head){
    ListNode *pre = nullptr, *cur = head, *next;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre =cur;
        cur = next;
    }
    return pre;
}
bool isPalindrome(ListNode* head) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *fast = dummy, *slow = dummy;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *headB = slow->next;
    slow->next = nullptr;
    headB = reverseList(headB);
    fast = head;
    slow = headB;
    while(slow != nullptr){
        if(fast->val != slow->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
```

#### [展平多级双向链表](https://leetcode-cn.com/problems/Qv1Da2/)

多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlist.png)



递归，遇到有子链表的结点时递归调用并返回子链表尾部，将子链表的尾部与当前结点的next结点相连，若无子链表尾部则为链表末尾

```c++
Node* flatten(Node* head) {
	flattenChild(head);
	return head;
}

Node* flattenChild(Node *head) {
	Node *cur = head, *next, *End;
	while (cur != nullptr) {
		next = cur->next;
		if (cur->child != nullptr) {
			Node *childEnd = flattenChild(cur->child);
			cur->child->prev = cur;
			cur->next = cur->child;
			cur->child = nullptr;
			childEnd->next = next;
			if (next) next->prev = childEnd;
			End = childEnd;
		}
		else
			End = cur;
		cur = next;
	}
	return End;
}    
```

#### [排序的循环链表](https://leetcode-cn.com/problems/4ueAj6/)

给定循环升序列表中的一个点，写一个函数向这个列表中插入一个新元素 `insertVal` ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 `null`），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。



先确定真正的开始结点，若当前元素大于插入值，则向后遍历

```c++
Node* insert(Node* head, int insertVal) {
	if (head == nullptr) {
		head = new Node(insertVal);
		return head->next = head;
	}
	Node *start = head;
	while (start->val <= start->next->val) {
		start = start->next;
		if (start == head) break;
	}
	Node *p = start->next, *pre = start;
	while (p->val < insertVal) {
		if (p != start) {
			pre = p;
			p = p->next;
		}
		else break;
	}
	if (p == start && p->val < insertVal) {
		pre = p;
		p = p->next;
	}
	pre->next = new Node(insertVal, p);
	pre->next->next = p;
	return head;
}
```

