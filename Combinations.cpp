class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //if(k < n/2)
            //k = n-k;
        rslt.clear();	//so that one Solution object can make multiple call on multiple inputs, like online judge
        vector<bool> bitmap(n + 1, false);
        slns = &bitmap;
        comb(n, k, 0, 1);
        return rslt;
    }
    
    vector<bool> *slns;
    vector<vector<int>> rslt;
    
    void comb(int n, int k, int ki, int stt)
    {
        if(ki == k)
        {
            vector<int> rst;
            for(int i = 1; i <= n; i++)
            {
                if((*slns)[i])
                    rst.push_back(i);
            }
            rslt.push_back(rst);    //push_back is to copy, no need to worry if the copied is not a pointer
            //reset();              //should not clear all bit, should only clear the bit selected in the returned round of selection
            return;
        }

        for(int j = stt; j <= n; j++ )
        {
            if((*slns)[j])
			{
				continue;
			}
            (*slns)[j] = true;
            comb(n, k, ki + 1, ++stt);	//++stt is the key point!!
            (*slns)[j] = false;		//Only reset the bit when visited
        }

    }
    /*
    void reset()
    {
        for(vector<bool>::iterator it = slns->begin(); it !=  slns->end(); ++it)
        {
            *it = false;
        }
    }
	*/
};