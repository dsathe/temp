#include <iostream>
using namespace std;



class linkedlist;
class node
{
	int pnr; char d;
	char name[12];
	node* next;
	friend class linkedlist;
public:
	node()
{
	d='\0';	pnr=0;  next=NULL;
}
};



class linkedlist
{
	node* start;
	node* last;


public:
	linkedlist()
{
		start=NULL;
		last=NULL;

}

	void insert()
{
		node* new1;

		new1=new node;
	     if(start==NULL)
	     {
	    	cout<<"enter the name ,pnr of president";
	    	cin>>new1->name;
	    	cin>>new1->pnr;
	    	new1->d='p';
	    	new1->next=NULL;
	    	start=new1;
	    	last=new1;

	     }

	     else if (start==last&&start!=NULL&&last!=NULL)
	     {
	    	 cout<<"enter the name ,pnr of secritery";
	    	 	    	cin>>new1->name;
	    	 	    	cin>>new1->pnr;
	    	 	    	new1->d='s';
	    	 	        new1->next=NULL;
	    	 	        last->next=new1;
	    	 	        last=new1;


	     }

}

	void insertmem()
	{
		 node* new1;
		static int loc=2;int count =1;
		 node* p;
		 p=start;
		new1 =new node;
        cout<<"enter the name ,pnr";
	    cin>>new1->name;
		cin>>new1->pnr;
		new1->d='m';
		while(count-1<loc&&p!=NULL)
		{
			p=p->next;
			count++;
		}
		new1->next=p->next;
		p->next=new1;


	}


	void display()
	{
		node* p;
		p=start;
		do
		{
			cout<<p->name<<p->pnr<<p->d<<"\n";
			p=p->next;
		}while(p->next==NULL);

	}

};




int main() {

	int x;
	cout<<"enter number of members";
	cin>>x;
	cout<<"enter the members in order president secritery and members";

	linkedlist l;
	l.insert();
	l.insert();
	for(int i=0;i<x;i++)
	{
		l.insertmem();
	}
	l.display();


	return 0;
}

