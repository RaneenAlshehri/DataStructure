#Raneen Alhehri
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using namespace std;
 

class Node {
public:
  
    int EmployeeId;
    string EmployeeName;
    string FirstDayOfWork;
    int PhoneNumber;
    double Salary;
    int WorkHours;
    int Address;
    Node* next;
};

Node* head = new Node();
//---------------------------Function check------------------------------------------
bool check(int id_emp)
{
   if (head == NULL)
        return false;
 
    Node* temp = new Node;
    temp = head;
 
    // Traverse the Linked List
    while (temp != NULL) {
        if (temp->EmployeeId == id_emp)
            return true;
        temp = temp->next;
    }
 
    return false;
}
 
//-------------------------- Function to insert the record--------------------------------------------
void InsertEmpRecord(int EmployeeId,string EmployeeName,string FirstDayOfWork,int PhoneNumber,double Salary,int WorkHours,int Address)
{

// if Record Already Exist

    if (check(EmployeeId)) {
        cout << "Record Already Exists \n";
        return;
    }
 
    // Create new Node to Insert Record
    Node* temp = new Node();
    temp->EmployeeId = EmployeeId;
    temp->EmployeeName = EmployeeName;
    temp->FirstDayOfWork = FirstDayOfWork;
    temp->PhoneNumber = PhoneNumber;
    temp->Salary = Salary;
    temp->WorkHours = WorkHours;
    temp->Address = Address;
    temp->next = NULL;
 
    // Insert at Begin
    if (head == NULL || (head->EmployeeId >= temp->EmployeeId)) {
        temp->next = head;
        head = temp;
    }
 
    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL && c->next->EmployeeId < temp->EmployeeId) {
            c = c->next;
        }
        temp->next = c->next;
        c->next = temp;
    }
 
    cout << "Record Inserted Successfully \n";
}

//---------------------------Delete Employee Record  ------------------------------------------
int DeleteEmployee(int EmployeeId)
{

    Node* temp = head;
    Node* v = NULL;
 

    if (temp != NULL && temp->EmployeeId == EmployeeId) {
        head = temp->next;
        delete temp;
 
        cout << "The record has been successfully deleted\n";
        return 0;
    }

    while (temp != NULL && temp->EmployeeId != EmployeeId) {
        v = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        v->next = temp->next;
        delete temp;
        cout << "The record has been successfully deleted \n";
 
        return 0;
    }
}
 

//------------------------Search Employee Record  ---------------------------------------------
 void SearchEmployee(int EmployeeId)
{
     
    // if head is NULL == NULL
    if (!head) {
        cout << "No Record \n ";
        return;
    }
 
    else {
        Node* temp = head;
        while (temp) {
            if (temp->EmployeeId == EmployeeId) 
            {
                cout << "EmployeeId   \t"
                     << temp->EmployeeId << endl;
                cout << "EmployeeName \t"
                     << temp->EmployeeName << endl;
                cout << "FirstDayOfWork\t"
                     << temp->FirstDayOfWork << endl;
                cout << "PhoneNumber  \t"
                     << temp->PhoneNumber << endl;
                cout << "Salary      \t"
                     << temp->Salary << endl; 
                cout << "WorkHours   \t"
                     << temp->WorkHours << endl; 
                cout << "Address     \t"
                     << temp->Address << endl;      
                return;
             }
            temp = temp->next;
        }
 
        if (temp == NULL)
            cout << "Record not found \n";
    }
}



// -------------------------ShowEmployee --------------------------------------------
 void ShowEmployee()
{
    Node* temp = head;
    if (temp == NULL) {
        cout << "Record not Available \n";
    }
    else {
        while (temp != NULL) {
            cout << " EmployeeId     "<< temp->EmployeeId <<"\n";
            cout << " EmployeeName   "<<  temp->EmployeeName <<"\n";
            cout << " FirstDayOfWork " << temp->FirstDayOfWork <<"\n";
            cout << " PhoneNumber    "<< temp->PhoneNumber <<"\n";
            cout << " Salary         "<<  temp->Salary <<"\n";
            cout << " WorkHours      " <<  temp->WorkHours <<"\n";
            cout << " Address        "<<  temp->Address <<"\n" ;
             temp= temp->next;
            cout << "____________________________________________________"<<"\n" ;  
        }
    }
}
//---------------------------------------------UPDATE------------------------------------------
 void updateSalary()
 {
     Node* p = head;
     while(p){
         
         if( p->WorkHours > 32){
            p->Salary +=0.2;
            cout<<"Successfully update Salary Record : " << p->EmployeeId << " \n ";}
         else{
            cout<<"\nFailure update Salary Record : " << p->EmployeeId << " \n ";
             }  
      p = p->next;
         
     }
 }

      

int main()
{
    head = NULL;
    
    int EmployeeId;
    string EmployeeName;
    string FirstDayOfWork;
    int PhoneNumber;
    double Salary;
    int WorkHours;
    int Address;
 
    //----Menu-----
    while (true) {
        cout << "\n\n\t\tWelcome to Employee Record Management System\n\t"
                "1- create a new Record\n\t"
                "2- delete Employee Record\n\t"
                "3- Search Record \n\t"
                "4- Show Record\n\t"
                "5- Update Record\n\t"
                "6-  Exit\n";
        
        cout << "\nEnter your Choice\n";
        
        int Choice;
        cin >> Choice;
        
        if (Choice == 1) {
            
            cout << "Enter EmployeeId\n";
            cin >> EmployeeId;
            cout << "Enter EmployeeName \n";
            cin >> EmployeeName;
            cout << "Enter FirstDayOfWork \n";
            cin >> FirstDayOfWork;
            cout << "Enter PhoneNumber\n";
            cin >> PhoneNumber;
            cout << "Enter Salary\n";
            cin >> Salary;
            cout << "Enter WorkHours\n";
            cin >> WorkHours;
            cout << "Enter Address\n";
            cin >> Address;
            InsertEmpRecord(EmployeeId, EmployeeName, FirstDayOfWork, PhoneNumber,Salary,WorkHours,Address);
        }
        else if (Choice == 2) {
            cout << "Enter EmployeeId Number of Employee whose record is to be deleted :\n";
            cin >> EmployeeId;
            DeleteEmployee(EmployeeId);
        }
        else if (Choice == 3) {
            cout << "Enter EmployeeId Number of Employee whose record you want to Search :\n";
            cin >> EmployeeId;
            SearchEmployee(EmployeeId);
        }
        else if (Choice == 4) {
            ShowEmployee();
        }
        else if (Choice == 5) {
           updateSalary();
        }
        else if (Choice == 6) {
            exit(0);
        }
        else {
            cout << "The option does not exist ,Try Again\n";
        }
    }
    return 0;
}
