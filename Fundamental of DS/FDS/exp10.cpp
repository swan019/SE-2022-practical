#include<iostream>
using namespace std;
class parenthesis
{   public :
    char st[20];
    char s1[20];
    int top;
    int isstackfull();
    int isstackempty();
    void push(char p);
    char pop();
    void checkwellness();
    parenthesis()
    {
        top=-1;
    }
};
int parenthesis :: isstackfull()
{
    if(top==19)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int parenthesis::isstackempty()
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void parenthesis :: push(char p)
{   
    top++;
    s1[top]=p;
}
char parenthesis :: pop()
{
    char y;
    y=s1[top];
    top--;
}
void parenthesis :: checkwellness()
{   int k=0;char s;
    cout<<"Enter the data :";
    cin>>st;
    while(st[k]!='\0')
    {
        s=st[k];
        if(s=='('||s=='['||s=='{')
        {
            push(s);
        }
        else if(s==')'||s==']'||s=='}')
        {
            pop();
        }
        k=k+1;
    }
    if(isstackempty())
    {
        cout<<"Entered data is Parenthesized";

    }
    else
    {
        cout<<"Entered data is not Parenthesized";
    }
    
}
int main()
{
    parenthesis d;
    d.checkwellness();
}