from numpy import *

# print("|----USER-DEFINED IMPORT SUCCESSFUL----|\n")

def askset():
    try:
        ch = input("Which Set Do You Want To Perform Operation on(A/B)")
        return ch
    except KeyboardInterrupt:
        return 0

def Lst_To_Set(TempSet,FinalSet):
    for i in TempSet:
        if i not in FinalSet:
            FinalSet.append(i)

def Delete_Self_Main(FinalSet,delval):
    for val in FinalSet:
        if(val==delval):
            FinalSet.remove(delval)
    return 0

def Diffrence_Self_Main(Set1,Set2):
    Diff=[]
    for i in Set1:
        if i not in Set2:
            Diff.append(i)
    return Diff

def Add():
    try:
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            ch = askset()
            ch2 = "Y"
            if(ch == "A"):
                if(len(SetA) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetA)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to add to the set: ")
                    TempSetA.append(val)
                    ch2 = input("Add More in Set A (Y/N): ")
                Lst_To_Set(TempSetA,SetA)
            elif(ch == "B"):
                if(len(SetB) == 0):
                    print("Set is currently empty")
                else:
                    print("Current Set: ", SetB)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to add to the set: ")
                    TempSetB.append(val)
                    ch2 = input("Add More in Set B (Y/N): ")
                Lst_To_Set(TempSetB,SetB)
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
            ch = askset()
            ch2 = "Y"
            if(ch == "A"):
                if(len(SetA) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetA)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to delete from the set: ")
                    Delete_Self_Main(SetA,val)
                    ch2 = input("Delete More from Set A (Y/N): ")
            elif(ch == "B"):
                if(len(SetB) == 0):
                    print("Set is currently empty.")
                else:
                    print("Current Set: ", SetB)
                while(ch2 == "Y" or ch2 == "y"):
                    val = input("Enter Value you want to Delete from the set: ")
                    Delete_Self_Main(SetB,val)
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
            else:
                print("Element Not found on Both Sets")
            ch3 = input(" Search Again (Y/N): ")

    except KeyboardInterrupt:
        return 0

def Size():
    try:
        ch = askset()
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            if(ch == "A"):
                if(len(SetA) == 0):
                    print("Set is empty.")
                else:
                    print("Set A : ", SetA)
                    print("Size : ", len(SetA))

            elif(ch == "B"):
                if(len(SetB) == 0):
                    print("Set is empty.")
                else:
                    print("Set B : ", SetB)
                    print("Size : ", len(SetB))
            ch3 = input(" Search Again (Y/N): ")
    except KeyboardInterrupt:
        return 0

def Intersection():
    try:
        Intersection=[]
        for vals in SetA:
            if vals in SetB:
                Intersection.append(vals)
        print("A ∩ B =", Intersection)
    except KeyboardInterrupt:
        return 0

def Union():
    try:
        Union_Temp=SetA+SetB
        Union_Final=[]
        Lst_To_Set(Union_Temp,Union_Final)
        print("A ∪ B =",Union_Final)
    except KeyboardInterrupt:
        return 0

def Difference():
    try:
        ch3 = "Y"
        while(ch3 == "Y" or ch3 == "y"):
            ch = input("1.A - B\n2.B - A ")
            if(ch == "1"):
                print("A - B = ", Diffrence_Self_Main(SetA,SetB))
            elif(ch == "2"):
                print("B - A = ", Diffrence_Self_Main(SetB,SetA))
            else:
                print("INVALID INPUT")
                Difference()
        ch3 = input(" Search Again (Y/N): ")
    except KeyboardInterrupt:
        return 0

def Subset():
    CheckSetA=SetA==SetB
    CheckSetB=SetA==SetB
    try:
        ch = input("1.A ⊆ B\n2.B ⊆ A ")
        if(ch == "1"):
            if(all(CheckSetA)==True):
                print("A is the a Subset of B")
            else:
                print("A is not a Subset of B")
        elif(ch == "2"):
            if(all(CheckSetB)==True):
                print("B is the a Subset of A")
            else:
                print("B is not a Subset of A")
        else:
            print("INVALID INPUT")
            Subset()
    except KeyboardInterrupt:
        return 0
    
def ProperSub():
    CheckSetA=SetA==SetB
    CheckSetB=SetA==SetB
    try:
        if(all(CheckSetA)==True and all(CheckSetB)==True):
            print("The Sets Are Proper Subset")
    except KeyboardInterrupt:
        return 0
    


TempSetA=[]
TempSetB=[]
SetA=[]
SetB=[]