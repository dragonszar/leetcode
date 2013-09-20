class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(S.begin(), S.end(), compar());
        
        return subsets_rec(S);
    }
    
    vector<vector<int> > subsets_rec(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(S.size()==0) //Need to create a local to return
        {   
            vector<int> empt;
            vector<vector<int>> empts;
            empts.push_back(empt);
            return empts;
        }
        
          
        int frst =  S[0];
        S.erase(S.begin());
        vector<vector<int>> rtns = subsets(S);
        vector<vector<int>> rtnscpy =  rtns;	//Cannot directly loop on rtns, since pushing to rtns will invalidate the iterator
        for(vector<vector<int>>::iterator it = rtnscpy.begin(); it!=rtnscpy.end(); ++it)
        {
            vector<int> newadd = *it;
            newadd.push_back(frst);
            rtns.push_back(newadd);
        }
        return rtns;
    }    

    class compar {
	public:	//Need the public modifier
		bool operator() (int i,int j) { return (i>j);}
    };

};