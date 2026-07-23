class Solution {
  public:
    void dfs(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->data);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    vector<int> preOrder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};