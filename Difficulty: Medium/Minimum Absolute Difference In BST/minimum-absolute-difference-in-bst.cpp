class Solution {
  public:
    int ans = INT_MAX;
    Node* prev = nullptr;

    void inorder(Node* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != nullptr) {
            ans = min(ans, abs(root->data - prev->data));
        }

        prev = root;

        inorder(root->right);
    }

    int absDiff(Node *root) {
        ans = INT_MAX;
        prev = nullptr;

        inorder(root);

        return ans;
    }
};