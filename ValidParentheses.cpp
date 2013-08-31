

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
        while(cur<s.size())
        {
            char curchar = s[cur];
            if(isright(curchar))
            {

    			if(sck.empty())	//Need to return false if the right parenthese is entered when sck is empty, we need to this case on the top because the second case need the stack to be not empty
					return false;

				if(!ispair(sck.top(),curchar))	//Need to check if sck is empty before peek, or the empty stack has been checked and returned if empty
				{
                    return false;
				}

				if(!sck.empty())	//Need to pop in the valid case, cannot be on top of the second case
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
        if(c=='}'||c==']'||c==')')
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
