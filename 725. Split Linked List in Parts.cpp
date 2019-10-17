//https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *temp = root;
        int listLen = 0;
        while(temp){
            listLen++;
            temp = temp->next;
            }
        vector<int> nNodes(k,listLen / k);
        int remain = listLen % k;
        for(int i=0; i < remain; i++) 
            nNodes[i] += 1;
        vector<ListNode*> result(k, NULL);
        
        for(int i = 0; i < k; i++){
            temp = root;
            result[i] = temp;
            if(temp){
                for(int j = 0; j < nNodes[i] - 1; j++){
                    temp = temp->next;
                }
                root = temp->next;
                temp->next = NULL;

            }
        }
        return result;
    }
};