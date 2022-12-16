#include<iostream>
using namespace std;
static int top=-1;
static char st[10];
static char s1[10];
static char s2[10];
int isstackfull()
{
    if(top==9)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isstackempty()
{
    if(top==-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
void push(char p)
{   top++;
    s1[top]=p;
    
}
char pop()
{   char d;
    d=s1[top];
    top=top-1;
    return d;
}
int main()
{   int x;
    cout<<"\n----------------\n1.Enter Word\n2.Display Reversed Word\n3.Check if entered word is PALINDROME\n4.Exit\nEnter your choice :";
    cin>>x;
    cout<<endl;
    if(x==1)
    {   int k=0;
        for(int s=0;s<10;s++)
        {
            s1[s]=0;
            s2[s]=0;
        }
        top=-1;
        char t;
        cout<<"Enter word which is to be reversed :";
        cin>>st;
        while(st[k]!='\0')
        {   t=st[k];
            if(isstackfull())
            {cout<<"Please enter small word !";
            break;}
            else
            {
                push(t);
                k++;
            }

        }

        main();
    }
    else if (x==2)
    {   char m;
        int g=0,flag=0;
        while(!isstackempty())
        {   m=pop();
            s2[g]=m;
            flag=1;
            g++;
           
        }
        if(flag==0)
        {
           cout<<"Sorry ,No word is entered !";
        }
        else{
            cout<<"Reversed word :"<<s2<<endl;
        }
        main();
    }
    else if (x==3)
    {
        if(st[0]==0)
        {
            cout<<"first enter and display reversed word !";
            main();
        }
        else if(s2[0]==0)
        {
            cout<<"first display reversed word !";
            main();
        }
        else{int h,flag1=0;
            for(h=0;h<10;h++)
            {
                if(st[h]!=s2[h])
                {
                    flag1=1;
                }
            }
            if(flag1==1)
            {
                cout<<"Entered word is not palindrome !";
            }
            else{
                cout<<"Entered word is palindrome !";
            }
            main();
        }
    }
    else if(x==4)
    {
        return 0;
    }
    else
    {
        cout<<"Please enter valid choice !";
        main();
    }
}

