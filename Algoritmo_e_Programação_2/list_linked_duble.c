#include <stdio.h>
#include <stdlib.h>
typedef int ttipo;
typedef struct node_{
	ttipo value;
	struct node_ *next;
	struct node_ *prev;
}node;
void print_linkded_list(node **head){
	node *temp = *head;
	if(*head == NULL){ 
		printf("lista vazia\n");
		return;
	}
	while(1){
		printf("%d ", temp->value);
		temp = temp->next;
		if(temp == *head) return;
	}
}
void insere_inicio(node **head, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->value = value;
	if(*head == NULL){
		*head = new_;
		new_->next = new_->prev = new_;
	}else{
		new_->next = *head;
		new_->prev = (*head)->prev;
		(*head)->prev->next = new_;
		(*head)->prev = new_;
		*head = new_;
	}
}
void insere_final(node **head, ttipo value){
	node *new_ = malloc(sizeof(node));
	new_->value = value;
	if(*head == NULL){
		*head = new_;
		new_->next = new_->prev = new_;
	}else{
		new_->next = *head;
		new_->prev - (*head)->prev;
		(*head)->prev->next = new_;
		(*head)->prev = new_;
	}
}
void remove_inicio(node **head){
	node *temp = *head;
	temp->prev->next = (*head)->next;
	temp->next->prev = (*head)->prev;
	*head = (*head)->next;
	free(temp);
}
void remove_final(node **head){
	node *temp = (*head)->prev;
	printf("%d temp prev\n", temp->value);
	(*head)->prev = temp->prev;
	temp->prev->next = (*head);
	//*head = (*head)->next;
	free(temp);
}
int main(){
	ttipo k, n;
	scanf("%d", &n);
	node *head = NULL;
	while(n--){
		scanf("%d", &k);
		insere_inicio(&head, k);
		insere_final(&head, k);
	}
	print_linkded_list(&head);
	printf("\n");
	
	remove_inicio(&head);
	print_linkded_list(&head);
	printf("\n");

	/*remove_final(&head);
	print_linkded_list(&head);
	printf("\n");*/

	//REMOVE NO FINAL NÃO ESTA FUNCIONANDO.
	return 0;
}