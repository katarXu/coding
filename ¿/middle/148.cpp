#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x7ffff
using namespace std;

/*
void moveZeroes(vector<int>& nums) {
	stable_sort(nums.begin(), nums.end(), [](int a, int b) {return b == 0; });
}
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == nullptr)
			return head;
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode* fast = head, *slow = head;
		while (fast != tail) {
			fast = fast->next;
			slow = slow->next;
			if (fast != tail)
				fast = fast->next;
		}
		return merge(sortList(head, slow), sortList(slow, tail));
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
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
};
int main() {
	system("pause");	

}