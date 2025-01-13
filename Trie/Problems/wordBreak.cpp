#include <iostream>
using namespace std;

// Google Asked Problem
// https://leetcode.com/problems/word-break/
// Construction of a Trie Data Structure
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;

public:
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i])
                delete children[i];
        }
    }
};

// Make More Robust Root Node
class Trie
{
public:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        delete root; // Clean Up
    }

    // Insert Function
    void insert(const string &word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';

            if (!curr->children[idx])
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }

        curr->isEndOfWord = true;
    }

    // Search Fuction
    bool search(const string &word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->isEndOfWord;
    }

    // Starts With Function
    bool isStartsWith(const string &prefix)
    {
        TrieNode *curr = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int idx = prefix[i] - 'a';
            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};


class Solution
{
public:
    bool isPossible(int start, string &s, Trie &trie)
    {
        // Base Case: Reached the end of the string
        if (start == s.length())
        {
            return true;
        }

        TrieNode *curr = trie.root; // Start from the root of the Trie

        // Try every possible partition of the string
        for (int i = start; i < s.length(); ++i)
        {
            int idx = s[i] - 'a';

            // If no child node matches, break out early
            if (!curr->children[idx])
            {
                break;
            }

            curr = curr->children[idx];

            // If current prefix is a valid word, recursively check the rest
            if (curr->isEndOfWord)
            {
                if (isPossible(i + 1, s, trie))
                {
                    return true;
                }
            }
        }

        return false; // No valid segmentation found
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.empty())
            return false; // Handle edge case: empty dictionary

        // Create a Trie and insert all words
        Trie trie;
        for (const string &word : wordDict)
        {
            trie.insert(word);
        }

        // Start the recursive process from index 0
        return isPossible(0, s, trie);
    }
};


// Using Memoisation
bool isPossible2(int start, string &s, Trie &trie, vector<int> &memo)
{
    if (start == s.length())
        return true; // Base Case: Reached the end

    if (memo[start] != -1)
        return memo[start]; // Check memoized result

    TrieNode *curr = trie.root;
    for (int i = start; i < s.length(); ++i)
    {
        int idx = s[i] - 'a';
        if (!curr->children[idx])
            break; // No match, stop further checks
        curr = curr->children[idx];

        if (curr->isEndOfWord)
        {
            if (isPossible2(i + 1, s, trie, memo))
            {
                return memo[start] = true;
            }
        }
    }
    return memo[start] = false; // Memoize result
}

int main()
{
    return 0;
}