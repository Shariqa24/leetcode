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
    bool hasCycle(ListNode *head) {
        ListNode* current=head;
        unordered_set<ListNode*>visited;
        while(current!=NULL){
            if(visited.find(current)!=visited.end()){
                return true;
            }
            visited.insert(current);
            current=current->next;
            }
        return false;
    }
};