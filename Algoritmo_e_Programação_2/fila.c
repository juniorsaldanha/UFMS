#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//testando
typedef struct node
{
	int data;
	struct node* next;	
}node;
void printList(node **head){
	node *temp = *head;
	if(temp == NULL){
		printf("fila vazia\n");
		return;
	}
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void adicionaFinal(node **head, int value){
	if(*head != NULL){
		node *temp = *head;
		while(temp->next != NULL) temp = temp->next;
		node *new = (node *)malloc(sizeof(node));
		temp->next = new;
		new->next = NULL;
		new->data = value;
	}else{
		node *new = (node *)malloc(sizeof(node));
		*head = new;
		new->next = NULL;
		new->data = value;
	}
}
void removeInicio(node **head){
	if(*head == NULL) printf("fila vazia\n");
	else *head = (*head)->next;
}
//1 INSERE
//2 REMOVE
//3 IMPRIME
int main(){
	int comando, x;node *head = NULL;
	scanf("%d", &comando);
	while(comando != 0){
		if(comando == 1){
			scanf("%d", &x);
			adicionaFinal(&head, x);
		}else if(comando == 2) removeInicio(&head);
		else if(comando == 3) printList(&head);
		scanf("%d", &comando);
	}

	return 0;
}