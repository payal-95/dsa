set1 = [10,20,30,40,50]
set2 = [20,40,50,60,70]
list3 = []
list4 = []
list5 = []
print("********* Menu *********")
print("1.Add\n2.remove\n3.Display\n4.Search\n5.Size\n6.Intersection\n7.Union\n8.Difference\n9.Subset")
ch = 0
while ch != 10:
    ch = int(input("\nEnter choice: "))

    if ch == 1:
        print("for set1")
        print("Enter Element: ")
        for i in range(5):
            x = int(input())
            set1.append(x)

        print("for set2")
        print("Enter Element: ")
        for i in range(5):
            x = int(input())
            set2.append(x)

    elif ch == 2:
        k = int(input("Enter Set Number: "))
        if k == 1:
            a = int(input("enter element to be deleted: "))
            set1.remove(a)

        else:
            a = int(input("enter element to be deleted: "))
            set2.remove(a)

    elif ch == 3:
        for i in set1:
            print(i)
        print("")
        for i in set2:
            print(i)

    elif ch == 4:
        flag = 0
        k = int(input("enter element to be searched: "))
        for i in set1:
            if i == k:
                flag = 1
        for j in set2:
            if j == k:
                flag = 2

        if flag == 1:
            print("Element found in set1 !!")

        elif flag == 2:
            print("Element found in set2 !!")

        else:
            print("Not Found !!!!!!!!")


    elif ch == 5:
        print("Size of set1 is: ", len(set1))
        print("Size of set2 is: ", len(set2))

    elif ch == 6:
        for i in set1:
            for j in set2:
                if i == j:
                    list3.append(i)
        print("Intersection is :", list3)

    elif ch == 7:
        for i in set1:
            list4.append(i)
        for j in set2:
            if j not in list4:
                list4.append(j)
        print("Union is :", list4)

    elif ch == 8:
        print("Set1-Set2")
        for i in set1:
            if i not in list3:
                list5.append(i)
        print(list5)
        list5.clear()

        print("Set2-Set1")
        for i in set2:
            if i not in list3:
                list5.append(i)
        print(list5)
        list5.clear()

    elif ch == 9:
        b = int(input("Enter no. of elements to be inserted: "))
        print("Enter elements: ")
        for i in range(b):
            e = int(input())
            list5.append(e)

        flag1 = 0
        for j in list5:
            if j not in set1:
                flag1 = 1

        if flag1 == 0:
            print("It is a subset of set1 !!")
        else:
            print("Not a Subset of set1 !!")

        flag2 = 0
        for k in list5:
            if k not in set2:
                flag2 = 1

        if flag2 == 0:
            print("It is a subset of set2 !!")
        else:
            print("Not a Subset of set2 !!")
