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
    	string pat = "";
		int patlen = 0;
        for(int i = 0; i<s.size(); i++)
        {
			
            if(hash[s[i]])
            {
				patlen = pat.find_first_of(s[i]);
				len = len - patlen;	//Within the pattern the chars before last occurance of s[i] will be discarded, both in hash and pat
				for(int i=0; i<patlen; i++)
					hash.erase(pat[i]);	//Need to clear the hash
				pat = pat.substr(patlen+1);	//Need to update the pattern, don't miss adding one
				pat.append(1, s[i]);

            }
            else{
                hash[s[i]] = 1;//Cannot assigned to i, since i can be 0, and we rely on hash['x']==0 to decide if 'x' hasn't been inserted 
				pat.append(1, s[i]);
				len++;
            }
            if(len>maxlen)
                maxlen = len;
        }
        return maxlen;
    }
};