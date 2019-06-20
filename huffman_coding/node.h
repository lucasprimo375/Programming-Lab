#ifndef NODE_H
#define NODE_H

struct node {
	std::string character;
	int frequency;
	node* left = nullptr;
	node* right = nullptr;
};

#endif