/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     void inOrder(TreeNode* root,string &s)
//     {
//         if(root == NULL)
//             return;

//         //find leaf node
//         if(root->right == NULL && root->left == NULL)
//         {
//             s += to_string(root->val) + "_";
//         }

//         inOrder(root->left,s);
//         inOrder(root->right,s);
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         string s1 = "";
//         string s2 = "";

//         inOrder(root1,s1);
//         inOrder(root2,s2);

//         return s1 == s2;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> nodeList_root1, nodeList_root2;
        findLeaf_dfs(root1, nodeList_root1);
        findLeaf_dfs(root2, nodeList_root2);
        return nodeList_root1 == nodeList_root2;
    }

    void findLeaf_dfs(TreeNode* nodeNow, std::vector<int>& nodeList) {
        if (!nodeNow) {
            return;
        }

        if (!nodeNow->left && !nodeNow->right) {
            nodeList.push_back(nodeNow->val);
            return;
        }

        findLeaf_dfs(nodeNow->left, nodeList);
        findLeaf_dfs(nodeNow->right, nodeList);
    }
};
/*
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        def findLeaf_dfs(nodeNow, nodeList):
            if not nodeNow:
                return False
    
            leftExist  = findLeaf_dfs(nodeNow.left, nodeList)
            rightExist = findLeaf_dfs(nodeNow.right, nodeList)

            if not leftExist and not rightExist:
                nodeList.append(nodeNow.val)

            return True
            
        nodeList_root1, nodeList_root2 = [], []
        findLeaf_dfs(root1, nodeList_root1)
        findLeaf_dfs(root2, nodeList_root2)

        if nodeList_root1 == nodeList_root2:
            return True
        else:
            return False
*/