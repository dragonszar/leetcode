class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = n;
        map<int, int> hash;

        for(int i=0; i<n; i++)
        {
			if(i>=len)	//Need this check, since i won't increase when hash[A[i]]+1 > 2 
				break;	
            int tmp = hash[A[i]]+1;	//Need to add 1, so that tmp is the number of times A[i] appears
            if(tmp>2)
            {
                eraze(A, i, len);
				i--;	//After erazing the current A[i] by copying A[i+1] to A[i], the next need to be looped on is still A[i]
                len--;
            }
            hash[A[i]] = tmp;
        }
        return len;    
    }
    void eraze(int input[], int idx, int leng)
    {
        for(int i=idx; i<leng-1; i++)
        {
            input[i] = input[i+1];
        }
        input[leng-1] = NULL;
    }
};