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
int lengthOfLL(node * head,int length)
{
	if(head!=NULL)
	{
     return  lengthOfLL(head->addr,++length);
	}
	
	return length;
	
}
void printLL(node *head)
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->addr;
	}
	cout<<endl;
}

node* insertatindex(node *head,int i,int data,node *& tail)
{
	node *newnode=new node(data);
	int count=0;
	node *temp=head;
	if(i<0){
	 
	    cout<<"please give suitable index "<<endl;
		return head;
	}
	if(i==0){
		newnode->addr=head;
		head=newnode;
		return head;
	}
 
	while(temp!=NULL && count< i-1){
		temp=temp->addr;
		count++;
		if( count==i-1 && temp->addr==NULL )
		{
			tail=newnode;
		}
	}

	if(temp!=NULL){
		node *a=temp->addr;
		temp->addr=newnode;
		newnode->addr=a;

	}
	return head;
}

int atindex(node *head,int i)
{
	int index=-1;
	int value=-1;
	if(i>=0){
	while(index!=i)
	{ 
		if(head==NULL)
	    {
		  return -1;
	    }
        value=head->data;
		head=head->addr;
		index++;
	}
	return value;
 }
 return -1;
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
	cout<<endl;
	cout<<"length of link list is : "<<lengthOfLL(head,0)<<endl;
	
	cout<<"To find the value at index i give i ? :"<<endl;
	int index=0;
	cin>>index;
	cout<<atindex(head,index)<<endl;
   while(true){
	cout<<"To insert node  at index i give i ? :"<<endl;
	int in=0;
	cin>>in;

	cout<<"Data ? :"<<endl;
	int data=0;
	cin>>data;
	head=insertatindex(head,in,data,tail);
	printLL(head);
	cout<<"last item data "<<tail->data<<endl;
   }
}
