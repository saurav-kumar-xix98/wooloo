#include <library/LC0140_WordBreakII.hpp>

namespace LC0140 {
    struct TrieNode {
        int wordLength;
        TrieNode* children[26];
        TrieNode() {
            wordLength = 0;
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

        temp->wordLength = word.size();
    }
}

std::vector<std::string> LC0140::wordBreak(std::string s, std::vector<std::string> &wordDict) {
        TrieNode* root = new TrieNode();
        for (const auto &word : wordDict)
            addWordToTrie(root, word);

        std::vector<TrieNode*> candidates = {root};
        std::vector<std::vector<std::string>> endsHere(s.size());

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            std::vector<TrieNode*> newCandidates;
            int indx = ch - 'a';
            bool foundWordEnd = false;
            for (TrieNode* node : candidates) {
                TrieNode* child = node->children[indx];
                if (child == nullptr)
                    continue;
                
                newCandidates.push_back(child);
                int length = child->wordLength;
                if (length != 0) {
                    foundWordEnd = true;
                    std::string currentWord = s.substr(i + 1 - length, length);
                    if (i - length >= 0) {
                        for (const auto &stringSoFar: endsHere[i - length])
                            endsHere[i].push_back(stringSoFar + " " + currentWord);
                    } else {
                        endsHere[i].push_back(currentWord);
                    }
                }
            }

            if (foundWordEnd) {
                newCandidates.push_back(root);
            }

            candidates.swap(newCandidates);
        }

        return endsHere.back();
}
