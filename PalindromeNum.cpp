class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ndgt = 0;
        int cur = x;
        
        //Handle minus number case
        if(cur<0)
            return false;
        
        while(cur>0)
        {
            ndgt++;
            cur = cur/10;
        }

        if(ndgt==1) //Handle 1 dgit case
            return true;
        for(int i=1; i <= (ndgt+1)/2; i++)
        {
            if(
                (
                    ( x / pow(10, (ndgt-i)) ) % 10
                ) != (
                    (x % pow(10, i)) / pow(10, (i-1)) //Watch the cao gao carefully
                )
            )
                return false; 
        }
        return true;
    }
    
    //"^" is not power sign
    int pow(int a, int b)
    {
        int rst = 1;
        for(int i=0; i < b; i++)
        {
            rst = rst * a;
        }
        return rst;
    }
    
};