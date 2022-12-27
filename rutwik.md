#include<iostream>
using namespace std;
class student
{
char *name,*dob,*bg,*class1,*div;
int roll_no;
public:
student()
{
name=new char[10];
dob=new char[10];
bg=new char[20];
class1=new char[20];
div=new char[20];
roll_no=0;
}
student(student &obj)
{
name=obj.name;
dob=obj.dob;
bg=obj.bg;
class1=obj.class1;
div=obj.div;
roll_no=obj.roll_no;
}
~student()
{
delete name;
delete dob;
delete bg;
delete class1;
delete div;
}
static int count;
static void totalrecord()
{
count++;
cout<<"Total number of records are:"<<count;
}
friend class studentinfo;
};
int student::count=0;
class studentinfo
{public:
char *address,*tele,*license;
studentinfo()
{ address=new char[10];
tele=new char[10];
license=new char[10];
}
studentinfo(studentinfo &obj)
{ address=obj.address;
tele=obj.tele;
license=obj.license;
}
~studentinfo()
{
delete address;
delete tele;
delete license;
}
friend class student;
void getdata(student *obj);
inline void header();
void display(student *obj);
};
void studentinfo::getdata(student *obj)
{ cout<<"Enter the name"<<endl;
cin>>obj->name;
cout<<"Enter the date of birth"<<endl;
cin>>obj->dob;
cout<<"Enter the blood group"<<endl;
cin>>obj->bg;
cout<<"Enter the class"<<endl;
cin>>obj->class1;
cout<<"Enter the div"<<endl;
cin>>obj->div;
cout<<"Enter the roll_no"<<endl;
cin>>obj->roll_no;
cout<<"Enter the address"<<endl;
cin>>this->address;
cout<<"Enter the telephone no."<<endl;
cin>>this->tele;
cout<<"Enter the license"<<endl;
cin>>this->license;
}
void studentinfo::header()
{ cout<<"name\tdob\tht\twt\taddress\ttele\tpolicy\tlisense"<<endl;
}
void studentinfo::display(student *obj)
{cout<<obj->name<<"\t"<<obj->dob<<"\t"<<obj->bg<<"t"<<obj->class1<<"\t"<<obj->div<<"\t"<<obj->roll_no<<"\t"<<address<<"\t"<<tele<<"\t"<<license;
}
int main()
{ char ans;
studentinfo p;
student *a[10];
studentinfo *b[10];
int ch;
int n;
do
{ cout<<"----------MENU----------"<<endl;
cout<<"1.Input"<<endl;
cout<<"2.Display"<<endl;
cout<<"3.Exit"<<endl;
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
cout<<"enter how many records you want to insert"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{ a[i]=new student;
b[i]=new studentinfo;
b[i]->getdata(a[i]);
student::totalrecord();
}
break;
case 2:
p.header();
for(int i=0;i<n;i++)
b[i]->display(a[i]);
break;
}
cout<<"\n Do you want to go main menu?(y/n):";
cin>>ans;
}
while(ans=='y');
return 0;}
