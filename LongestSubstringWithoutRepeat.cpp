class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
            return 0;
        map<char, int> hash;
        int maxlen = 0;
        int len = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(hash[s[i]])
            {
                //len = 1;
            }
            else{
                len++;
                hash[s[i]] = 1; //Cannot assigned to i, since i can be 0, and we rely on hash['x']==0 to decide if 'x' hasn't been inserted 
            }
            if(len>maxlen)
                maxlen = len;
        }
        return maxlen;
    }
};