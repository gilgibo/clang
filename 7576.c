#include <stdio.h>
#include <stdlib.h>

int row,col;

typedef struct _Node{
	int r;
	int c;
	int num;
	struct _Node *next;
	struct _Node *prev;
}Node;

typedef struct _Queue{
	Node* top;
	int size;
}Queue;

void push(int a, int b ,int n,Queue* ph){
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->r = a;
	newnode->c = b;
	newnode->num = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(ph->size == 0){
		ph->top = newnode;
	}else{
		Node *tmp = ph->top;
		while(tmp->prev != NULL)
			tmp = tmp->prev;
		tmp->prev = newnode;
		newnode->next = tmp;
	}
	ph->size++;
	printf("%d,%d,%d \n",a,b,n);
}
		

Node* pop(Queue* ph){
	Node* tmp = ph->top;
	if(ph->size == 1){
		ph->top = NULL;
	}else if (ph-> size > 1){
		ph->top = ph->top->prev;
		ph->top->next = NULL;
		tmp->prev = NULL;
	}
	ph->size--;
	return tmp;
}	

int main()
{
	Queue* ph = (Queue*)malloc(sizeof(Queue));
	ph->size = 0;
	ph->top = NULL;
	scanf("%d %d",&row,&col);

	int tom[row][col];	

	for(int i = 0 ; i < row ; i ++){
		for(int j = 0 ; j < col ; j++){
			scanf("%d",&tom[i][j]);
			if(tom[i][j] ==1)
				push(i,j,0,ph);
		}
	}
	int cnt = 0;
	
	while(ph->size != 0){
		Node* tmp = pop(ph);
		int hor = tmp->r;
		int ver = tmp->c;
		int t_n = tmp->num;
		if(hor-1 >=0 && tom[hor-1][ver] == 0){
			push(hor-1,ver,t_n+1,ph);
			tom[hor-1][ver] =1;
		}
		if(hor+1 <row && tom[hor+1][ver] == 0){
			push(hor+1,ver,t_n+1,ph);
			tom[hor+1][ver] = 1;
		}
		if(ver-1 >=0 && tom[hor][ver-1] == 0){
			push(hor,ver-1,t_n+1,ph);
			tom[hor][ver-1] = 1;
		}
		if(ver+1 < col && tom[hor][ver+1] == 0){
			push(hor,ver+1,t_n+1,ph);
			tom[hor][ver+1] = 1;
		}
		cnt = t_n;
		free(tmp);
	}
	
	printf("%d",cnt);
	return 0;
}
