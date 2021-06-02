Given a binary tree root, return the sum of all leaves that are right children.



///////////////////////////////////////////////////////////////////////////////////////

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void calc(Tree* node, int &sum){
    if( node == NULL )
        return;

    if(node -> right != NULL)
        if(!node->right->left & !node->right->right)
            sum += node->right->val;

    calc(node->left, sum);
    calc(node->right, sum);
}
int solve(Tree* root) {
    int sum = 0;
    calc(root, sum);
    return sum;
}
