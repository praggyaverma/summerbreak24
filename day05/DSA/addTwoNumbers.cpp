class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x, y, s, c = 0;

        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        while (l1 != nullptr || l2 != nullptr){
            if (!l1) x = 0;
            else x = l1->val;
            if (!l2) y = 0;
            else y = l2->val;
            s = (x + y + c) % 10;
            c = (x + y + c) / 10;

            curr->next = new ListNode(s);
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (c > 0){
            curr->next = new ListNode(c);
        }
        return result->next;
    }
};
