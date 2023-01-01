
import array as arr
def accept_perc():
    a=arr.array('f',[])
    no_stud=int(input("enter the number of students :"))
    for i in range (0,no_stud):
        a.append(float(input("enter the first year % of student[{0}]: ".format(i))))
    return a
def print_perc(a):
    for i in range(0,len(a)):
        print("\t{0:.2f}".format(a[i]),end=" ")
    print()
def partition(a,start,end):
    pivot=a[start]
    low=start+1
    high=end
    while True:
        while low<=high and a[high]>=pivot:
            high=high-1
        while low<=high and a[low]<=pivot:
            low=low+1
        if low<=high :
            a[low],a[high]=a[high],a[low]
        else:
            break
    a[start],a[high]=a[high],a[start]
    return high
def quick_sort(a,start,end):
    if start>=end:
        return
    p=partition(a,start,end)
    quick_sort(a,start,p-1)
    quick_sort(a,p+1,end)
    return a
def top_five(a):
    print("top five score are :")
    cnt=len(a)
    if cnt<5:
        start,stop=cnt-1,-1
    else:
        start,stop=cnt-1,cnt-6
    for i in range(start,stop,-1):
        print("\t{0:.2f}".format(a[i]),end=" ")
#if name=="main":
    #driver program if name=="main":
unsort_A=arr.array('f',[])
quick_sort_A=arr.array('f',[])
flag=1

while flag==1:
    print("\n 1.Accept array elements \n 2.Display the elements \n 3.quik sort \n 4.exit")
    choice=int(input("Enter your choice:"))
    if choice==1:
        unsort_A=accept_perc()
    elif choice==2:
        print_perc(unsort_A)
    elif choice==3:
        print("Elements after sorting using Insertion")
        quick_sort_A=quick_sort(unsort_A,0,len(unsort_A)-1)
        print_perc(quick_sort_A)
        top_five(quick_sort_A)
    else:
        print("wrong choice")
        flag=0