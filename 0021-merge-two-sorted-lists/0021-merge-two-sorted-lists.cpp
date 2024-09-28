class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(10000); 
        ListNode* point = dummy;

        ListNode* tempA = list1;
        ListNode* tempB = list2;

        while(tempA != NULL && tempB != NULL){
            if(tempA->val <= tempB->val){
                point->next = tempA;
                tempA = tempA->next;
            } else {
                point->next = tempB;
                tempB = tempB->next;
            }
            point = point->next;
        }

        if(tempA != NULL){
            point->next = tempA;
        } else if(tempB != NULL){
            point->next = tempB;
        }

        return dummy->next; 
    }
};