marks=['ab',12,22,20,23,24,25,'ab',25,21,25,'ab',22,'ab',25,28]
List1 = []
List2 = []
List3 = []

for i in marks :
        if type(i)==type(" ") :
          List1.append(i)
        else :
          List2.append(i)
def absent() :
    n=len(List1)
    print("absent :",n)

def avg():
    n=len(List2)
    sum=0
    for i in List2 :
        sum=sum+i
    aveg=sum/n
    print("The Average Score of Class is :",aveg)
def high():
    h=0
    for i in List2 :
        if i>h :
          h=i
    print("Highest score of Class is :",h)
def low() :
    l=31
    for i in List2 :
        if i<l :
          l=i
    print("Lowest score of Class is :",l)
def frequency() :
    for i in range (31):
        hi=0
        for k in List2 :
            if i==k :
                hi=hi+1
        List3.append(hi)
    print(List3)
def mile():   
    j=0    
    for h in List3 :
        
        if h>j :
          j=h
    print(j)

    for z in range (31) :
        if List3[z]==j :
            mm=z
    print("mark with highest frequency are :",mm)
def mainmenu() :
    print("/*************MENU**************/")
    print("1. The average score of class ")
    print("2. Highest score and lowest score of class ")
    print("3. Count of students who were absent for the test ")
    print("4. Display mark with highest frequency ")
    print("5. Exit ")
    choice = int(input("Enter your choice : "))

    if choice == 1:
        avg()
        mainmenu()

    elif choice == 2:
        high()
        low()
        mainmenu()

    elif choice == 3:
        absent()
        mainmenu()
    elif choice == 4:
        frequency()
        mile()
        mainmenu()

    else:
        print("Wrong choice")
    
        
mainmenu()
