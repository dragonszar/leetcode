class Solution {
public:
    vector<vector<int> > combine(int n, int k) {

        //if(k < n/2)
            //k = n-k;
        rslt.clear();	//so that one Solution object can make multiple call on multiple inputs, like online judge
        vector<bool> bitmap(n + 1, false);
        slns = &bitmap;	//Since our length of the bitmap is decided by n per each call, we define the bitmap as a pointer which will point to a per-call based local var
        comb(n, k, 0, 1);
        return rslt;
    }
    
    vector<bool> *slns;
    vector<vector<int>> rslt;
    
    void comb(int n, int k, int ki, int stt)	///n is n; k is k; ki is the current # of choice, ki <= k; all integer in [stt, n] will be options for next choice  
    {
        if(ki == k)	///When made all k choices, convert the bit map to a solution and add to solution set
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
            /*if((*slns)[j])
			{
				continue;
			}*/
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