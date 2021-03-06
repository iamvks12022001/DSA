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
		
	}

	if(temp!=NULL){
		if( count==i-1 && temp->addr==NULL )
		{
			tail=newnode;
		}
		node *a=temp->addr;
		temp->addr=newnode;
		newnode->addr=a;

	}
	return head;
}
int lengthOfLLrecursive(node * head,int count)
{
	if(head!=NULL)
	{
        count=lengthOfLLrecursive(head->addr,count);
        count++;

	}
	return count;
}

int insertRecurrsive(node *& head,int i,int data, node*& tail)
{
	if(head==NULL )
	{
		if(i==-1)
		{
			node *newnode=new node(data);
			head=newnode;
			tail=newnode;
			return 1;
		}
		return -1;
	}
	if(i==-1)
	{
		node *newnode=new node(data);
		newnode->addr=head;
		head=newnode;
		return 1;
	}
	if(i<-1)
	{
		cout<<"give suitable value for i"<<endl;
		return -1;
	}
	if( i==0)
	{
		node *newnode=new node(data);
		newnode->addr=head->addr;
		head->addr=newnode;
		if(newnode->addr==NULL)
		{
			tail=newnode;
		}
		return 1;
	}

	int res=insertRecurrsive(head->addr,--i,data,tail);
	 return (res==1)?1:-1;


}

int deleteRecurrsive(node *& head,int i, node*& tail)
{
	if(head==NULL )
	{
		return -1;
	}
	if(i==-1)
	{
		node *a=head;
		head=head->addr;
		delete a;
		return 1;
	}
	if(i<-1)
	{
		cout<<"give suitable value for i"<<endl;
		return -1;
	}
	if( i==0)
	{
		node *a=head->addr;
		head->addr=a->addr;
		if(a->addr==NULL)
		{
			tail=head;
		}
		delete a;
		return 1;
	}

	int res=deleteRecurrsive(head->addr,--i,tail);
	 return (res==1)?1:-1;


}
node* deleteatindex(node *head,int i,node *& tail)
{
	
	int count=0;
	node *temp=head;
	if(i<0){
	 
	    cout<<"please give suitable index "<<endl;
		return head;
	}
	if(i==0){
		head=head->addr;
		delete temp;
		return head;
	}
 
	while(temp!=NULL && count< i-1){
		temp=temp->addr;
		count++;
		
	}

	if(temp!=NULL){
		if( count==i-1 && (temp->addr)->addr==NULL )
		{
			tail=temp;
		}
		node *a=temp->addr;
		temp->addr=a->addr;
		delete a;

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
	// cout<<"length of link list is : "<<lengthOfLL(head,0)<<endl;
	// cout<<lengthOfLLrecursive(head,0)<<endl;
	
	// cout<<"To find the value at index i give i ? :"<<endl;
	// int index=0;
	// cin>>index;
	// cout<<atindex(head,index)<<endl;
    
	// cout<<"To insert node  at index i give i ? :"<<endl;
	// int in=0;
	// cin>>in;

	// cout<<"Data ? :"<<endl;
	// int data=0;
	// cin>>data;
	// head=insertatindex(head,in,data,tail);
	// printLL(head);
	// cout<<"first item data "<<head->data<<endl;
	// cout<<"last item data "<<tail->data<<endl;
   
 //    cout<<"To insert node  at index i give i ? :"<<endl;
	// int in=0;
	// cin>>in;
 //    cout<<"Data ? :"<<endl;
	// int data=0;
	// cin>>data;
	// int res=insertRecurrsive(head,in-1,data,tail);
	// if(res==-1)
	// {
	// 	cout<<"pls give suitable index"<<endl;
	// }
	// printLL(head);
	// cout<<"first item data "<<head->data<<endl;
	// cout<<"last item data "<<tail->data<<endl;
    

	// cout<<"To delete node  at index i give i ? :"<<endl;
	// int de=0;
	// cin>>de;

	
	// head=deleteatindex(head,de,tail);
	// printLL(head);
	// cout<<"first item data "<<head->data<<endl;
	// cout<<"last item data "<<tail->data<<endl;


   
 //    cout<<"To delete node  at index i give i ? :"<<endl;
	// int de=0;
	// cin>>de;

	
	// int res=deleteRecurrsive(head,de-1,tail);
	// if(res==-1)
	// {
	// 	cout<<"pls give suitable index"<<endl;
	// }
	// printLL(head);
	// cout<<"first item data "<<head->data<<endl;
	// cout<<"last item data "<<tail->data<<endl;
   
	
   
}
