class Solution {
public:
    void reorderList(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list
        ListNode* second = slow->next;
        slow->next = NULL;

        // Step 3: Reverse second half
        ListNode* prev = NULL;

        while (second != NULL) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        second = prev;

        // Step 4: Merge both halves
        ListNode* first = head;

        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};