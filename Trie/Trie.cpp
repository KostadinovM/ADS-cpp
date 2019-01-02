#include <string>

using namespace std;

const int SIZE = 26;

struct node
{
	node *children[SIZE];
	bool isEndOfWord;
};

class Trie
{
public:
	void insert(node *root, string key);
	node *getNode();
	bool search(node* root, string key);
};

node *Trie::getNode()
{
	node *pNode = new node;
	pNode->isEndOfWord = false;
	for (int i = 0; i < SIZE; i++)
		pNode->children[i] = nullptr;
	return pNode;
}


void Trie::insert(node *root, string key)
{
	node *pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}

	//mark last node as leaf
	pCrawl->isEndOfWord = true;
}

bool Trie::search(node *root, string key)
{
	node *pCrawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}
