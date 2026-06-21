/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mpp;

        Node* curr=head;
        Node* temp=NULL;
        Node* prev=NULL;
        Node* newhead=NULL;

        while(curr){
                Node* newnode = new Node(curr->val);
                mpp[curr]=newnode;
                if(prev==NULL){
                    prev=newnode;
                    newhead=prev;
                }
                else{
                    prev->next=newnode;
                    prev=newnode;
                }
            curr=curr->next;
        }  

        curr=head;
        temp=newhead;
        while(curr){
            temp->random=mpp[curr->random];
            curr=curr->next;
            temp=temp->next;
        } 

        return newhead;     
    }
};
