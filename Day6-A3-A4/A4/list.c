#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} NODE;

void initList(NODE **head)
{
	(*head) = (NODE *)malloc(sizeof(NODE));
	(*head)->data = -10;
	(*head)->right = (*head)->left = (*head);
}

NODE *insertList(NODE *head, int x) {

	NODE *newNode, *temp, *curr;

	newNode =  (NODE *)malloc(sizeof(NODE));
	newNode->data = x;
	newNode->left = newNode->right = NULL;

	if(head->data < 0) {
		temp = newNode;
		head->right = head->left = temp;
		temp->left = temp->right = head;
		return temp;
	}

	if (x <= head->data) {
		newNode->right = head;
		newNode->left = head->left;
		head->left = newNode;
		return newNode;
	}

	curr = head;
	while (curr->right->data > 0  && curr->right->data < x) {
		curr = curr->right;
	}

	newNode->right = curr->right;
	curr->right->left = newNode;
	curr->right = newNode;
	newNode->left = curr;
	return head;
}

NODE *deleteList(NODE *head, int x)
{
	NODE *curr = head;
	while (curr->data > 0) {
		if (curr->data == x) break;
		curr = curr->right;
	}
	if (curr->data < 0) return head;

	if (curr->left->data < 0) {
		head = curr->right;
		curr->right->left = curr->left;
	}
	else {
		if (curr->right->data < 0){
			curr->left->right = curr->right;
			curr->right->left = curr->left;
		}
		else {
			curr->left->right = curr->right;
			curr->right->left = curr->left;
		}
		free(curr);
	}
	return(head);
}	


		
void printList(NODE *curr) {
	NODE *start = curr;
	printf("\nThe contents of the list (in descending order) is: \n");
	if (curr->data < 0) return;
	curr=curr->left->left;
	while (curr != start) {
    		printf("%d  ", curr->data);
    		curr = curr->left;
	}	
	printf("%d  ", curr->data);
	printf("\n");
}


int main() {

    	NODE *head;
	int roll, n, i, x;
	initList(&head);
	printf("Enter last 5 digits of your roll no: ");
	scanf("%d", &roll);
	n = 10 + roll%10;
	for (i=0; i<n; i++) {
    		head = insertList(head, roll*3 + 2*i);
	}
	printList(head);
	for (i=0; i<n; i++) {
    		head = deleteList(head, roll*3 + 2*i);
	}

    	return 0;
}	
