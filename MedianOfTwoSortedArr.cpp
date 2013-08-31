class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0)
            return mid(B, n);
        if(n==0)
            return mid(A, m);
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
            
        int bigarr[big/2], smallarr[small/2];
        cutleft(bigger, big, bigarr);
        cutright(smaller, small, smallarr);
        findMedianSortedArrays(bigarr, big/2, smallarr, small/2);
        
    }
    double mid(int X[], int len)
    {
        if(len<1)
            return 0;
        if(len%2 == 0)
        {
            return (X[len/2] + X[(len/2) -1])/2;
        }
        else
            return X[(len-1)/2];
    }
    void cutleft(int in[], int len, int out[])
    {
        for(int i=len/2, j=0; i< len; i++, j++)
        {
            out[j] = in[i];
        }
    }
    void cutright(int in[], int len, int out[])
    {
        for(int i=0; i< len/2; i++)
        {
            out[i] = in[i];
        }
    }
};