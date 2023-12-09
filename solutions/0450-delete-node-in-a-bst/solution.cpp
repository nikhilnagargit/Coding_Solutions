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
    pair<TreeNode*,TreeNode*> search(TreeNode* root,TreeNode* parent, int key){
        if(!root)return {nullptr,nullptr};
        if(root->val==key) return {root,parent};
        if(root->val<key) return search(root->right,root,key);
        return search(root->left,root,key);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        pair<TreeNode*,TreeNode*> p = search(root,nullptr,key);
        TreeNode* node = p.first;
        TreeNode* parent_of_node = p.second;
        if(!node) return root;

        // if node is root of the tree
        if(!parent_of_node){
            if(!node->right and !node->left) return nullptr;

            if(node->right and !node->left){
                return node->right;
            }
            if(node->left and !node->right){
                return node->left;
            }
            TreeNode* leftsubtree = root->left;
            TreeNode* newroot = root->right;
            TreeNode* newroot_left_subtree = root->right->left;
            root->right->left = leftsubtree;
            TreeNode* temp = leftsubtree;
            while(temp->right!=nullptr){
                temp  = temp->right;
            }
            temp->right = newroot_left_subtree;
            return newroot;
        }

        // if node has no child;
        if(!node->right and !node->left){
            if(parent_of_node->val<key){
                parent_of_node->right = nullptr;
                return root;
            }
        }
        // if node has both child;
        if(node->right and node->left){
            if(parent_of_node->val<key){
                parent_of_node->right = node->left;
                TreeNode* node_left_child_right = node->left->right;
                node->left->right = node->right;
                TreeNode* temp = node->right;
                while(temp->left!=nullptr){
                    temp = temp->left;
                }
                temp->left = node_left_child_right;
                return root;
            }
            else{
                parent_of_node->left = node->right;
                TreeNode* node_right_child_left = node->right->left;
                node->right->left = node->left;
                TreeNode* temp = node->left;
                while(temp->right!=nullptr){
                    temp = temp->right;
                }
                temp->right = node_right_child_left;
                return root;
            }
        }
        // if node has left child
        if(node->left){
            if(parent_of_node->val>key){
                parent_of_node->left = node->left;
            }
            else{
                parent_of_node->right = node->left;
            }
            return root;
        }
        // if node has right child
        else{
            if(parent_of_node->val>key){
                parent_of_node->left = node->right;
            }
            else{
                parent_of_node->right = node->right;
            }
            return root;
        }
    }
};
