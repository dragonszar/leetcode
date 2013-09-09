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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(lists.size()==0)
            return NULL;

        ListNode *rst;
        //ListNode *cur = *(lists.begin());   //Need to add *
        vector<ListNode *>::iterator selected = lists.begin();
        
        while(lists.size()>0){
            for(vector<ListNode *>::iterator it = lists.begin(); it!=lists.end(); ++it)
            {
                if(*it == NULL || (*it)->val==NULL)
                {
                    lists.erase(it);
                    continue;
                }
                    
                if((*it)->val < (*selected)->val)
                {
                    selected = it;
                }
                    
            }
            rst->next = *selected;
            if((*selected)->next!=NULL)
                *selected = (*selected)->next;
            else
                lists.erase(selected);
        }    
        rst = rst->next;
        return rst;
    }
};