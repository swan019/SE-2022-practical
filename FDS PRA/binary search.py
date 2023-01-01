
print("phonebook application",end="\n")
import math
def nr_binsearch(phbk,low,high,key):
    mid=0
    print(low," ",mid," ",high)
    while (low<=high):
        print("bm_low val :",low)
        print("bm_high val:",high)
        s1=low+high
        print("s1 :",s1)
        m1=s1/2
        print("m1 val :",m1)
        mid=math.ceil(m1)
        print("mid val :",mid)
        if (phbk[mid][0]==key):
            return mid
        elif (phbk[mid][0]<key):
            low=mid+1
            print("low val :",low)
            print("high val :",high)
        elif (phbk[mid][0]>key):
            high=mid-1
            print("high val :",high)
    return -1 
def insert(phbk,x1):
    c=[x1]
    mob=int(input("Enter mobile number of your friend"))
    c.append(mob)
    print(c)
    phbk.append(c)
    print(phbk)
    print("But for binary and fibonacci search record must be in a sorted order in phonebook")
    sort(phbk)
def sort(phbk) :
    for j in range (len(phbk)):
        swapped = False 
        i=0
        while i<len(phbk)-1:
            if phbk[i][0]>phbk[i+1][0]:
                phbk[i],phbk[i+1]=phbk[i+1],phbk[i]
                swapped=True
            i=i+1
        if swapped==False :
            break
    print("*** after sorting the data in phonebook ....***")
    print(phbk)
def binary_search (arr,low,high,x):
    if high>=low:
        mid=(high+low)//2
        if arr[mid][0]==x:
            return mid
        elif arr[mid][0]>x:
            return binary_search(arr,low,mid-1,x)
        else:
            return binary_search(arr, mid+1, high, x)
        
    else:
        return -1

phbk = [["amol",1234567892],["bavesh",2132654522],["chetan", 9923511212], ["dheeraj", 9823463224], ["eravati", 8530770714]]
l1 = len(phbk)
print("Records present in phone book are as follows")
for i in range(l1):
    print(phbk[i])
    print()
x = input("Enter friend name u want to search:")
x1 = x.lower() 
print(x1)
result = nr_binsearch(phbk, 0, len(phbk) - 1, x1)

if result != -1:
    print(x1, "is present at index", str(result), "in phonebook")
else:
    print(x1, "is not present in phonebook")
    print("Friend", x1, "is now inserted in phonebook.....")
    insert(phbk, x1)
    print("Friend", x1, " info added successfully in phonebook.....")


def min(x,y):
    if (x<y):
        return x
    else:
        return y
def fibsearch(arr,x,n):
    f2=0
    f1=1
    fibM=f2+f1
    while (fibM<n):
        f2=f1
        f1=fibM
        fibM=f2+f1
        offset=-1
        while(fibM>1):
            i=min(offset+f2,n-1)
            if (arr[i][0]<x):
                fibM=f1
                f1=f2
                f2=fibM-f1
            else:
                return i
            if (f1 and arr[offset+i][0]==x):
                return offset + i
        return - 1

print("fibonacci search method :",end="\n")
phbk = [["amol",1234567892],["bavesh",2132654522],["chetan", 9923511212], ["dheeraj", 9823463224], ["eravati", 8530770714]]
n = len(phbk)
print("Records present in phone book are as follows")
for i in range(n):
    print(phbk[i])
    print()

x = input("Enter friend name u want to search:")
x1 = x.lower() 
print(x1)
result = fibsearch(phbk,x1,n)

if result != -1:
    print(x1, "is present at index", str(result), "in phonebook")
else:
    print(x1, "is not present in phonebook")
    print("Friend", x1, "is now inserted in phonebook.....")
    insert(phbk, x1)
    print("Friend", x1, " info added successfully in phonebook.....")