// both takes O(n) time complexity 

// i). traverse the binary tree  ii).preorder iii) record maximum depth iv). post order 
// class Solution{
// public:
//     int res = 0;
//     int depth = 0;
//     int maxDepth(TreeNode* root){
//         traverse(root);
//         return res;
//     }
//     void traverse(TreeNode* root){
//         if (root == nullptr){
//             return;
//         }
//         depth++;
//         if(root->left == nullptr && root->right == nullptr){
//             res = max(res , depth);
//         }
//         traverse(root->left);
//         traverse(root->right);
//         depth--;
//     }
// };

//  i). recursively calculate the maxdepth of left subtrees and right subtrees and return 1 + max(leftmax , right max ) for each  node 
// class Solution{
// public:
    
//     int maxDepth(TreeNode* root){
//         if (root == nullptr){
//             return 0;
//     }
//         int leftmax = maxDepth(root->left);     // checks 0 for them so maxDepth
//         int rightmax = maxDepth(root->right);

//         return 1 + max(leftmax , rightmax);
//     }
// };