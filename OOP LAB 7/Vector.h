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
		int parent;
		Node* children[MAX_CHILDREN];
		int childrenCount;

		Node(T value, int parent) : value(value), parent(parent), childrenCount(0)
		{
			for (int i = 0; i < MAX_CHILDREN; i++)
				children[i] = nullptr;
		}
	};
	
	Node* nodes[MAX_CHILDREN];
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
		nodesCount--;
		delete parent;
	}

public:
	
	Tree() : root(nullptr), nodesCount(0) {};

	//metode
	void add_node(int parent, T value)
	{
		if (nodesCount== 0)
		{
			root = new Node(value,-1);
			nodes[nodesCount++] = root;
			return;
		}
		if (parent >= 0 && parent < nodesCount)
		{
			Node* parentNode = nodes[parent];
			Node* newNode = new Node(value, parent);
			parentNode->children[parentNode->childrenCount++] = newNode;
			nodes[nodesCount++] = newNode;
		}
	}
	T get_node(int parent)
	{
		if (parent == 0)
			return root->value;
		if (parent >= 0 && parent < nodesCount)
			return nodes[parent]->value;
		return T();
	}
	void delete_node(int parent)
	{
		if (parent >= 0 && parent <= nodesCount)
			delete_recursiv(nodes[parent]);
	}
	T find(T value)
	{
		return find_recursiv(root, value);
	}
	void sort(int parent)
	{
		if (parent >= 0 && parent <= nodesCount)
		{
			Node* parentNode = nodes[parent];
			for (int i = 0; i < parentNode->childrenCount - 1; i++)
				for (int j = i + 1; j < parentNode->childrenCount; j++)
					if (cmp(parentNode->children[i], parentNode->children[j]))
						swap(parentNode->children[i], parentNode->children[j]);
		}
	}
	int count(int parent)
	{
		if (parent == 0)
			return nodesCount;
		if (parent >= 0 && parent <= nodesCount)
		{
			Node* parentNode = nodes[parent];
			return count_recursiv(parentNode);
		}
		return -1;
	}
};

