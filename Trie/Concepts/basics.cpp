#include <iostream>
#include <vector>
using namespace std;

// Construction of a Trie Data Structure 
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    public:
    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }

    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            if(children[i])
                delete children[i];
        }
    }
};

// Make More Robust Root Node
class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode();
    }

    ~Trie(){
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
    bool isStartsWith(const string& prefix){
        TrieNode* curr = root;

        for(int i = 0; i < prefix.length(); i++)
        {
            int idx = prefix[i] - 'a';
            if( !curr->children[idx] ) return false;

            curr = curr->children[idx];
        }

        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << (trie.search("app") ? "Found\n" : "Not Found\n");            // Output: Found
    cout << (trie.search("apples") ? "Found\n" : "Not Found\n");         // Output: Not Found
    cout << (trie.isStartsWith("app") ? "Prefix Found\n" : "Not Found\n"); // Output: Prefix Found

    return 0;
}