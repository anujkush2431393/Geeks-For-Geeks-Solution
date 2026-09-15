class Solution {
  public:
    int getCount(Node *root, int k) {
        if (root == nullptr)
            return 0;

        vector<int> leafLevels;
        queue<pair<Node*, int>> q;

        q.push({root, 1});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            // Leaf node
            if (node->left == nullptr && node->right == nullptr) {
                leafLevels.push_back(level);
                continue;
            }

            if (node->left)
                q.push({node->left, level + 1});

            if (node->right)
                q.push({node->right, level + 1});
        }

        // Visit cheapest leaves first
        sort(leafLevels.begin(), leafLevels.end());

        int count = 0;

        for (int cost : leafLevels) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};