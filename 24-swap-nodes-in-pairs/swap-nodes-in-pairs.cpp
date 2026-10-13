/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //ekta temp node banacchi jeta point korbe original head ke
        ListNode* temp = new ListNode(0);
        temp -> next = head;

        ListNode* prev = temp;

        while(prev -> next != nullptr && prev->next->next != nullptr){
            ListNode* first = prev->next;
            ListNode* second = first->next;

            prev -> next = second;

            first->next = second->next;

            second->next = first;

            prev = first;
        }

        ListNode* newHead = temp->next;

        delete temp;
        return newHead;
    }
};