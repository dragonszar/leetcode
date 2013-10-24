
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = n;
        int cnt = 1;
        int prev = A[0];
		if(n<=2)
			return n;
        for(int i=1; i<n; i++)
        {
			if(i>=len)
				break;
            if(A[i] == prev)
                cnt++;
            else
                cnt = 1;
            
            if(cnt>2)
            {
                eraze(A, i, len);
				i--;
                len--;
            }
            prev = A[i];
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