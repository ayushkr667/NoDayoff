//Given a binary tree root return a level order traversal of the node values

////////////////////////////////////////////////////////////////////////////////

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void calc(Tree* node, vector<int>& res){
    queue<Tree*>q;
    q.push(node);
    while(!q.empty()){
        Tree* temp = q.front();
        res.push_back(temp->val);
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
vector<int> solve(Tree* root) {
    vector<int> res;
    calc(root, res);
    return res;
}
