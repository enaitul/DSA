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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next){
            return {-1, -1};
        }
        int mindist = INT_MAX;
        int currindex = 1;
        int previndex = -1;
        int firstindex = -1;
        ListNode *prev = head;
        ListNode *curr = head -> next;

        while (curr -> next !=NULL){
            ListNode *nextnode = curr -> next;

            bool islocalmax = (prev -> val < curr -> val) && (nextnode -> val < curr -> val);
            bool islocalmin = (prev -> val > curr -> val) && (nextnode -> val > curr -> val);

            if (islocalmax || islocalmin){
                if (firstindex == -1){
                    firstindex = currindex;
                }
                else{
                    mindist = min (mindist, currindex - previndex);
                }
                previndex = currindex;

                
            }
            prev = curr;
                curr = nextnode;
                currindex++;
            
        }
        if (firstindex == -1 || firstindex == previndex){
                return {-1,-1};
            }

            int maxdist = previndex - firstindex;
            return {mindist, maxdist};
    }
};