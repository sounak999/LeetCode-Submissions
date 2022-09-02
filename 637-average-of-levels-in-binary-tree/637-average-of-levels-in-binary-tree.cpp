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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        // while there are nodes remaining to be visited
        while(!q.empty())
        {
            double size = q.size();
            double sum = 0;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();
                sum += (frontNode->val);
                
                if(frontNode->left)
                    q.push(frontNode->left);
                
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            
            res.push_back(sum/size);
        }
        
        return res;
    }
};