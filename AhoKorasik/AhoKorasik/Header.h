#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* failureLink;
    vector<int> output;
    TrieNode() : failureLink(nullptr) {}
};

class AhoCorasick {
public:
    AhoCorasick(const vector<string>& patterns) {
        root = new TrieNode();
        comparisons = 0;
        buildTrie(patterns);
        buildFailureLinks();
    }

    ~AhoCorasick() {
        deleteTrie(root);
    }

    void search(const string& text) {
        TrieNode* current = root;
        for (int i = 0; i < text.size(); ++i) {
            while (current != root && current->children.find(text[i]) == current->children.end()) {
                current = current->failureLink;
                ++comparisons;
            }
            if (current->children.find(text[i]) != current->children.end()) {
                current = current->children[text[i]];
                ++comparisons;
            }
            processOutputs(current, i);
        }
    }

    int getComparisons() const {
        return comparisons;
    }

private:
    TrieNode* root;
    int comparisons;

    void buildTrie(const vector<string>& patterns) {
        for (int i = 0; i < patterns.size(); ++i) {
            TrieNode* current = root;
            for (char ch : patterns[i]) {
                if (current->children.find(ch) == current->children.end()) {
                    current->children[ch] = new TrieNode();
                }
                current = current->children[ch];
            }
            current->output.push_back(i);
        }
    }

    void buildFailureLinks() {
        queue<TrieNode*> q;
        for (auto& pair : root->children) {
            pair.second->failureLink = root;
            q.push(pair.second);
        }

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (auto& pair : current->children) {
                char ch = pair.first;
                TrieNode* child = pair.second;
                TrieNode* failure = current->failureLink;

                while (failure != root && failure->children.find(ch) == failure->children.end()) {
                    failure = failure->failureLink;
                }
                if (failure->children.find(ch) != failure->children.end()) {
                    child->failureLink = failure->children[ch];
                }
                else {
                    child->failureLink = root;
                }

                child->output.insert(child->output.end(), child->failureLink->output.begin(), child->failureLink->output.end());
                q.push(child);
            }
        }
    }

    void processOutputs(TrieNode* node, int index) {
        for (int patternIndex : node->output) {
            cout << "Pattern " << patternIndex << " found at position " << index << endl;
        }
    }

    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};
