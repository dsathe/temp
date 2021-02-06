//This is a .cpp file
#include<iostream>
#include<math.h>
using namespace std;
class poly;
class node
{
	int exp;
	int coef;
	node* next;
	friend class poly;
};

class poly

{
	node* last;	
	public:
		poly()
		{
			last=NULL;
		}
		void accept()
		{
		
			node*new1=new node;
			cin>>new1->coef;
			cin>>new1->exp;
			if(last==NULL)
			{
				new1->next=new1;
				last=new1;
			}
			else
			{
				new1->next=last->next;
				last->next=new1;
				last=new1;
			}
		}
		
		
		void display()
		{
			node*p=NULL;
			p=last->next;
			while(p!=last)
			{
				cout<<p->coef<<"x^"<<p->exp<<" + ";
				p=p->next;
			}
			cout<<p->coef<<"x^"<<p->exp<<endl;
		        
			
		}
		
		void eval()
		{
			int sum=0;int var;
			cout<<"Enter the value of x\n";
			cin>>var;
			node *p=last->next;
			do
			{
				sum=sum+p->coef*pow(var,p->exp);
				p=p->next;
			}while(p!=last->next);
			cout<<"The Value is:-\n"<<sum<<endl;
		}
		
		void create(int c,int e)
		{
			node*new1=new node;
			new1->coef=c;
			new1->exp=e;
			if(last==NULL)
			{
				new1->next=new1;
				last=new1;
			}
			else
			{
				new1->next=last->next;
				last->next=new1;
				last=new1;
			}
		}
		
		
		void add(poly q)
		{
			poly re;
			node*x=NULL;
			node*y=NULL;
			x=last->next;
			y=q.last;
			y=y->next;
			do
			{
				if(x->exp>y->exp)
				{
					re.create(x->coef,x->exp);
					x=x->next;
				}
				
				else if(x->exp<y->exp)
				{
					re.create(y->coef,y->exp);
					y=y->next;
				
				}
				
				else
				{
					int result=x->coef+y->coef;
					re.create(result,x->exp);
					x=x->next;
					y=y->next;
				}
			}while(x!=last->next||y!=(q.last)->next);
			
			while(x!=last->next)
			{
				re.create(x->coef,x->exp);
				x=x->next;
			}
			
			while(y!=(q.last)->next)
			{
				re.create(y->coef,y->exp);
					y=y->next;
			}
			
			node* xc=re.last;
			xc=xc->next;
			do
			{
				cout<<xc->coef<<"x^"<<xc->exp<<" + ";
				xc=xc->next;
			}while(xc!=re.last);
			cout<<xc->coef<<"x^"<<xc->exp<<endl;
		}
};

int main()
{
	poly p,q;int n;
	cout<<"Enter number of terms\n";
	cin>>n;
    cout<<"Enter the polynomial in decreasing order\n";
	for(int i=0;i<n;i++)
	{
		p.accept();
	}
	p.display();
	//p.eval();
	cout<<"Enter number of terms\n";
	cin>>n;
    cout<<"Enter the polynomial in decreasing order\n";
	for(int i=0;i<n;i++)
	{
		q.accept();
	}
	q.display();
	p.add(q);
	
	return 0;
}
