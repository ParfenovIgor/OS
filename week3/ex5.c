#include <stdio.h>
#include <stdlib.h>
                   
struct node{
 	int key;
	struct node *prev,*next;
};
    
struct node *first=NULL;
          
void print_list(){
	struct node *ptr=first;
	while(ptr!=NULL){
	 	printf("%d ",ptr->key);
	 	ptr=ptr->next;
	}
	printf("\n");
}

void insert_node(struct node *ptr,int _key){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->key=_key;
	if(ptr->next==NULL){
		ptr->next=new;
		new->prev=ptr;
		new->next=NULL;
	}
	else{
	 	struct node *ptr2=ptr->next;
	 	ptr->next=new;
	 	new->prev=ptr;
	 	new->next=ptr2;
	 	ptr2->prev=new;
	}
}

void insert_front(int _key){
    struct node *new=(struct node*)malloc(sizeof(struct node));
	new->key=_key;
	new->prev=NULL;
	new->next=first;
	if(first!=NULL){
	 	first->prev=new;
	}
	first=new;
}

void delete_node(struct node *ptr){
 	struct node* prev=ptr->prev;
 	struct node* next=ptr->next;
 	if(prev==NULL && next==NULL){
 	 	first=NULL;
 	}
 	else if(prev==NULL && next!=NULL){
 	 	first=next;
 	 	next->prev=NULL;
 	}
 	else if(prev!=NULL && next==NULL){
 	 	prev->next=NULL;
 	}
 	else{
 	 	prev->next=next;
 	 	next->prev=prev;
 	}
 	free(ptr);
}

int main(){  
    for(int i=1;i<=10;i++)
    	insert_front(i);
    print_list();
    struct node *ptr=first;
    for(int i=0;i<5;i++)
		ptr=ptr->next;
	insert_node(ptr,20);
	print_list();
	delete_node(ptr);
	print_list();
	return 0;
}