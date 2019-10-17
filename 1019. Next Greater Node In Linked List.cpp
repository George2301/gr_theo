//https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        if(head && head->next){
            while(head->next){
                int max = head->val;
                ListNode* tmp = head->next;
                while(tmp){
                    if (tmp->val > max){
                        max = tmp->val;
                        break;
                    }
                    tmp = tmp->next;
                }
                if (max > head->val){
                    result.push_back(max);
                } else {
                    result.push_back(0);
                }
                tmp = head->next;
                head = head->next;
            }
            result.push_back(0);
        } else if(head) {
            result.push_back(0);
        } 
        return result;
    }
};