#include <library/LC0472_ConcatenatedWords.hpp>

namespace LC0472 {
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    void addWordToTrie(TrieNode* root, const std::string& word) {
        TrieNode* temp = root;
        for (char ch : word) {
            int indx = ch - 'a';
            if (temp->children[indx] == nullptr)
                temp->children[indx] = new TrieNode();

            temp = temp->children[indx];
        }

        temp->isWord = true;
    }

    bool canSplit(TrieNode* root, const std::string &word) {
        int N = word.size();

        std::vector<bool> toVisit(N, false);
        toVisit[0] = true;

        for (int i = 0; i < N; ++i) {
            if (!toVisit[i])
                continue;
            TrieNode* temp = root;
            for (int j = i; j < N; ++j) {
                temp = temp->children[word[j] - 'a'];
                if (temp == nullptr)
                    break;
                if (temp->isWord) {
                    if (i != 0 && j == N - 1)
                        return true;
                    if (j + 1 < N)
                        toVisit[j + 1] = true;
                }
            }
        }
        return false;
    }
}

std::vector<std::string> LC0472::findAllConcatenatedWordsInADict(std::vector<std::string> &words) {
    TrieNode* trie = new TrieNode();
    for (const auto &word : words)
        addWordToTrie(trie, word);

    std::vector<std::string> ans;
    for (const auto &word: words)
        if (canSplit(trie, word))
            ans.push_back(word);

    return ans;
}
