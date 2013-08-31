
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0&&n!=0)
            return mid(B, n);
        if(n==0&&m!=0)
            return mid(A, m);
		if(m==1&&n==1)
			return ((double)A[0] + (double)B[0])/2;
        int midA = mid(A, m);
        int midB = mid(B, n);
        int* bigger;
        int* smaller; 
        int big, small;
        if(midA>midB)
        {
            bigger = A;
            big = m;
            smaller = B;
            small = n;
        }
        else
        {
            bigger = B;
            big = n;
            smaller = A;
            small = m;
        }
        
        int bigarr[1000], smallarr[1000];
        cutleft(bigger, big, bigarr);
        cutright(smaller, small, smallarr);
        return findMedianSortedArrays(bigarr, big/2, smallarr, small/2);	//DON'T MISS THE RETURN
        
    }



    double mid(int X[], int len)
    {
        if(len<1)
            return 0;
		if(len==0)
			return X[0];
        if(len%2 == 0)
        {
            return ((double)X[len/2] + (double)X[(len/2) -1])/2;    //Need to convert to double before averaging.
        }
        else
            return X[(len-1)/2];
    }
    void cutleft(int in[], int len, int out[])
    {
        for(int i=(len/2), j=0; i< len; i++, j++)
        {
            out[j] = in[i];
        }
    }
    void cutright(int in[], int len, int out[])
    {
		if(len==1)
		{
			out[0] = in[0];
			return;
		}
        for(int i=0; i< len/2; i++)
        {
            out[i] = in[i];
        }
    }
};