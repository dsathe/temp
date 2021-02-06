#include<iostream>
using namespace std;

class Job;
class node
{
	int pr;
	char name[5];
	node* next;
	friend class job;
public:
	node()
{ 
	pr=0;  next=NULL; name[0]='\0';
}

};

class job
{
        node* front;
        node* rear;
        public:
          job()
        {
                front=NULL;
                rear=NULL;
        }
        
        void insertfront()
        {
                node*new1=new node;        
                cout<<"Enter the name of job"<<endl;
                cin>>new1->name;
                cout<<"Enter the number"<<endl;
                cin>>new1->pr;
                if(front==NULL)
                {
                        new1->next=NULL;
                        front=new1;
                        rear=new1;
                }
                else
                {
                        new1->next=front;
                        front=new1;
                }
        }
        
        void insertrear()
        {
                node*new1=new node;        
                cout<<"Enter the name of job"<<endl;
                cin>>new1->name;
                cout<<"Enter the number"<<endl;
                cin>>new1->pr;
                if(front==NULL)
                {
                        new1->next=NULL;
                        front=new1;
                        rear=new1;
                }
                else
                {
                        new1->next=NULL;
                        rear->next=new1;
                        rear=new1;
                }
        }
        
        void deletefront()
        {
                node*p=front;
                if(p!=NULL)
               { 
                  if(front!=rear)
                  { 
                    p=p->next;
                    delete front;
                    front=p;
                  }
                  else
                  {
                        delete front;
                        front=NULL;
                        p=NULL;
                        rear=NULL; 
                  }
               }
               else
               {
               cout<<"UNDERFLOW"<<endl;
               } 
        }
        
        void display()
       {
                node*p=front;
                cout<<"The jobs are"<<endl<<endl;
                while(p!=NULL)
                {
                        cout<<p->name<<" "<<p->pr<<endl;
                        p=p->next;
                }
       }
       
         void deleterear()
       {
                     node*p=front;
                if(p!=NULL)
               { 
                  while(p->next!=rear)
                  {
                        p=p->next;
                  }
                  delete rear;
                  p->next=NULL;
                  rear=p;
               }
               else
               {
               cout<<"UNDERFLOW"<<endl;
               }    
       }
     
        
};

int main()
{
        job j1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                j1.insertrear();
        }
        j1.display();
        j1.insertfront();
        j1.display();
        j1.deletefront();
        j1.display();
        j1.deleterear();
        j1.display();
        
        return 0;
}
