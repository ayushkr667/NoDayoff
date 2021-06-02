Given the root to a binary tree root, return a list of two numbers where the first number 
is the number of leaves in the tree and the second number is the number of internal (non-leaf) nodes.



/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void calc(Tree* node, int &leaf, int &non){
    if(node == NULL){
        return;
    }
    if(node->right == NULL && node->left == NULL){
        leaf++;
        return;
    }
    else{
        non++;
    }
    calc(node->right, leaf, non);
    calc(node->left, leaf, non);
}

vector<int> solve(Tree* root) {
    int leaf  = 0, non = 0;

    if(root != NULL)
        calc(root, leaf, non);
        
    vector<int> res;
    res.push_back(leaf);
    res.push_back(non);
    return res;
}
