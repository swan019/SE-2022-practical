#include<iostream>
using namespace std;

class node{
    public:
	int prnno;
	char a[20];
	node *next;
	
};

class pinclub{
    public:
	node *start,*start1;
    node* create();
    node* insertfirst();
    void insertmiddle(node *s1);
    void insertlast(node *s1);
    node* deletefirstnode(node *s1);
    void deleteanynode(node *s1);
    void deletelastnode(node *s1);
	void search(node *s1);
    void count(node *s1);
    void concat(node *s1, node *s2);
    void display(node *s1);
    void fun();

	
	pinclub()
    {
        start=NULL;
        start1=NULL;
        
    }
};


node* pinclub::create(){
	node *p,*t1;
	p=new node;
	cout<<"Enter the prn number:";
	cin>>p->prnno;
	cout<<"Enter the name:";
	cin>>p->a;
	p->next=NULL;
    if(start1==NULL)
	{start1=p;
    t1=p;}
    else{
        t1->next=p;
        t1=p;
    }
	cout<<"\nStart node add is:"<<start1<<endl;
	return start1;
}
node* pinclub :: insertfirst()
{   node *p;
	p=new node;
	cout<<"Enter the prn number:";
	cin>>p->prnno;
	cout<<"Enter the name:";
	cin>>p->a;
    if(start==NULL)
    {
        start=p;
	p->next=NULL;

    }
    else{
        p->next=start;
        start=p;
    }
    
    
    return start;
}
void pinclub :: insertmiddle(node *s1)
{
    node *p;
    int x,flag=0;
        if (s1==NULL)
        {
            cout<<"Please add president !";
        }
        else{
            p=new node;
            cout<<"\nenter prn no :";
            cin>>p->prnno;
            cout<<"\nenter name :";
            cin>>p->a;
            p->next=NULL;
            cout<<"enter prn no after which you want to add data :";
            cin>>x;
            while(s1!=NULL)
            {   if(s1->prnno==x)
            {
                p->next=s1->next;
                s1->next=p;
                flag=1;
                break;
            }
                s1=s1->next;
            }
            if(flag==0)
            {
                cout<<"Enter valid prn no !";
            }
            
        }
    
}
void pinclub :: insertlast(node *s1)
{
    node *p;
    int x;
    if(s1==NULL)
    {
        cout<<"Please add president !";
    }
    else
    {
    p=new node;
    cout<<"\nenter prn no :";
    cin>>p->prnno;
    cout<<"\nenter name :";
    cin>>p->a;
    p->next=NULL;
    while(s1->next!=NULL)
    {
        s1=s1->next;
    }
    s1->next=p;}
}
node* pinclub :: deletefirstnode(node *s1)
{start=s1->next;
delete s1;
return start;

} 
void pinclub::deleteanynode(node *s1)
{   int x,flag;
    node *t1;
    flag=0;
    t1=s1;
    cout<<"\nenter prn no. you want to delete :";
    cin>>x;
    while(s1->next!=NULL)
    {
        if(s1->prnno==x)
        {flag=1;}
        if (flag==1)
        {  
            t1->next=s1->next;
            delete s1;
        }
        t1=s1;
        s1=s1->next;
    }
    if(flag==0)
    {
        cout<<"Enter valid prn no !";
    }

}
void pinclub :: deletelastnode(node *s1)
{node *t1;
while(s1->next!=NULL) 
{t1=s1;
s1=s1->next;} 
t1->next=NULL;
delete s1;
} 
void pinclub :: search(node *s1)
{   int a,flag=0;
    cout<<"\nenter the prn no you want to search :";
    cin>>a;
    while(s1!=NULL)
    {
        if(s1->prnno==a)
        {
            cout<<"\nentered prn no. exist";
            flag=1;

        }
        s1=s1->next;

    }
    if(flag==0)
    {
        cout<<"\nentered prn no. doesn't exist";
    }
}

void pinclub :: count(node *s1)
{int i=0;
    while(s1!=NULL)
    {
        i=i+1;
        s1=s1->next;
    }
    cout<<"Total Number of Members in Club :"<<i<<endl;
}
void pinclub :: concat(node *s1, node *s2) 
{ while(s1->next!=NULL) 
{s1=s1->next;} 
s1->next=s2;
} 
void pinclub::display(node *s1)
{
    while(s1!=NULL)
	{
		cout<<"|"<<s1->prnno<<" |"<<s1->a<<" |"<<s1->next<<" |--->";
		s1=s1->next;
	}
	
}
void pinclub :: fun()
{	int val,val1,val2,k;
    static node *head,*head1;
cout<<"\nWelcome To Pinnacle Club\n";
cout<<"1.Add Member\n"<<"2.Delete Member\n"<<"3.Search Member\n"
<<"4.Display list of Members\n"<<"5.Display count of Members\n"<<"6.Concatenation of two lists\n"<<"Enter your Choice :";
cin>>val;
if(val==1)
{
    cout<<"\n1.President\n2.Member\n3.Secretary\nEnter Your Choice :";
    cin>>val1;
    {
        if(val1==1)
        {
            head=insertfirst();
            cout<<"\nStart node add is:"<<head<<endl;
            fun();
        }
        else if(val1==2)
        {
           insertmiddle(head);
           fun();
        }
        else if(val1==3)
        {
            insertlast(head);
            fun();
        }
        else{
            cout<<"Enter valid choice";
            fun();
        }
    }
}
else if(val==2)
{
    cout<<"\n1.President\n2.Member\n3.Secretary\nEnter Your Choice :";
    cin>>val1;
    {
        if(val1==1)
        {
            head=deletefirstnode(head);fun();
        }
        else if(val1==2)
        {
            deleteanynode(head);fun();
        }
        else if(val1==3)
        {
        deletelastnode(head);fun();
        }
        else{
            cout<<"Enter valid choice";fun();
        }
    }
}
else if(val==3)
{
    search(head);fun();
}
else if(val==4)
{
   display(head);fun();
}
else if(val==5)
{
    count(head);fun();
}
else if(val==6)
{
    cout<<"Enter the number of members of club in other division :";
    cin>>val2;
    for(k=0;k<val2;k++)
    {
        head1=create();
    
    }
    concat(head,head1);
    cout<<"Concated List :\n";
    display(head);
    fun();
}
else{
    cout<<"Enter valid choice!";
    fun();
}
}
int main(){pinclub p;
p.fun();}