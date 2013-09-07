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
                else{
                    curlen = 0;
                }
            }else{
                credit++;
                curlen++;
            }
            if(curlen > rst)
                rst = curlen;
        }
        rst = rst - credit; //Have unclosed left parenthis
        return rst; //Don't miss return
    }
};