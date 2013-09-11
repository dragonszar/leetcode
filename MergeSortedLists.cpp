
class Solution {
public:
    class Comp
    {
        public:
            bool operator()(const ListNode *st, const ListNode *ed) const
            {
                return (st->val - ed->val > 0); 
            }
    };


    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<ListNode*>::iterator it = lists.begin();
    	while(it != lists.end()) {                      //Must remove the NULL element first
			if(*it == NULL) lists.erase(it);
			else ++it;
		}
        
        if(lists.size() < 1) return NULL;       //Need to check after removing NULL element
        
        ListNode *head = NULL;
        ListNode *cur = NULL;
		vector<ListNode *>::iterator itst = lists.begin();
		vector<ListNode *>::iterator ited = lists.end();
        priority_queue<ListNode *, vector<ListNode *>, Comp> pq(itst, ited, Comp());    //Standard way to construct a priority queue from a vector
        
        while(pq.size() > 0)
        {
            if(head == NULL)
            {
                head = pq.top();
                cur = head;
            }
            else{
                cur->next = pq.top();	//pop() will return void
                cur = cur->next;  
            }
            pq.pop();	//Pop and re-insert to realize the increase key
            if(cur->next!=NULL)
                pq.push(cur->next);	//Need to push in the next node of the popped node
        }
		cur->next = NULL;
        return head;
    }

};