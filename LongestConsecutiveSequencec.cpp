class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sm, lg;
        range(num, sm, lg);
        int shift = 0;
        if(sm < 0)
            shift = (-1) * sm;
        int i = 0; 
        vector<int> mp(lg-sm+1, -1);
        for(vector<int>::iterator it = num.begin(); it!=num.end(); ++it, i++)
        {
            mp[shift+(*it)] = i;
        }
        int longest = 0;
        int len = 0;
        for(vector<int>::iterator it = mp.begin(); it!=mp.end(); it++)
        {  
            if(*it == -1)
            {
                len = 0;
            }else{
                len++;
            }
            if(len>longest)
                longest = len;
        }
        return longest;
    }
    
    void range(vector<int> &num, int &sm, int &lg)
    {
        sm = 0;
        lg = 0;
        for(vector<int>::iterator it = num.begin(); it!=num.end(); ++it)
        {
            if(*it > lg)
                lg = *it;
            if(*it < sm)
                sm = *it;
        }
    }
};