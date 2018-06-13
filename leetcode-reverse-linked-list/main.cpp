#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        std::vector<int> buffer;
        ListNode* iter = head;
        while (iter) {
            buffer.push_back(iter->val);
            iter = iter->next;
        }

        iter = head;
        while(iter) {
            iter->val = buffer.back();
            buffer.pop_back();
            iter = iter->next;
        }

        return head;
    }
};

void printList(struct ListNode* n) {
    while (n) {1
        std::cout << n->val << std::endl;
        n = n->next;
    }
}

int main() {
    Solution s;

    ListNode N1 {1};
    ListNode N2 {2};
    ListNode N3 {3};
    ListNode N4 {4};
    ListNode N5 {5};

    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;

    s.reverseList(&N1);
    printList(&N1);
    return 0;
}