class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sm, lg;
        range(num, sm, lg);

        int i = 0; 
        map<int, int> mp;   //Need to use map instead of the array due to memory issue, map is automatically sorted when inserting.
        for(vector<int>::iterator it = num.begin(); it!=num.end(); ++it, i++)
        {
            mp[(*it)] = i;
        }
        int longest = 0;
        int len = 0;
        for(map<int, int>::iterator it = next(mp.begin()); it!=mp.end(); it++)
        {  
            if(prev(it)->first != it->first -1) //map's iterator need to use first and second
            {
                len = 1;
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