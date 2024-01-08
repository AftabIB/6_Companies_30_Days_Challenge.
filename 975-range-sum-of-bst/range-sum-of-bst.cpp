class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, &sum, low, high);
        return sum; 
    }
    void inorder(TreeNode* root, int* sum, int low, int high)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->val > low)
            inorder(root->left, sum, low, high);
        if(root->val >= low && root->val <= high)
            *sum += root->val;
        if(root->val < high)
            inorder(root->right, sum, low, high);
    }
};
