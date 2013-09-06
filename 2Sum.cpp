// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> buf(numbers);
        sort(numbers.begin(), numbers.end());
        int stt = 0;
        int end = numbers.size()-1;
        for(int i=0; i<numbers.size(); i++)
        {
            if(numbers[i]>=target-numbers[numbers.size()-1])
            {
                stt = i;   
                break;
            }
        }
        for(int i = numbers.size()-1; i >= 0; i-- )
        {
            if(numbers[i] <= target-numbers[0])
            {
                end = i;
                break;
            }
        }
        int low, high;
        for(int i = stt, j = end; i<j;)
        {
            if(numbers[i] + numbers[j] < target)
                i++;
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
            {
                low = numbers[i];
                high = numbers[j];
				break;	//Don't miss the break, or it will be looping forever
            }
        }
        vector<int> rst;
		int ilow = distance(buf.begin(), find(buf.begin(), buf.end(), low)) + 1;

		reverse_iterator<vector<int>::iterator> rev_begin (buf.end());	//Reverse pointer
		reverse_iterator<vector<int>::iterator> rev_end (buf.begin());

		int ihigh = distance(rev_end, find(rev_begin, rev_end, high))*(-1);	//The standard cpp way to find last
		if(ilow<ihigh)	//Need to push the smaller index first, pay attention to the request
		{
			rst.push_back(ilow);
			rst.push_back(ihigh);
		}
		else{
			rst.push_back(ihigh);
			rst.push_back(ilow);
		}

        return rst;
    }
};



int _tmain(int argc, _TCHAR* argv[])
{
	int test[] = {4,2,9,1,4,56,90,3, 0, 0, 0,0,0};
	vector<int> tst;
	vector<int> rst;
	tst.assign(test, test+sizeof(test)/sizeof(int));	//Pointer can be treated as iterator
	Solution s;
	rst = s.twoSum(tst, 8);

	return 0;
}

