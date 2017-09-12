//https://leetcode.com/problems/linked-list-cycle/description/

#include <iostream>

using namespace std;

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
    bool hasCycle(ListNode *head) {
        ListNode* tmp;
        while(head) {
            if (head->next == head)
                return true;
            if (head->next == NULL)
                return false;

            tmp = head->next;
            head->next = head;
            head = tmp;
        }
        return false;
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}