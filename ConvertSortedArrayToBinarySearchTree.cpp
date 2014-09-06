class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(num.size()<=0)
            return NULL;
        if(num.size()<=1)
            return new TreeNode(num[0]);
        int mid = num.size()/2;
        TreeNode* self = new TreeNode(num[mid]);
        vector<int> tmp1(num.begin(), num.begin()+mid);
        self->left = sortedArrayToBST(tmp1);
        vector<int> tmp2(num.begin()+mid, num.end());
        self->right = sortedArrayToBST(tmp2);
        return self;
    }
    
};