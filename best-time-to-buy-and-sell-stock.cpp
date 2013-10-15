class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if(prices.size() == 0)
            return 0;
        priority_queue<pair<int, int>,vector<pair<int, int>>, Comp> trans;
        int low = prices[0];
        int high = low;
        for(vector<int>::iterator itr = prices.begin()+1; itr!= prices.end(); itr++)
        {
            if(*itr < low)
            {
                if(high > low)
                {
                    trans.push(make_pair(low, high));
                }
                low = *itr;
                high = low;	//High need to be reset to low when a ever lower point is assigned to low
            }
            else if (*itr < high)
                continue;
            else if (*itr > high)
                high = *itr;
        }
        if(high > low)	//Don't forget to save potential solution when looping ends
            trans.push(make_pair(low, high));
        if(trans.size()!=0)
            return trans.top().second - trans.top().first;
        else
            return 0;
        
    }
    class Comp
    {
        public:
            bool operator()(const pair<int, int> &a, const pair<int, int> &b)
            {
                return (a.second - a.first) < (b.second - b.first);
            }
    };
};