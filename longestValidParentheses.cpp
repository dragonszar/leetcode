
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rst = 0;
        int credit = 0;
        int curlen = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(credit>0)
                {
                    credit--;
                    curlen++;
                }
                else{   ///extra closing without opening, clear
                    curlen = 0;
                    credit = 0;
                }
                if(credit==0 && curlen > rst)
                    rst = curlen;
                //if(credit>0 && curlen - credit > rst)   ///missing closing, passing ((), but failed on ()(()
                   // rst = curlen - credit;
            }else{
                credit++;
                curlen++;
            }
            /*
            if(credit > 0 && i = s.size() -1)   ///missing closing but no more input, fail on ((()(
            {
                int j = i - 1;
                int foundopening = -1
                while(foundopening < credit)
                {
                    if(s[j] == ')')
                        foundopening--;
                    else
                        foundopening++
                    j--;
                }
                      
            }
            */
        }
        
        if(credit > 0)  ///If there's missing closing but no more input, then do the same process from right to left and select the bigger one to return
        {
            int rstfromright = 0;
            credit = 0;
            curlen = 0;       
            for(int i = s.size() - 1; i >=0 ; i--)   ///Start from right, this is to avoid missing solutions when 
            {
                if(s[i] == '(')
                {
                    if(credit>0)
                    {
                        credit--;
                        curlen++;
                    }
                    else{   
                        curlen = 0;
                        credit = 0;
                    }
                    if(credit==0 && curlen > rstfromright)
                        rstfromright = curlen;

                }else{
                    credit++;
                    curlen++;
                }
            }
            if(rstfromright > rst)
                    rst = rstfromright;
        }


        //rst = rst - credit; //Have unclosed left parenthis
        return rst; //Don't miss return
    }
};