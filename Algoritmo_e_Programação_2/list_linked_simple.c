#include <stdio.h>
#include <stdlib.h>
typedef int ttipo;
typedef struct node_{
	ttipo value;
	struct node_ *prox;
}node;
void insere_inicio(node **head, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->value = value;
	new_->prox = *head;
	*head = new_;
}
void insere_final(node **head, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->value = value;
	if(*head == NULL){
		new_->prox = *head;
		*head = new_;
	}else{
		node *temp = *head;
		while(temp->prox != NULL) temp = temp->prox;
		new_->prox = temp->prox;
		temp->prox = new_;
	}
}
void remove_inicio(node **head){
	node *temp = *head;
	*head = (*head)->prox;
	free(temp);
}
void remove_final(node **head){
	node *temp = *head;
	while(temp->prox->prox != NULL) temp = temp->prox;
	free(temp->prox->prox);
	temp->prox = NULL;
}
void print_linked_list(node **head){
	node *temp = *head;
	if(*head == NULL) return;
	while(temp != NULL){
		printf("%d ", temp->value);
		temp = temp->prox;
	}
	printf("\n");
}
int main(){
	int n;
	scanf("%d", &n);
	ttipo j;
	node *head = NULL;
	for (int i = 0; i < n; ++i){
		scanf("%d", &j);
		insere_inicio(&head, j);
		insere_final(&head, j);
	}
		print_linked_list(&head);
		remove_inicio(&head);
		remove_final(&head);
		print_linked_list(&head);
	return 0;
}