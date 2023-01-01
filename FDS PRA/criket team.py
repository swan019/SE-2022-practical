def removeDuplicate(t):
    l1 = []
    for i in t:
        if i not in l1:
            l1.append(i)
    return l1


# Intersection of two lists
# A & B

def intersection(lst1, lst2):
    lst3 = []
    for value in lst1:
        if value in lst2:
            lst3.append(value)
    # lst3 = [value for value in lst1 if value in lst2]
    return lst3


# Union of two lists
# A | B

def union(lst1, lst2):
    lst3 = lst1.copy()
    for value in lst2:
        if value not in lst3:
            lst3.append(value)
    return lst3


# Difference of two lists
# A - B

def difference(lst1, lst2):
    lst3 = []
    for value in lst1:
        if value not in lst2:
            lst3.append(value)
    return lst3


# Symmetric Difference of two lists
# A ^ B == (A - B) | (B - A)

def symmetricDiff(lst1, lst2):
    lst3 = []
    d1 = difference(lst1, lst2)
    d2 = difference(lst2, lst1)
    lst3 = union(d1, d2)
    return lst3


# Number of students who neither played Cricket nor Badminton = SeComp - (Cricket | Badminton)

def nCnB(lst1, lst2, lst3):
    lst4 = difference(lst1, union(lst2, lst3))
    print(lst4)
    return lst4, len(lst4)

SeComp = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"]
Cricket = ["a", "c", "e", "f", "c", "a", "i", "j"]
Badminton = ["c", "b", "e", "h", "b", "g"]
Football = ["b", "d", "e", "j"]

# Remove Duplicates
Cricket = removeDuplicate(Cricket)
Badminton = removeDuplicate(Badminton)
Football = removeDuplicate(Football)

flag = 1
while flag == 1:
    print("/****MENU*****/")
    print("1. List of students who played both Cricket and Badminton ")
    print("2. list of students who play either cricket or badminton but not both ")
    print("3. Number of students who play neither cricket nor badminton ")
    print("4. Number of students who play both Cricket and Football but not Badminton")
    print("5. Exit ")
    choice = int(input("Enter your choice : "))

    if choice == 1:
        print(" Cricket : ", Cricket)
        print(" Badminton : ", Badminton)
        print(" List of students who played both Cricket and Badminton : ")
        print(intersection(Cricket, Badminton))

    elif choice == 2:
        print(" Cricket : ", Cricket)
        print(" Badminton : ", Badminton)
        print(" list of students who play either cricket or badminton but not both ")
        print(symmetricDiff(Cricket, Badminton))

    elif choice == 3:
        print(" Class : ", SeComp)
        print(" Cricket : ", Cricket)
        print(" Badminton : ", Badminton)
        l, cnt = nCnB(SeComp, Cricket, Badminton)
        print("Number of students who play neither cricket nor badminton : ", cnt)
        print("List of students who play neither cricket nor badminton : ", l)
    elif choice == 4:
        print(" Class : ", SeComp)
        print(" Cricket : ", Cricket)
        print(" Badminton : ", Badminton) 
        i1 = intersection(Cricket,Football)
        d1=difference(i1,Badminton)
        print("Number of students who play Cricket and Football but not Badminton:", len(d1) )
        print("List of students who play Cricket and Football but not Badminton:", d1) 

    else:
        print("Wrong choice")
        flag = 0