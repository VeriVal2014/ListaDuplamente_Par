#ifndef LISTD_H
#define LISTD_H

typedef struct node Node;
typedef struct listd Listd;

struct node{
	Node* next; //Next node
	Node* last; //Previous node
	int info; //Info of node
};

struct listd{
	Node* head; //First node
	Node* tail; //Last node
};

extern int insertFront (int num);
extern int insertBack (int num);
extern int deleteNum (int num);
extern int show();
#endif
