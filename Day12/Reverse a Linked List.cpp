// Given a singly linked list node, return its reverse.

// Bonus: Can you do this in \mathcal{O}(1)O(1) space?

/////////////////////////////////////////////////////////////////

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    if(node == NULL || node->next == NULL)
        return node;

    LLNode* curr = node;
    LLNode* prev = NULL, nex = NULL;
    while(curr != NULL){
        LLNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}


