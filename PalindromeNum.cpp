class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ndgt = 0;
        int cur = x;
        while(cur>0)
        {
            ndgt++;
            cur = cur/10;
        }

        if(ndgt==1)
            return true;
        for(int i=1; i <= (ndgt+1)/2; i++)
        {
            if(((x/(ndgt-i))%10) != ((x%10)/(10^(i-1))))
                return false; 
        }
        return true;
    }
    
    
};