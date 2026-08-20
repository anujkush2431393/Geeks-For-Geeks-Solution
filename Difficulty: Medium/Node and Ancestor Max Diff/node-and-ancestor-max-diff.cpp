class Solution {
  public:
    int ans = INT_MIN;

    int dfs(Node* root) {
        if (root == nullptr)
            return INT_MAX;

        int leftMin = dfs(root->left);
        int rightMin = dfs(root->right);

        int subMin = min(root->data, min(leftMin, rightMin));

        // If there is a descendant, calculate difference
        if (leftMin != INT_MAX)
            ans = max(ans, root->data - leftMin);

        if (rightMin != INT_MAX)
            ans = max(ans, root->data - rightMin);

        return subMin;
    }

    int maxDiff(Node* root) {
        dfs(root);
        return ans;
    }
};