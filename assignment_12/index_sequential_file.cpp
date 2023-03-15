#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Employee
{
public:
    int EmpID;
    char EmpName[20];
    char EmpDesg[20];
    int EmpSal;

    void gInfo();
    void pInfo();
    void mod();
    void modindex(int,int);
    void apnd();
    void display();
    void search();
    void del();
    int getindex(int);
    void displayindex();
    void setindex(int);
    int delindex(int);
    void disp();
};

class index{
    public:
    int EmpInd;
};



int Employee::getindex(int srroll)
{
   fstream indexfile;
    index ind;
    char ch;
    int pos=0;
    int  flag = 0;
    indexfile.open("index.dat", ios::in | ios::binary);
    while (indexfile.read((char *)&ind, sizeof(ind)))
    {
        if (ind.EmpInd == srroll)
        {
            flag = 1;
            break;
        }
        pos=pos+48;

    }
    if (flag == 0)
    {
        cout << "Employee Not Found !!" << endl;
    }
    else{
        return pos;
    }
    indexfile.close();
    cout<<pos;
    cout << endl;
}
int Employee::delindex(int srroll)
{
    fstream mainfile;
    fstream tempfile("tempind.dat");
    index stud;
    string str;
    
    mainfile.open("index.dat", ios::in | ios::binary);
    tempfile.open("tempind.dat", ios::out | ios::binary);

    while (!mainfile.eof())
    {

        mainfile.read((char *)&stud, sizeof(stud));

        if (mainfile)
        {

            if (stud.EmpInd!= srroll)
            {
                tempfile.write((char *)&stud, sizeof(stud));
            }
        }
    }

    mainfile.close();
    tempfile.close();
    
    remove("index.dat");
    rename("tempind.dat", "index.dat");
    return 0;
}
void Employee::modindex(int srroll,int modroll)
{
    fstream mainfile;
    fstream tempfile("tempind.dat");
    index stud;
    string str;
    
    mainfile.open("index.dat", ios::in | ios::binary);
    tempfile.open("tempind.dat", ios::out | ios::binary);

    while (!mainfile.eof())
    {

        mainfile.read((char *)&stud, sizeof(stud));

        if (mainfile)
        {
            if (stud.EmpInd == srroll)
            {
                stud.EmpInd=modroll;
                tempfile.write((char *)&stud, sizeof(stud));
            }
            else
            {
                tempfile.write((char *)&stud, sizeof(stud));
            }
        }
    }

    mainfile.close();
    tempfile.close();
    
    remove("index.dat");
    rename("tempind.dat", "index.dat");
}

void Employee::setindex(int EmpID){
    ofstream setfile;
    Employee stud;
    index ind;
    ind.EmpInd=EmpID;
    setfile.open("index.dat", ios::app | ios::binary);
    setfile.write((char *)&ind, sizeof(ind));
    setfile.close();

}

void Employee::gInfo()
{
    index ind;
    cout << "Employee ID->";
    cin >> EmpID;
    setindex(EmpID);
    cout << "Salary->";
    cin >> EmpSal;
    cout << "Name->";
    cin >> EmpName;
    cout << "Designation->";
    cin >> EmpDesg;
}

void Employee::displayindex(){
    ifstream infile;
    index stud;
    char ch;
    infile.open("index.dat", ios::out | ios::binary);
    while (infile.read((char *)&stud, sizeof(stud)))
    {
        cout<<stud.EmpInd<<"\n";
    }
    infile.close();
    cout << endl;

}


void Employee::pInfo()
{
    cout <<"\n "<< EmpID << "\t\t|\t\t" << EmpName << "\t\t|\t\t" << EmpDesg << "\t\t|\t\t\t" << EmpSal<<"\n";
}

void Employee::apnd()
{
    ofstream outfile;
    Employee stud;
    outfile.open("main.dat", ios::app | ios::binary);
    stud.gInfo();
    outfile.write((char *)&stud, sizeof(stud));
    outfile.close();
}

void Employee::display()
{
    ifstream infile;
    Employee stud;
    char ch;
    infile.open("main.dat", ios::out | ios::binary);
    while (infile.read((char *)&stud, sizeof(stud)))
    {
        stud.pInfo();
    }
    infile.close();
    cout << endl;
}

void Employee::search()
{
    ifstream infile;
    Employee stud;
    index ind;
    int pos;
    char ch;
    int srroll, flag = 0;
    cout << "Enter Employee ID To Be Searched: ";
    cin >> srroll;
    pos=getindex(srroll);
    infile.open("main.dat", ios::out | ios::binary);
    infile.seekg(pos,ios::beg);
    while (infile.read((char *)&stud, sizeof(stud)))
    {
            stud.pInfo();
            flag = 1;
            break;
    }
    if (flag == 0)
    {
        cout << "Error Occured !!" << endl;
    }
    infile.close();
}

void Employee::del()
{
    fstream mainfile;
    fstream tempfile("temp.dat");
    Employee stud;
    string str;
    int srroll;
    cout << "Enter Employee ID To Be Deleted: ";
    cin >> srroll;
    int indstat=delindex(srroll);
    if (indstat!=0){
    cout << "Indexing Error Occured";
    exit;    
    }
    mainfile.open("main.dat", ios::in | ios::binary);
    tempfile.open("temp.dat", ios::out | ios::binary);

    while (!mainfile.eof())
    {

        mainfile.read((char *)&stud, sizeof(stud));

        if (mainfile)
        {

            if (stud.EmpID == srroll)
            {
                cout << "The deleted record is \n";
                stud.pInfo();
            }
            else
            {
                tempfile.write((char *)&stud, sizeof(stud));
            }
        }
    }

    mainfile.close();
    tempfile.close();
    
    remove("main.dat");

    rename("temp.dat", "main.dat");
}


void Employee::mod(){
     fstream mainfile;
    fstream tempfile("temp.dat");
    Employee stud;
    string str;
    int srroll;
    cout << "Enter Employee To Be Modified: ";
    cin >> srroll;
    mainfile.open("main.dat", ios::in | ios::binary);
    tempfile.open("temp.dat", ios::out | ios::binary);

    while (!mainfile.eof())
    {

        mainfile.read((char *)&stud, sizeof(stud));

        if (mainfile)
        {

            if (stud.EmpID == srroll)
            {
                cout<<"Updated Employee ID-> ";
                cin>>stud.EmpID;
                cout<<"Updated Salary-> ";
                cin>>stud.EmpSal;
                cout<<"Updated Name-> ";
                cin>>stud.EmpName;
                cout<<"Updated Designation-> ";
                cin>>stud.EmpDesg;
                tempfile.write((char *)&stud, sizeof(stud));
                modindex(srroll,stud.EmpID);
            }
            else
            {
                tempfile.write((char *)&stud, sizeof(stud));
            }
        }
    }

    mainfile.close();
    tempfile.close();
    
    remove("main.dat");

    rename("temp.dat", "main.dat");

}


int main()
{
    char choice;
    do
    {
        int ch;
        Employee stud;
        cout << "\n---Employee Management (Indexed Sequntial File Org.) ---\n1.Append Data\n2.Display \n3.Search Data\n4.Delete Data\n5.Modify Data\n\n Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            stud.apnd();
            break;
        case 2:
        cout<<"<------Index File Contents------>\nEmployee ID\n";
            stud.displayindex();
        cout<<"<------Main File Contents------>\n| Employee ID\t|\t\tEmployee Name\t|\t\tEmployee Desingation\t|\t\tEmployee Salary |";
        cout<<"\n``````````````````";
            stud.display();
            break;
        case 3:
            stud.search();
            break;
        case 4:
            stud.del();
            break;
        case 5:
            stud.mod();
            break;
        default:
            break;
        }

        cout << "Do you want to continue!? ";
        cin >> choice;
    } while (choice = 'y' || choice == 'Y');

    return 0;
}