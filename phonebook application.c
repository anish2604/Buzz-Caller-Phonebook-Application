#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct node
{
	char name[50];//name of contact
	char sex[10];//gender of contact
	int age;//age of contact
	char num[10];//phone number of contact
	struct node *next;
}; 
 
typedef struct node Node;
typedef struct node * Link;
 
void display(Link head);
void insert_node(Link head,Link new_node);
void delete_node(Link head);
void search(Link head);
void mod_node(Link head);
  
//Function to Create a new head node initialization List
void create_link(Link * head)
{
	*head=(Link)malloc(sizeof(Node));
	(*head)->next = NULL;
}
 
//Function to Insert details for a contact
void insert_node(Link head,Link new_node)
{
	Link p,q;
	q = head;
	p = q->next;
	new_node=(Link)malloc(sizeof(Node));
 
	printf("\n\tEnter Name: ");
	scanf("%s",new_node->name);
 
 	//Determining whether the gender input is correct
	while(1==1)
	{
		printf("\tEnter Gender (male or female): ");
		scanf("%s",new_node->sex);
		if((strcmp(new_node->sex,"male")!=0)&&(strcmp(new_node->sex,"female")!=0))
		{
			printf("\n\tInvalid Gender!\n\n");
		}
		else
			break;
	}
	
	while(1==1)
	{
		printf("\tEnter Age: ");
		scanf("%d",&new_node->age);
		//Determining whether the age input is correct
		if(new_node->age<0||new_node->age>120)
		{
			printf("\n\tInalid Age!\n\n");
		}
		else
			break;
	}
	
	//Determining whether the phone number has correct number of digits
	while(1==1)
	{
		printf("\tEnter Phone Number: ");
		scanf("%s",new_node->num);
		if(strlen(new_node->num)!=10)
		{
			printf("\n\tInvalid Phone Number!\n\n");
		}
		else
			break;	
	}
 
	if(NULL == p)
	{
		q->next = new_node;
		new_node = p;
	}
	else
	{
		while(strcmp((new_node->name),(p->name))==1)
		{
			p = p->next;
			q = q->next;
		}
		new_node->next = p;
		q->next = new_node;
	}
}
 
//Funtion to delete a contact information based on his/her name
void delete_node(Link head)
{
	Link p,q;
	char comp[20];
	p = head->next;
	q = head;
	printf ("\n\tEnter the Contact Name to be Deleted: ");
	scanf("%s",comp);
	if(p == NULL)
	{
		printf("\n\tPhonebook has no Contacts!\n\n");
	}
	else
	{
		//Determining whether the names are the same with the entered name and continue traversing
		while(p != NULL && (strcmp(p->name,comp)!=0))
		{
			q = p;
			p = p->next;
		}
		if(NULL == p)
		{
			printf("\n\tThere is no such Contact!\n\n");
		}
		else
		{
			q->next = p->next;
			free(p);
			printf("\n\tContact Deleted!\n\n");
		}
	}
}
 
// Function to Search a given contact by its name
void search(Link head)
{
	char comp[20];
	Link q=head;
	Link p=q->next;
	printf ("\n\tEnter the Contact Name to be Searched: "); 
	scanf("%s",comp);
	while(p!=NULL&&(strcmp(p->name,comp)!=0))
	{
		q=p;
		p=p->next;
	}
	if(NULL == p)
	{
		printf("\n\tCheck no such person!\n\n");
		return;
	}
	else
	{
		printf("\n\t\tName\t\tGender\t\tAge\t\tPhone Number\n");
		printf("\t\t%s\t\t",p->name );
		printf("%s\t\t",p->sex );
		printf("%d\t\t",p->age );
		printf("%s\n",p->num );
	}
}

//Function to Modify all information in the node based on name of the contact
void mod_node(Link head)
{
	char comp[20];
	int choice;
	Link q=head;
	Link p=q->next;
	printf ("\n\tEnter the Contact Name to be Modified: ");
	scanf("%s",comp);
	while(p!=NULL&&(strcmp(p->name,comp)!=0))
	{
		q=p;
		p=p->next;
	}
	if(NULL == p)
	{
		printf("\n\tThere is No such Contact!\n\n");
		return;
	}
	else
	{
		printf("\n\t1. Modify Name\n");
		printf("\t2. Modify Gender\n");
		printf("\t3. Modify Age\n");
		printf("\t4. Modify Phone Number\n");
		printf("\t5. Exit Modification\n");
		printf ("\n\tEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf ("\n\tEnter Modified Name: ");
				   	scanf("%s",p->name);
				   	break;
			case 2:	while(1==1)
					{
						printf("\n\tEnter the Modified Gender (male or female): ");
						scanf("%s",p->sex);
						if((strcmp(p->sex,"male")!=0)&&(strcmp(p->sex,"female")!=0))
						{
							printf("\n\tInvalid Gender!\n\n");
						}
						else
							break;
					}
					break;
			case 3:	while(1==1)
					{
						printf ("\n\tEnter the Modified Age: ");
						scanf("%d",&p->age);
						if(p->age<0||p->age>120)
						{
							printf("\n\tInvalid Age!\n\n");
						}
						else
							break;
					}
					break;
			case 4:	while(1==1)
					{
						printf ("\n\tEnter the Modified Phone Number: ");
						scanf("%s",p->num);
						if(strlen(p->num)!=10)
						{
							printf("Invalid Phone Number!\n\n");
						}	
						else
							break;	
					}
					break;
			case 5:	
					break;
		}
	}
 
}

// Function to Traverve through the linked list and display the contents of each node
void display(Link head)
{
	Link p;
	p = head->next;
	if(NULL == p)
	{
		printf("\n\tPhonebook has No Contacts!\n\n");
		return;
	}
	
	printf("\n\t\tName\t\tGender\t\tAge\t\tPhone Number\n");
	while(p!= NULL)
	{
		printf("\t\t%s\t\t",p->name );
		printf("%s\t\t",p->sex );
		printf("%d\t\t",p->age );
		printf("%s\n",p->num );
		p = p->next;
	}
}
 
int main()
{
	int i,j,m;
	Link head;
	Link new_node;
	create_link(&head); 
 	
 	system("COLOR 60");
 	
 	printf("\n\t\t\t\t\t\t\tBUZZ Caller\n");
 	
 	while(1 == 1)
	{
		printf("\n\t\t\t\t\t\t1. New Contact\n");
		printf("\t\t\t\t\t\t2. Search for Contact\n");
		printf("\t\t\t\t\t\t3. Modify Contact\n");
		printf("\t\t\t\t\t\t4. Delete Contact\n");
		printf("\t\t\t\t\t\t5. Show All Contacts\n");
		printf("\t\t\t\t\t\t6. Exit Phonebook\n");
		printf ("\n\tEnter your Choice: ");
		scanf("%d",&m);
		switch(m)
		{
			case 1:	insert_node(head,new_node);
					break;
			case 2:	search(head);
					break;
			case 3:	mod_node(head);
					break;
			case 4:	delete_node(head);
					break;
			case 5:	display(head);
					break;
			case 6:	return 0;
		}
	}
}
