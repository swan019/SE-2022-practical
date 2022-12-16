print("Practical No 3 \nName : Atharva Babanrao Dere [SE-A]")
def accept (m,row,col) :
    for i in range (row) :
        c=[]
        for j in range (col):
            no=int(input("Enter value of matrix["+str(i)+"]["+str(j)+"]::"))
            c.append(no)
        print()
        m.append(c)
def show (m,row,col) :
    for i in range (row) :
        for j in range (col):
            print(m[i][j],end='  ')
        print()
def add_mat(m1,m2,row,col) :
    for i in range(row):
        for j in range (col):
            res[i][j]=n1[i][j]+n2[i][j]
def sub_mat(m1,m2,row,col) :
    for i in range(row):
        for j in range (col):
            res[i][j]=n1[i][j]-n2[i][j]
def mul_mat(n1,n2,row,col) :
    for i in range(row):
        for j in range (col):
            for k in range(col):
             res[i][j]=res[i][j]+n1[i][k]*n2[k][j]
def trans_mat(n,row,col) :
    for i in range (row) :
        for j in range(col):
            res[i][j]=n[j][i]
n=[]
n1=[]
n2=[]
res=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
print("basic matrix operation using matrices")
print("welcome all in assignment no 3 from group A")
row1=int(input("enter no of rows in first matrix :"))
col1=int(input("enter no of columns in first matrix :"))
row2=int(input("enter no of rows in second matrix :"))
col2=int(input("enter no of columns in second matrix :"))
def main() :
    print("1. accept two matrices from user :")
    print("2. show the matrices values :")
    print("3. addition of two matrices : ")
    print("4. substraction of two matrices :")
    print ("5. multiplication of two matrices: ")
    print("6. transpose of matrix :")
    print("7 .exit")
    ch = int(input("enter your choice :"))
    if ch==1 :
        print("please enter the values for first matrix :")
        accept(n1,row1,col1)
        print("please enter the values for second matrix :")
        accept(n2,row2,col2)
        main()
    elif ch==2 :
        print("the value of first matrix is as follows :")
        show(n1,row1,col1)
        print("the value of second matrix is as follows :")
        show(n2,row2,col2)
        main()
    elif ch==3 :
        print("the addition of two matrices are as follows :")
        if ((row1==row2) and (col1==col2)) :
            add_mat(n1,n2,row1,col1)
            show(res,row1,col1)
        else:
            print("sorry addition is not possible :")
        main()
    elif ch==4 :
        print("the substraction of two matrices are as follows...")
        if ((row1==row2) and (col1==col2)) :
            sub_mat(n1,n2,row1,col1)
            show(res,row1,col1)
        else :
            print("sorry!!! subtraction is not possible")
        main()
    elif ch==5 :
        print("multiplication")
        if(col1==row2):
            mul_mat(n1,n2,row2,col1)
            show(res,row2,col1)
        else:
            print("sorry")
        main()
    elif ch==6 :
        print("before transpose")
        show(n1,row1,col1)
        print("after transpose")
        trans_mat(n1,row1,col1)
        show(res,row1,col1)
        main()
    elif ch==7 :
        exit
    else :
        print("please enter valid choice")
        main()
main()