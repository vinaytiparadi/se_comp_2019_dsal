

# print("|----PREDEFINED IMPORT SUCCESSFUL----|")
def askset_self():
    try:
        ch = input("Which Set Do You Want To Perform Operation on(A/B)")
        return ch
    except KeyboardInterrupt:
        return 0


def Add():
    try:
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            ch = askset_self()
            ch2 = "Y"
            if(ch == "A"):
                if(len(SetA) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetA)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to add to the set: ")
                    SetA.add(val)
                    ch2 = input("Add More in Set A (Y/N): ")
            elif(ch == "B"):
                if(len(SetB) == 0):
                    print("Set is currently empty")
                else:
                    print("Current Set: ", SetB)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to add to the set: ")
                    SetB.add(val)
                    ch2 = input("Add More in Set B (Y/N): ")
            ch3 = input(" Continue (Y/N): ")
    except KeyboardInterrupt:
        return 0


def Display():
    try:
        print("Set A : ", SetA)
        print("Set B : ", SetB)
    except KeyboardInterrupt:
        return 0


def Remove():
    try:
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            ch = askset_self()
            ch2 = "Y"
            if(ch == "A"):
                if(len(SetA) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetA)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to delete from the set: ")
                    SetA.discard(val)
                    ch2 = input("Delete More from Set A (Y/N): ")
            elif(ch == "B"):
                if(len(SetB) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetB)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to Delete from the set: ")
                    SetB.discard(val)
                    ch2 = input("Delete More from Set B (Y/N): ")
            ch3 = input(" Continue (Y/N): ")
    except KeyboardInterrupt:
        return 0


def IsContain():
    try:
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            val = input("Enter the value which you want to search: ")
            S1 = val in SetA
            S2 = val in SetB
            if(S1 == True and S2 == True):
                print("Element found on Both Sets")
            elif(S1 == True):
                print("Element found on Set A")
            elif(S2 == True):
                print("Element found on Set B")
            ch3 = input(" Search Again (Y/N): ")
    except KeyboardInterrupt:
        return 0


def Size():
    try:
        ch = askset_self()
        if(ch == "A"):
            if(len(SetA) == 0):
                print("Set is empty.")
            else:
                print("Set A : ", SetA)
                print("Size : ", SetA.__len__())

        elif(ch == "B"):
            if(len(SetB) == 0):
                print("Set is empty.")
            else:
                print("Set A : ", SetB)
                print("Size : ", SetB.__len__())
    except KeyboardInterrupt:
        return 0


def Intersection():
    try:
        print("A ∩ B =", SetA.intersection(SetB))
    except KeyboardInterrupt:
        return 0


def Union():
    try:
        print("A ∪ B =", SetA.union(SetB))
    except KeyboardInterrupt:
        return 0


def Difference():
    try:
        ch = input("1.A - B\n2.B - A ")
        if(ch == "1"):
            print("A - B = ", SetA.difference(SetB))
        elif(ch == "2"):
            print("B - A = ", SetB.difference(SetA))
        else:
            print("INVALID INPUT")
            Difference()
    except KeyboardInterrupt:
        return 0


def Subset():
    try:
        ch = input("1.A ⊆ B\n2.B ⊆ A ")
        if(ch == "1"):
            if(SetA.issubset(SetB)==True):
                print("A is the a Subset of B")
            else:
                print("A is not a Subset of B")
        elif(ch == "2"):
            if(SetB.issubset(SetA)==True):
                print("B is the a Subset of A")
            else:
                print("B is not a Subset of A")
        else:
            print("INVALID INPUT")
            Subset()
    except KeyboardInterrupt:
        return 0


def ProperSub():
    try:

        if(SetA==SetB):
            print("The Sets Are Proper Subset")
    except KeyboardInterrupt:
        return 0
SetA = set()
SetB = set()
