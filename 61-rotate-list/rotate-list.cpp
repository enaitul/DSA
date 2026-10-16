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
    int getSize(ListNode* head) {
        int cnt = 0;

        while (head != NULL) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }
    // void printList(ListNode* head) {
    // while (head != NULL) {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
// }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getSize(head);

         if (n <= 1) return head;

        k = k % n;
        while (k--) {
            ListNode* prev = head;
            ListNode* temp = head;
            while (prev->next->next != NULL) {
                prev = prev->next;
            
            }
            temp = prev -> next;
            temp->next = head;
            prev->next = NULL;
            head = temp;
        }
        return head;
        
    }
};