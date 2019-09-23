//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while((l1 != NULL) || (l2 != NULL)){
            int val1 = 0, val2 = 0;
            if(l1 != NULL)
                val1 = l1->val;
            if(l2 != NULL)
                val2 = l2->val;

            int value = val1 + val2 + r;
            r = 0;
            if(value >= 10){    // Ïåðåíîñ äåñÿòêà
                value -= 10;
                r = 1;
            }
            ListNode * pos = new ListNode(value);   // Ñîçäàíèå íîâîé ÿ÷åéêè ñïèñêà
            cur->next = pos;    // Óêàçàòåëü íà íîâóþ ÿ÷åéêó
            cur = cur->next;

            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(r != 0){ // Ïåðåíîñ ïîñëåäíåãî äåñÿòêà
            ListNode* pos = new ListNode(r);
            cur->next = pos;
        }
        return head->next;
    }
};
