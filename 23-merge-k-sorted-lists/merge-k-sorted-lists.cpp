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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (true){
            int minindex = -1;
            int smallest = INT_MAX;

            for (int i = 0; i < lists.size(); i++){
                if (lists[i] != NULL && lists[i]->val < smallest){
                    smallest = lists[i] -> val;
                    minindex = i;
                }
            }

            if (minindex == -1) break; //list is empty

            ListNode* node = lists[minindex];

            lists[minindex] = lists[minindex] -> next; //in which ever list we are in rn, we advance in that list

            tail -> next = node;
            tail = tail -> next;
        }

        return dummy -> next;
    }
};