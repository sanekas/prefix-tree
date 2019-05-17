#pragma once

#define SIZE 26

struct Node {
	Node *children[SIZE];
	bool wordEnd;
};