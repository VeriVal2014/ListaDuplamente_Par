#include <stdio.h>
#include <stdlib.h>
#include "listd.h"

Listd listd = {.head=NULL, .tail=NULL};


Node* Alloc(){
	Node *nodeInsert= malloc(sizeof(Node));
	return nodeInsert;
}

int show(){
	Node *nodeShow=listd.head;
	
	while(nodeShow){
		printf("%d ", nodeShow->info);
		nodeShow=nodeShow->next;
	}
	
	return 1;
}
int showInv(){
	Node *nodeShow=listd.tail;
	
	while(nodeShow){
		printf("%d ", nodeShow->info);
		nodeShow=nodeShow->last;
	}
	
	return 1;
}

int insertFront(int num){
	Node *nodeInsert;
	nodeInsert=Alloc();
	
	nodeInsert->info=num;
	
	if(listd.head==NULL){
		nodeInsert->last=NULL;
		nodeInsert->next=NULL;
		listd.head=nodeInsert;
		listd.tail=nodeInsert;
	}else {
		nodeInsert->next=listd.head;
		nodeInsert->last=NULL;
		listd.head->last=nodeInsert;
		listd.head=nodeInsert;
	}
	
	return 1;
}

int insertBack(int num){
	Node *nodeInsert;
	nodeInsert=Alloc();
	
	nodeInsert->info=num;
	
	if(listd.head==NULL){
		nodeInsert->last=NULL;
		nodeInsert->next=NULL;
		listd.head=nodeInsert;
		listd.tail=nodeInsert;
	}else {
		nodeInsert->last=listd.tail;
		nodeInsert->next=NULL;
		listd.tail->next=nodeInsert;
		listd.tail=nodeInsert;	
	}
	
	return 1;
}

int deleteNum(int num){
	
	Node *nodeFind=listd.head;
	while(nodeFind){
		if(nodeFind->info==num){
			if((!(nodeFind->last))||(!(nodeFind->next))){
			
				if((!(nodeFind->last))&&(!(nodeFind->next))){
					listd.head=NULL;
					listd.tail=NULL;
				}else{
					if(!(nodeFind->last)){
						listd.head=nodeFind->next;
						nodeFind->next->last=NULL;
					
					}
					if(!(nodeFind->next)){
						listd.tail=nodeFind->last;
						nodeFind->last->next=NULL;
			
					}
				}
			}
			else {
				nodeFind->last->next=nodeFind->next;
				nodeFind->next->last=nodeFind->last;
			}
						
		}
		nodeFind=nodeFind->next;
	}
	
	return 1;
}

