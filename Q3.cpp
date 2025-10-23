#include <iostream>
using namespace std;
struct Employee{
    int id;
    string name;
    float salary;
};
int main(){
    Employee e[10];
    cout<<"enter your detail with id name and salary respectively seperated by spaces "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>e[i].id>>e[i].name>>e[i].salary;
    }
    cout<<"\nmenu driven\n";
    cout<<"ID \t\t NAME \t Salary"<<endl;
    for ( int i=0;i<10;i++){
        cout<<e[i].id<<e[i].name<<e[i].salary;
    }

    cout<<"SEARCHING FOR THE EMPLOYEE VIA ID\n tell the id to searched ";
    int find;
    cin>>find;
    for(int i=0;i<10;i++){
        if(find==e[i].id){
            cout<<"Employee details : "<<e[i].name<<endl;
        }
    }
    //salary hike 
    cout<<"Doing salary hike for employee with income less 30000"<<endl;
    for(int i=0;i<10;i++){
        if(e[i].salary<30000)
        e[i].salary+=e[i].salary*0.1;
    }
    cout<<"Updated list : \n id \t name\t new salary"<<endl;
    for(int i=0;i<10;i++){
        cout<<e[i].id<<"\t"<<e[i].name<<"\t"<<e[i].salary;
    }

}
/**
Define a structure Employee with members id(int), name (string), and salary (float).
Declare an array of 10 employees and read their details from user input.
Write a menu-driven program that allows the user to:
Display all employee details.
Search for an employee by id.
Increase the salary of all employees earning less than ₹30,000 by 10%.
Exit.
*/
