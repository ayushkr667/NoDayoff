//Given a binary tree root, return the sum of all node 
//values whose grandparents have an even value.
  
/////////////////////////////////////////////////////////////////////

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void calc(Tree* node, Tree*par, Tree* gp, int &res){
    if(node == NULL)
        return ;

    if( gp != NULL ){
        if((gp->val)%2 == 0)
            res+= (node->val);
    }

    calc(node->left, node, par, res);
    calc(node->right, node, par, res);
}

int solve(Tree* root) {
    int res = 0;
    calc(root, NULL, NULL, res);
    return res;
}



