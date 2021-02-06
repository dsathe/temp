#include <iostream>
#include <string.h>
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
	d='\0';	pnr=0;  next=NULL; name[0]='\0';
}
};



class linkedlist
{
	node* start;
	node* last;
	int loc;

public:
	linkedlist()
{
		start=NULL;
		last=NULL;
		loc=2;

}

	void insert()
{
		//node* new1;

	node	*new1=new node;
	     if(start==NULL)
	     {
	    	cout<<"enter the name ,pnr of president\n";
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
		// node* new1;

		int count =2;

	node *p=start;
		 node *new1 =new node;
        cout<<"enter the name ,pnr";
	    cin>>new1->name;
		cin>>new1->pnr;
		new1->d='m';
		while(count<loc&&p!=NULL)
		{
			p=p->next;
			count++;
		}
		loc++;
		new1->next=p->next;
		p->next=new1;



	}


	void display()
	{
		//node* p;
		node *p=start;
		do
		{
			cout<<p->name<<"\t"<<p->pnr<<"\t"<<p->d<<"\n";
			p=p->next;
		}while(p!=NULL);

	}


	void count()
	{
		node *p=start;
		int count=0;
		while(p!=NULL)
		{
			p=p->next;
			count++;
		}
		cout<<"the count of members are"<<count<<"\n";
	}

	void reverselist(node* p)
	{
		if(p==NULL)
		{
			return;
		}
		reverselist(p->next);
		cout<<p->name<<"\t"<<p->pnr<<"\t"<<p->d<<"\n";
	}


	void concatinate(linkedlist m)
	{
		node *p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=m.start;
		p->d='m';
		p=p->next;
		p->d='m';
		last=m.last;
        cout<<"do you want to sort conactinated list";
        int z;cin>>z;
        if(z==1)
		{
        	sortt();
        	display();
		}
        else
        {
        	display();
        }

	}

	void sortt()
	{
		node* p=start;
		node* temp=start->next;
		int pnr1; char d1;int i=0,j=0;
			char n[12];

			node *q=start;
					int count=0;
					while(q!=NULL)
					{
						q=q->next;
						count++;
					}


		for(i=1;i<count;i++)
		{p=start;
		temp=start->next;
			for(j=0;j<=count-i-1;j++)
			{
			   if (p->pnr>temp->pnr)
			   {
				  pnr1=temp->pnr;
				  d1=temp->d;
				 strcpy(n,temp->name);

				  strcpy(temp->name,p->name);
				  temp->d=p->d;
				  temp->pnr=p->pnr;

				  p->d=d1;
				  strcpy(p->name,n);
				  p->pnr=pnr1;
			   }

				  temp=temp->next;
				  p=p->next;
			 }

		  }
		start->d='p';
		last->d='s';
		p=start->next;
		while(p->next!=NULL)
		{
			p->d='m';
			p=p->next;
		}


		display();
		}


      node* pointerr()
	{
		node *p=start;
		return p;	
	}

	void deleting()
	{
		int ch;int mem;
		node *p=start;
		cout<<"enter which member you want to delete\n";
		cout<<"1:president,2:secritery,3:member";
		cin>>ch;
		switch(ch)
		{
		case 1:

			p=start->next;
			start->next=NULL;
			delete start;
			start=p;
			p->d='p';
			break;
		case 2:
			if(start==last)

			while(p->next!=last)
			{
				p=p->next;
			}
		     p->next =NULL;
			delete last;
			last=p;
			p->d='s';
			break;
		case 3:
			int i=0;
			cout<<"enter which member you want to delete";
			cin>>mem;
			node *current=start;
			node *previous=NULL;
		    while(i<mem &&current!=NULL)
			{
				previous =current;
				current=current->next;
				i++;
			}
		    previous->next=current->next;
		    current->next=NULL;
		    delete current;

		}
	}


};




int main() {

	int x,ch,con=0;
	cout<<"enter number of members";
cin>>x;
	cout<<"enter the members in order president secritery and members\n";

	linkedlist l,l1;
	l.insert();
	l.insert();

	for(int i=0;i<x;i++)
	{
		l.insertmem();
	}

	do{
	cout<<"enter 1: display  2:display count 3:reverse string 4:conactinate 5:delete 6:sort";
	cin>>ch;
	switch(ch)
	{
	case 1:
	      l.display();
	      break;
	case 2:
	      l.count();
	      break;
	case 3:

	      l.reverselist(l.pointerr());

	      break;
	case 4:

	int t;
	cout<<"enter number of members";
	cin>>t;
	l1.insert();
	l1.insert();
	for(int i=0;i<t;i++)
	{
		l1.insertmem();
	}

	      l.concatinate(l1);
	      break;
	case 5:
		  l.deleting();
	      l.display();
	      break;
	case 6:
	      l.sortt();
	      break;
     }
	cout<<"do you want any other calculation if yes =1 and no=0 ";
	cin>>con;
	}while(con==1);
	return 0;
}

