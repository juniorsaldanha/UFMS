#include <stdio.h>
#include <stdlib.h>
typedef struct node_{
	int posicao;
	struct node_ *next;
	struct node_ *prev;
}node;
void print_list(node **head){
	node *temp = *head;
	while(1){
		printf("posição %d\n", temp->posicao);
		temp = temp->next;
		if(temp == *head) return;
	}
}
void create_list(node **head, int posicoes){
	int i;
	node *current = NULL;
	for(i = 1; i <= posicoes; ++i){
		node *new_ = malloc(sizeof(node));
		new_->posicao = i;
		if(*head == NULL){
			*head = new_->next = new_->prev = current = new_;
		}else{
			current->next = new_;
			new_->prev = current;
			new_->next = *head;
			(*head)->prev = new_;
			current = new_;
		}
	}	
}
int josephus(node **head, int jumps){
	node *current = *head;node *temp = NULL;
	int i;
	while(current->next != current){
		for(i = 1; i < jumps; ++i) current = current->next;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		temp = current;
		current = current->next;
		free(temp);
	}
	return current->posicao;
}
int main(){
	int k, jumps, posicoes;
	scanf("%d", &k);
	while(k--){
		node *head = NULL;
		scanf("%d%d", &posicoes, &jumps);
		create_list(&head, posicoes);
		// print_list(&head);
		printf("%d\n", josephus(&head, jumps));
	}
	return 0;
}