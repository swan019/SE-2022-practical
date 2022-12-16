#include<iostream>
#include<string>
using namespace std;
class node
{   public:
    node *prev;
    int flag;
    int seatno;
    string moviename;
    float price;
    node *next;
};
class cinemax
{   public :
     node *arr[10];
    void create();
    void show();
    void book();
    void cancel();
    void available();
    int fun();
    cinemax()
    {int i;
        for(i=0;i<10;i++)
        {
            arr[i]=0;
        }
    }

};
void cinemax::create()
{
    int i,f;
    node *p,*t;
    for(i=0;i<10;i++)
    {
        for(f=0;f<7;f++)
        {
            p=new node;
            p->flag=0;
            p->seatno=f+1;
            p->moviename="KGF";
            p->price=150;
            p->next=p->prev=p;
            if(arr[i]==NULL)
            {
                arr[i]=p;
                t=p;
            }
            else{
                t->next=p;
                p->prev=t;
                p->next=arr[i];
                arr[i]->prev=p;
                t=p;
            }


        }
    }
}
void cinemax :: show()
{ node *g;
int i,j;
    for(i=0;i<10;i++)
    {   g=arr[i];
    cout<<"Row :"<<i+1<<"\n";
        for(j=0;j<7;j++)
        {   
            cout<<g->flag<<"|"<<g->seatno<<"|"<<g->moviename<<"|"<<g->price<<"|->";
            g=g->next;
        }
        cout<<endl;
    }
}
void cinemax::book()
{
    int i=0,m,k,f;
    node *t;
    cout<<"\nEnter Row Number :";
    cin>>m;
    if(m<=10)
    {
    cout<<"\nEnter Seat Number :";
    cin>>k;
    t=arr[m-1];
    for(f=0;f<7;f++)
    {
        if(t->seatno==k)
        {   if(t->flag==1)
        {
            cout<<"Seat is already Booked !";
            i=1;
            break;
        }
        else
        {
            t->flag=1;
            cout<<"Seat Booked Successfully !";
            i=1;
            break;
        }
        }
        t=t->next;
        
    }
        
    if(i==0)
    {
        cout<<"Enter valid seat number !";
    }
    }
    else
    {
        cout<<"Enter valid row number !";
    }
}
void cinemax :: cancel()
{
    int i=0,m,k,f;
    node *t;
    cout<<"\nEnter Row Number :";
    cin>>m;
    if(m<=10)
    {
    cout<<"\nEnter Seat Number :";
    cin>>k;
    t=arr[m-1];
    for(f=0;f<7;f++)
    {
        if(t->seatno==k)
        {   if(t->flag==0)
        {
            cout<<"Seat is already Empty !";
            i=1;
            break;
        }
        else
        {
            t->flag=0;
            cout<<"Seat Cancelled Successfully !";
            i=1;
            break;
        }
        }
        t=t->next;
        
    }
        if(i==0)
        {
            cout<<"Enter valid row number/seat number !";
        }
        
    
    }
    else
    {
        cout<<"Enter valid row number !";

    }


}
void cinemax :: available()
{
    int i,j;
    node *t;
    for(i=0;i<10;i++)
    {cout<<"\nRow "<<i+1<<" :";
        t=arr[i];
        for(j=0;j<7;j++)
        {
            if(t->flag==0)
            {
                cout<<t->seatno<<"|";
            }
            t=t->next;
        }

    }
}

int cinemax :: fun()
{   int x;
    cout<<"\nWELCOME TO CINEMAX THEATRE BOOKING PORTAL";
    cout<<"\n1.Display list of available seats\n2.Book seat\n3.Cancel booked seat\n4.Exit\nEnter your choice :";
    cin>>x;
    if(x==1)
    {
        available();
        fun();
    }
    else if(x==2)
    {
        book();
        fun();
    }
    else if(x==3)
    {
        cancel();
        fun();
    }
    else if(x==4)
    {
        return 0;
    }
    else
    {
        cout<<"Enter valid choice !";
        fun();
    }
}
int main()
{
    cinemax c;
    c.create();
    c.show();
    c.fun();
}