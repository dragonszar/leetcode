class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
            return false;
        stack<char> sck;
        sck.push(s[0]);
        int cur = 1;
        while((!sck.empty()) && cur<s.size())
        {
            char curchar = s[cur];
            if(isright(curchar))
            {
                if(!ispair(sck.top(),curchar))
                    return false;
                sck.pop();
            }
            else if(isleft(curchar))
                sck.push(curchar);
            else
                return false;
            cur++;
        }
        if(cur!=s.size() || !sck.empty())
            return false;
        return true;
    }
    bool isleft(char c)
    {
        if(c=='('||c=='['||c=='{')
            return true;
        return false;
    }
    bool isright(char c)
    {
        if(c=='}'||c=='['||c==')')
            return true;
        return false;
    }
    bool ispair(char l, char r)
    {
        if(l=='(' && r==')')
            return true;
        if(l=='[' && r==']')
            return true;
        if(l=='{' && r=='}')
            return true;
        return false;
    }
};