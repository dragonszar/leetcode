// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0; 
        int j = matrix.size() - 1;
        int imax = matrix[0].size() - 1;
        int jmin = 0;
        while(i <= imax && j >= jmin)
        {
            if(matrix[j][i] > target)
                j--;
            else if(matrix[j][i] < target)
                i++;
            else if(matrix[j][i] == target)
                return true;
        }
        return false;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> input;
	

	int in0[] = {-10,-8,-6,-4,-3};
	input.push_back(vector<int>(in0, in0+5));
	int in1[] = {0,2,3,4,5};
	input.push_back(vector<int>(in1, in1+5));
	int in2[] = {8,9,10,10,12};
	input.push_back(vector<int>(in2, in2+5));

	Solution s;
	s.searchMatrix(input, 0);
	return 0;
}

