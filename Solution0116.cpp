// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/* 116. Populating Next Right Pointers in Each Node */
/* Runtime: 11ms, Memory: 18.87MB*/

class Solution {
public:
    Node *connect(Node *root) {
        // Edge case: empty tree, nothing to connect
        if (root == nullptr) {
            return root;
        }

        // 'leftmost' always points to the leftmost node of the current level
        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            // 'head' walks horizontally across the current level
            // using the next pointers we've already established
            Node* head = leftmost;

            while (head != nullptr) {
                // Connect 1: left child -> right child (same parent)
                head->left->next = head->right;

                // Connect 2: right child -> next node's left child
                // (only possible if there's a next node on this level)
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                // Move to the next node in the current level
                head = head->next;
            }

            // Move down to the next level, starting from its leftmost node
            leftmost = leftmost->left;
        }
        return root;
    }
};
