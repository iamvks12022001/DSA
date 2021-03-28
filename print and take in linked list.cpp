#include<bits/stdc++.h>
using namespace std;

struct node{
	int data=0;
	node * addr;
	node(int data){
		this->data=data;
		addr=NULL;
	}
};

void printLL(node *head)
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->addr;
	}
}
void insertLL(int value,node *&head ,node *&tail)
{

  node *newnode=new node(value);
	if(head==NULL)
	{
		head=newnode;
		
	}
	else{
		tail->addr=newnode;
	}

  tail=newnode;

}
int main()
{
	node *head=NULL;
	node *tail=NULL;
	cout<<"give the values for liked list and press -1 if you finished the insertion of input value"<<endl;

	int i=0;
	cin>>i;
	
	while(i!=-1)
	{
		
		insertLL(i,head,tail);
	
		cin>>i;
	}

	printLL(head);
}