// iterative sol
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = nullptr;
        while (head){
            ListNode* n = head->next;
            head->next = newhead;
            newhead = head;
            head = n;
        }
        return newhead;
    }
};

// recursive sol
class Solution {
    ListNode* reverser(ListNode* head, ListNode* newhead){
        if (!head) return newhead;
        ListNode* n = head->next;
        head->next = newhead;
        newhead = head;
        return reverser(n, newhead);
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = nullptr;
        return reverser(head, newhead);
    }
};
