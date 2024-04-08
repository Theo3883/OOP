#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_CHILDREN 101
template <class T>
class Tree
{
private:
	struct Node
	{
		T value;
		Node* parent;
		Node* children[MAX_CHILDREN];
		int childrenCount;

		Node(T value, int parent) : value(value), parent(parent), childrenCount(0)
		{
			for (int i = 0; i < MAX_CHILDREN; i++)
				children[i] = nullptr;
		}
	};

	Node* root;
	int nodesCount;

	// functii pentru implementare

	bool cmp(Node* a, Node* b)
	{
		return a->value > b->value;
	}
	T find_recursiv(Node* parent, T value)
	{
		if (parent->value == value)
			return parent->value;
		for (int i = 0; i < parent->childrenCount; i++)
		{
			T found = find_recursiv(parent->children[i], value); //subarborele copilului
			if (found != nullptr)
				return found;
		}
		return nullptr;
	}
	int count_recursiv(Node* parent)
	{
		int count = 1;
		for (int i = 0; i < parent->childrenCount; i++)
			count += count_recursiv(parent->children[i]);
		return count;
	}
	void delete_recursiv(Node* parent)
	{
		for (int i = 0; i < parent->childrenCount; i++)
			delete_recursiv(parent->children[i]);
		//nodesCount--;
		delete parent;
	}

public:

	Tree() : root(nullptr), nodesCount(0) {};

	//metode
	void add_node(Node* parent, Node* newNode)
	{
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		parent->childrenCount++;
		parent->children[parent->childrenCount++]
	}
	T get_node(Node* parent, int index)
	{
		if (index == -1)
			return root->value;
		if (index <= nodes[parent]->childrenCount)
		{
			return parent->children[index]->value;
		}
		return T();
	}
	void delete_node(Node* parent)
	{
		delete_recursiv(parent);
	}
	T find(T value)
	{
		return find_recursiv(root, value);
	}
	void insert(Node* parent, int index, Node* newNode)
	{
		parentNode->childrenCount++;
		for (int i = parent->childrenCount - 1; i > index; i--)
			parent->children[i] = parent->children[i - 1];
		parent->children[index] = newNode;
	}
	void sort(Node* parent)
	{
		if (parent >= 0 && parent <= nodesCount)
		{
			for (int i = 0; i < parent->childrenCount - 1; i++)
				for (int j = i + 1; j < parent->childrenCount; j++)
					if (cmp(parent->children[i], parent->children[j]))
						swap(parent->children[i], parent->children[j]);
		}
	}
	int count(Node* parent)
	{
		return count_recursiv(parent);
	}
};

