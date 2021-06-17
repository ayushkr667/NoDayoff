// Given a binary tree root, invert it so that its left subtree 
// and right subtree are swapped and the children are recursively inverted.

//////////////////////////////////////////////////////////////////////////////

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* soln(Tree* node){
    if( node == NULL )
        return node;

    Tree* l = soln(node->left);
    Tree* r = soln(node->right);

    node->left = r;
    node->right = l;
    return node;
}


Tree* solve(Tree* root) {
    return soln(root);
}
