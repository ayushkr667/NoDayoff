//Given a singly linked list node whose values are integers, 
//determine whether the linked list forms a palindrome.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool solve(LLNode* node) {
    LLNode* curr = node;
    vector<int> temp;
    while( curr != NULL ){
        temp.push_back(curr->val);
        curr = curr->next;
    }
    int i = temp.size() - 1;
    while(node != NULL){
        if( node->val != temp[i] ){
            return false;
        }
        i--;
        node = node->next;
    }
    return true;
}


