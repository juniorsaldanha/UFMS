#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	int data;
	struct node *next;	
}node_t;
void adicionaInicio(node_t **head, int data);
void adicionaFinal(node_t **head, int data);
void removeInicio(node_t **head);
void removeFinal(node_t **head);
void printList(node_t **head);
int main(){
	int comando, data;
	scanf("%d", &comando);
	node_t *head = NULL;
	while(comando != 0){
		

		//	1 – Inserção do elemento no início da lista;
		if(comando == 1){
			scanf("%d", &data);
			adicionaInicio(&head, data);
		}
		//2 – Inserção do elemento no final da lista;
		else if(comando == 2){
			scanf("%d", &data);
			adicionaFinal(&head, data);
		}
		//3 – Remoção do primeiro elemento da lista;
		else if(comando == 3){
			removeInicio(&head);
		}
		//4 – Remoção do último elemento da lista;
		else if(comando == 4){
			removeFinal(&head);
		}
		//5 – Imprime a lista. Imprima “lista vazia” caso a lista esteja sem nenhum elemento;
		else if(comando == 5){
			printList(&head);
		}
		scanf("%d", &comando);
	}
	return 0;
}
void adicionaInicio(node_t **head, int value){
	node_t * temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->data = value;
	temp->next = *head;
	*head = temp;
}
void adicionaFinal(node_t **head, int value){
	if(*head != NULL){
		node_t *temp = *head;
		while(temp->next != NULL) temp = temp->next;
		node_t *new = (node_t *)malloc(sizeof(node_t));
		temp->next = new;
		new->next = NULL;
		new->data = value;
	}else{
		node_t *new = (node_t *)malloc(sizeof(node_t));
		*head = new;
		new->next = NULL;
		new->data = value;
	}
}
void removeInicio(node_t **head){
	if(*head == NULL) printf("lista vazia\n");
	else *head = (*head)->next;
}
void removeFinal(node_t **head){
	node_t *temp = *head;
	node_t* aux = NULL;
	if(*head == NULL) printf("lista vazia\n");
	else if(temp->next != NULL){
		while(temp->next != NULL){
			aux = temp;
			temp = temp->next;
		}
		aux->next = NULL;
	}else{
		*head = NULL;
	}
}
void printList(node_t **head){
	node_t *temp = *head;
	if(temp == NULL){
		printf("lista vazia\n");
		return;
	}
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}