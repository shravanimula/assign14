#include<stdio.h>
#include<stdlib.h>
struct Student{
	int marks;
	struct Student *link;
};
struct Student* Add(struct Student *);
void Display(struct Student *);
int main()
{
	struct Student *head=NULL;
	int choice;
	while(1)
	{
		printf("1. Add_last 2.Display 3.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add(head);
				break;
			case 2: Display(head);
				break;
			case 3: exit(0);
		}
	}
}
struct Student* Add(struct Student *ptr)
{
	struct Student *newnode=NULL,*temp=NULL;
//	struct Student
	newnode=calloc(1,sizeof(struct Student));
	if(newnode==NULL)
	{
		printf("Node not created\n");
	}
	else
	{
		printf("enter the marks\n");
		scanf("%d",&newnode->marks);
		if(ptr==NULL) 
		{
			ptr=newnode;
		}
		else
		{
			temp=ptr;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
	
			temp->link=newnode;
		}
	}
	return ptr;
}
void Display(struct Student *ptr)
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(ptr)
		{
			printf("%d\n",ptr->marks);
			ptr=ptr->link;
		}
	}
}

