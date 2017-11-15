#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *next;
	struct _Node *prev;
}Node;

typedef struct _Placeholder{
	int size;
	Node *top;
}Placeholder;

void push(Placeholder* ph, int num){
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = num;
	newnode->next = NULL;
	if(ph->size == 0){
		newnode->prev = NULL;
		ph->top = newnode;
	}
	else{	
		newnode->prev = ph->top;
		ph->top->next = newnode;
		ph->top = newnode;
	}
	ph->size++;
}

void pop(Placeholder* ph){
	Node* tmp = ph->top;
	ph->size --;
	if(ph->size == 0){
		ph->top = NULL;
	}
	else{
		ph->top = ph->top->prev;
		ph->top->next = NULL;
	}
	free(tmp);
}
	

int main(){

	Placeholder* ph = (Placeholder *)malloc(sizeof(Placeholder));
	ph->size = 0;
	ph->top = NULL;
	int num, flag;
	while(1){
		printf("the size of stack is %d\n",ph->size);
		printf("press 1 for push, press 2 for pop\n");
		scanf("%d",&flag);
		if(ph->size == 0&&flag == 2){
			perror("no data in stack");
			continue;
		}
		 
	push(ph,3);
	printf("%d\n",ph->top->data);
	push(ph,4);
	printf("%d\n",ph->top->data);
	pop(ph);
	printf("%d\n",ph->top->data);
	pop(ph);
	free(ph);
	
	return 0;
}
