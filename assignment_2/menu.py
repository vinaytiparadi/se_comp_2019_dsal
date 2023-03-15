import Setoperations
import SetOperations_Self

def menu():
    ch="Y"
    while(ch=="Y" or ch =="y"):
        try:
            print("\n\n------------------------\n\n")
            print("<----SET OPS---->\t\t<----MULTI-SET OPS---->")
            print("1->Create a Set\t\t\t6->Intersection")
            print("2->Display Set\t\t\t7->Union")
            print("3->Remove a Set\t\t\t8->Diffrence")
            print("4->Contain Check\t\t9->Subset")
            print("5->Size\t\t\t\t10->Proper Subset")
            print("\n\t\t11->EXIT")
            chmain=int(input("Enter Your Choice: "))
            if(chmain==1):
                Setoperations.Add()
            if(chmain==2):
                Setoperations.Display()
            if(chmain==3):
                Setoperations.Remove()
            if(chmain==4): 
                Setoperations.IsContain() 
            if(chmain==5):
                Setoperations.Size()
            if(chmain==6):
                Setoperations.Intersection()
            if(chmain==7):
                Setoperations.Union()
            if(chmain==8):
                Setoperations.Diffrence()
            if(chmain==9):
                Setoperations.Subset()
            if(chmain==10):
                Setoperations.ProperSub()
            if(chmain==11):
                exit()
        except Exception as e:
            print("Following Error Occured: ",e)
        except KeyboardInterrupt:
            ch=input("Display Options (Y/N):")
        ch=input("Display Options (Y/N):")

def menu_self():
    ch="Y"
    while(ch=="Y" or ch =="y"):
        try:
            print("\n\n------------------------\n\n")
            print("<----SET OPS---->\t\t<----MULTI-SET OPS---->")
            print("1->Create a Set\t\t\t6->Intersection")
            print("2->Display Set\t\t\t7->Union")
            print("3->Remove a Set\t\t\t8->Diffrence")
            print("4->Contain Check\t\t9->Subset")
            print("5->Size\t\t\t\t10->Proper Subset")
            print("\n\t\t11->EXIT")
            chmain=int(input("Enter Your Choice: "))
            if(chmain==1):
                SetOperations_Self.Add()
            if(chmain==2):
                SetOperations_Self.Display()
            if(chmain==3):
                SetOperations_Self.Remove()
            if(chmain==4): 
                SetOperations_Self.IsContain() 
            if(chmain==5):
                SetOperations_Self.Size()
            if(chmain==6):
                SetOperations_Self.Intersection()
            if(chmain==7):
                SetOperations_Self.Union()
            if(chmain==8):
                SetOperations_Self.Diffrence()
            if(chmain==9):
                SetOperations_Self.Subset()
            if(chmain==10):
                SetOperations_Self.ProperSub()
            if(chmain==11):
                exit()
        except Exception as e:
            print("Following Error Occured: ",e)
        except KeyboardInterrupt:
            ch=input("Display Options (Y/N):")
        ch=input("Display Options (Y/N):")

def Menu_Init():
    print("<----AVAILABLE FUNCTIONALITIES---->\n1.PREDEFINED\n2.USER-DEFINED")
    Operation=int(input("Enter your choice: "))
    try:
        if (Operation==1):
            menu()
        elif(Operation==2):
            menu_self()
    except KeyboardInterrupt:
        ch=input("EXIT(Y/N)? ")
        if(ch=="Y"):
            exit()
        elif(ch=="N"):
            Menu_Init()
Menu_Init()
