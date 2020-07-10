/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* ptr = head;
        stack<Node*> st;
        
        while(ptr->next or !st.empty() or ptr->child){
            if(ptr->child){
                st.push(ptr->next);
                ptr->next = ptr->child;
                ptr->child->prev = ptr;
                ptr->child = NULL;
            }
            else if(!ptr->next){
                ptr->next = st.top();
                if(st.top()) st.top()->prev = ptr;
                st.pop();
            }
            if(ptr->next) ptr = ptr->next;
        }
        return head;
    }
};
