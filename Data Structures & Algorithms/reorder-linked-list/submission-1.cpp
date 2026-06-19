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

    ListNode* reverse(ListNode* head){

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp=NULL;

        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;


    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* second=reverse(slow->next);
        slow->next=NULL;
         ListNode* first=head;
        while(second!=NULL){
           ListNode* t1=first->next;
           ListNode* t2=second->next;
           
           first->next=second;
           second->next=t1;
           first=t1;
           second=t2;

        }


        
    }
};
