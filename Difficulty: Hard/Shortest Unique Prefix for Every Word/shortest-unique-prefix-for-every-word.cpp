class Solution {
  struct TrieNode {
      unordered_map<char, TrieNode*> children;
      int count;
      TrieNode() : count(0) {}
  };

  void insert(TrieNode* root, const string& word) {
      TrieNode* node = root;
      for (char c : word) {
          if (!node->children[c]) node->children[c] = new TrieNode();
          node = node->children[c];
          node->count++;
      }
  }

  string getPrefix(TrieNode* root, const string& word) {
      TrieNode* node = root;
      string prefix;
      for (char c : word) {
          node = node->children[c];
          prefix.push_back(c);
          if (node->count == 1) break;  // unique prefix found
      }
      return prefix;
  }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        
        // Build Trie
        for (auto &word : arr) {
            insert(root, word);
        }
        
        // Collect shortest unique prefixes
        vector<string> result;
        for (auto &word : arr) {
            result.push_back(getPrefix(root, word));
        }
        
        return result;
    }
};
