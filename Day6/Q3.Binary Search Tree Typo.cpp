//You are given a binary tree root which is almost a binary search tree except two nodes'
//values have been swapped. Return the original binary search tree.

////////////////////////////////////////////////////////////////////////////////////////////



/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
Tree* a; Tree* b; Tree* c;
int occur;
 //in order is sorted
void calc(vector<Tree*>&values, Tree* node){
    if(node == NULL)
        return;

    calc(values, node->left); //left

    if( values.empty() ){
        values.push_back(node); //root
    }
    else{
        if( (values.back()->val) > node->val ){
            if(occur == 0){
                a = values.back();
                b = node;
                occur++;
            }
            else{
                c = node;
            }
        }
        values.push_back(node);
    }

    calc(values, node->right); //right
}

Tree* solve(Tree* root) {

    a = b = c = NULL;
    occur = 0;

    vector<Tree*> values;

    calc(values, root);

    if( c == NULL ){
        //two swapped are adjacent
        swap( a->val, b->val );
    }

    else{
        swap( a->val, c->val );
    }

    return root;
}

