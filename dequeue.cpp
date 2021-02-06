#include<iostream>
#include<string.h>
using namespace std;

class dequeue
{
        string a[10];
        int front;
        int rear;
        public:
        dequeue()
        {
                front =-1;
                rear=-1;
        }
        void insertfront();
        void insertrear();
        void deletefront();
        void deleterear();
        void display();
};

void dequeue::insertfront()
{
        cout<<"Enter the job name"<<endl;
        if(front==-1)
        {
                front=front+1;
                rear=rear+1;
                cin>>a[front];
        }
        else 
        {
                if(front==0&&rear==9)
                {
                        cout<<"Overflow"<<endl;
                }
                else if(front!=0)
                {
                        front=front-1;
                        cin>>a[front];
                }
                else
                {
                        for(int i=rear;i>=0;i--)
                        {
                                a[i+1]=a[i];
                        }
                        rear=rear+1;
                        cin>>a[0];
                }
                
        }
}

void dequeue::insertrear()
{
        cout<<"Enter the job name"<<endl;
        if(front==-1)
        {
                front=front+1;
                rear=rear+1;
                cin>>a[front];
        }
        else
        {
                if(front==0&&rear==9)
                {
                        cout<<"Overflow"<<endl; 
                }
                else if(front!=0&&rear==9)
                {       
                        for(int i=front-1;i<10;i++)
                        {
                                a[i]=a[i+1];
                        }
                        front--;
                        cin>>a[rear];
                }
                else
                {
                        rear=rear+1;
                        cin>>a[rear];
                }
        }
}
void dequeue::deletefront()
{
        cout<<"Deleting from front"<<endl;
        if(front==-1&&rear==-1)
        {
                cout<<"Underflow"<<endl;
        }
        else
        {
                if(front==rear)
                {
                        cout<<a[front]<<"Deleted"<<endl;
                        front=-1;
                        rear=-1;
                }
                else 
                {
                        cout<<a[front]<<"Deleted"<<endl;
                        front++;
                }        
        } 
}

void dequeue::deleterear()
{
        cout<<"Deleting from rear"<<endl;
        if(front==-1&&rear==-1)
        {
                cout<<"Underflow"<<endl;
        }
        else
        {
                if(front==rear)
                {
                        cout<<a[front]<<"Deleted"<<endl;
                        front=-1;
                        rear=-1;
                }
                else
                {
                         cout<<a[rear]<<"Deleted"<<endl;
                         rear--;
                }
        }
}

void dequeue::display()
{
        cout<<"Jobs are:-\n";
        for(int i=front;i<=rear;i++)
        {
                cout<<a[i]<<endl;
        }
}

int main()
{
        dequeue d;
        int n,ch;
        char q;
        cout<<"Enter number of jobs"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                d.insertrear();
        }
        d.display();
        do
        {
                cout<<"1:Insert job front\n2:Insert job at back\n3:Delete the job in front\n4:Delete job at the back\n";
                cin>>ch;
                switch(ch)
                {
                        case 1: d.insertfront();
                                d.display();
                                break;
                        case 2: d.insertrear();
                                d.display();
                                break;
                        case 3: d.deletefront();
                                d.display();
                                break;
                        case 4: d.deleterear();
                                d.display();
                                break;
                }
                cout<<"Do you want any other calculation?\n";
                cin>>q;
        }while(q=='y');
        return 0;
}
