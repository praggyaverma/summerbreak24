class Solution {
public:
    ListNode* merge2(ListNode* l1, ListNode* l2){
        ListNode* l = new ListNode(-1);
        ListNode* curr = l;

        while (l1 != nullptr && l2 != nullptr){
            if (l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1!=NULL) curr->next = l1; 
        if(l2!=NULL) curr->next = l2;

        return l->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        ListNode* temp = lists[0];

        if(lists.size() > 1){
            for(int i = 1; i < lists.size(); i++){
                temp = merge2(temp, lists[i]);
            }
        }
        return temp; 
    }
};
