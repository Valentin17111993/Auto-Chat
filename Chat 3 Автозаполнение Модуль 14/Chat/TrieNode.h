#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
	public:
		unordered_map<char, TrieNode*> children;
		bool isEndOfWord;

		TrieNode();
};

class Trie
{
	private:
		TrieNode* root;

	public:
		Trie();
		~Trie();
		void deleteTrie(TrieNode* node);
		void insert(const std::string& word);
		void searchSuggestions(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions);
		vector<std::string> autocomplete(const std::string& prefix);
};