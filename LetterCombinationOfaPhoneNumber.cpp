
class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		init();
        string buffer = digits;	//the buffer cannot be assigned as 0 length, or it will be out of boundary when building the solution
		letcom(digits, 0, buffer);
        return comstr;
    }
    vector<string> comstr;	//use global so won't need to pass along as parameters
	vector<string> mapstr;

	void init()
	{
		mapstr.push_back("0");	//There's no good way to initialize array of char* or vector of string
		mapstr.push_back("1");
		mapstr.push_back("abc");
		mapstr.push_back("def");
		mapstr.push_back("ghi");
		mapstr.push_back("jkl");
		mapstr.push_back("mno");
		mapstr.push_back("pqrs");
		mapstr.push_back("tuv");
		mapstr.push_back("wxyz");
        comstr.clear();
	}

    //cstring mapstr[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void letcom(string nums, int idx, string& buf)
    {

        if(idx >= nums.size())
        {
            comstr.push_back(buf);
            return;
        }
		if(nums[idx]<'0' || nums[idx]>'9')
            return;
        
        int nm = nums[idx] - '0';	//Standard way to convert from char to number
        string pat = mapstr[nm];
        for(int i = 0; i < pat.size(); i++)
        {
            buf[idx] = pat[i];
            letcom(nums, idx+1, buf);
        }
    }

};
