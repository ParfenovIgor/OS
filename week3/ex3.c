#include <stdio.h>
#include <stdlib.h>
                   
struct node{
 	int key;
	struct node *next;
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
		new->next=NULL;
	}
	else{              
		new->next=ptr->next;
		ptr->next=new;
	}
}

void insert_front(int _key){
    struct node *new=(struct node*)malloc(sizeof(struct node));
	new->key=_key;
	new->next=first;
	first=new;
}

void delete_node(struct node *ptr){
 	if(ptr=first){
 	 	first=ptr->next;
 	}
 	else{
 	 	struct node *ptr2=first;
 	 	while(ptr2->next!=ptr)
 	 		ptr2=ptr2->next;
 	 	ptr2->next=ptr->next;
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