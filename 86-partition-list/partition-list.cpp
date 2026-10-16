class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(-1);
        ListNode* head2 = new ListNode(-1);

        ListNode* small = head1;
        ListNode* large = head2;

        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val < x) {
                small->next = temp;
                small = small->next;
            } else {
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }

        large->next = NULL;
        small->next = head2->next;

        return head1->next;
    }
};