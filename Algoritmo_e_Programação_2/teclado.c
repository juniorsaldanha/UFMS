#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	char letra;struct node *prox;
}alias_node;
void printList(alias_node *p){
	p = p->prox;
	while(p->prox != NULL){
		printf("%c", p->letra);
		p = p->prox;
	}
	printf("%c\n", p->letra);
}
alias_node *inserts(char c, alias_node *p){
	alias_node *new = (alias_node *)malloc(sizeof(alias_node));
	new	->	letra	= c;
	new	->	prox	= p->prox;
	p->	prox	= new;
	return new;
}
int main(){
	int n, i;char c[100];
	scanf("%d", &n);
	while(n--){
		alias_node head;
		head.prox = NULL;
		alias_node *current = &head;
		scanf("%s", c);
		for(i = 0; c[i] != '\0'; ++i){
			if(c[i] == '[') current = &head;
			else if(c[i] == ']')
				while(current->prox != NULL)
				current = current->prox;
			else current = inserts(c[i], current);
		}
		printList(&head);
	}
	return 0;
}