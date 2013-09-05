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
                j++;
            else
            {
                low = numbers[i];
                high = numbers[j];
            }
        }
        vector<int> rst;
        rst.push_back(distance(buf.begin(), find(buf.begin(), buf.end(), low)));
        rst.push_back(distance(buf.begin(), find(buf.begin(), buf.end(), high)));
        return rst;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int test[] = {2,1,9,4,4,56,90,3};
	vector<int> tst;
	vector<int> rst;
	tst.assign(test, test+sizeof(test)/sizeof(int));
	Solution s;
	rst = s.twoSum(tst, 8);

	return 0;
}

