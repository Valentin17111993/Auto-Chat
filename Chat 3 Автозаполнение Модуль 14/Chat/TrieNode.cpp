#include "TrieNode.h"
using namespace std;

TrieNode::TrieNode()
{
	isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		children[i] = nullptr;
	}
}

Trie::Trie()
{
	root = new TrieNode();
}

Trie :: ~Trie()
{
	deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* node)
{
	if (node)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			deleteTrie(node->children[i]);
		}
		delete node;
	}
}

void Trie::insert(const std::string& word)
{
	TrieNode* current = root;

	for (char c : word)
	{
		if (current->children.find(c) == current->children.end())
		{
			current->children[c] = new TrieNode();
		}
		current = current->children[c];
	}
	current->isEndOfWord = true;
}

void Trie::searchSuggestions(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->isEndOfWord)
	{
		suggestions.push_back(prefix);
	}

	for (const auto& pair : node->children)
	{
		searchSuggestions(pair.second, prefix + pair.first, suggestions);
	}
}

vector<std::string> Trie::autocomplete(const std::string& prefix)
{
	TrieNode* node = root;
	std::vector<std::string> suggestions;

	for (char ch : prefix) 
	{
		if (node->children.find(ch) == node->children.end()) 
		{
			return suggestions; 
		}
		node = node->children[ch];
	}

	if (node != nullptr) 
	{
		searchSuggestions(node, prefix, suggestions);
	}

	return suggestions;
}