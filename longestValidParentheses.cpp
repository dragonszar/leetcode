
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == "")
            return 0;
        int credit = 0;
        vector<int> buf(s.size(), 0);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                credit++;
            }else{
                credit--;
                //if(credit < 0)
                    //credit = 0;
            }
            buf[i] = credit;
        }
        vector<int> dif(s.size(), 0);
        for(int i = 0; i < s.size()-1; i++)
        {
            dif[i] = buf[i+1] - buf[i];
        }
        //dif[s.size()-1] = 0;
        vector<int> diff(s.size(), 0);
        for(int i = 1; i < s.size(); i++)
        {
            diff[i] = dif[i-1] - dif[i];
        }
        //diff[0] = 0;
        int peeki = 0, btmi = 0;
        int maxdiff =diff[0], mindiff = diff[0]; 
        for(int i = 1; i < s.size(); i++)
        {
            if(diff[i] > maxdiff)
            {
                maxdiff = diff[i];
                peeki = i;
            }
            if(diff[i] < mindiff)
            {
                mindiff = diff[i];
                btmi = i;
            }           
        }

        return (buf[peeki]-buf[btmi]) * 2; //Don't miss return
    }
};