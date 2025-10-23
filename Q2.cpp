/*
Define two structures:
Marks with members math, science, and english (floats).
Student with members rollNo (int), name(string), and marks (of type Marks).
Declare an array of 5 Student structures.
Accept input for all students and their marks, compute their average marks, and then display:
The student with the highest average marks, and
The student with the lowest average marks.*/
#include <iostream>
#include <cmath>
using namespace std;
struct Marks{
    float math, science, english;
};
struct Student{
    int rollNo ;
    string name;
    Marks marks;
};
int main(){
    Student s[5];
    for(int i=0;i<5;i++){
        
        cout<<"Student : " <<i+1<<" : \nroll No: ";
        cin>>s[i].rollNo;
        cout<<"name: ";
        cin>>s[i].name;
        cout<<"marks : ";
        cout<<"Math: ";
        cin>>s[i].marks.math;
        cout<<"Science: ";
        cin>>s[i].marks.science;
        cout<<"English: ";
        cin>>s[i].marks.english;
    }
    int arr[5]={0};
    int smax=0;
    int smaxi=-1;
    int smin=100*5;;
    int smini=-1;
    for(int i=0;i<5;i++){
        int sum=s[i].marks.math+s[i].marks.science+s[i].marks.english;
        sum/=3;
        cout<<sum/3<<" is average of student "<<i+1<<" with name : "<<s[i].name<<endl;
        if(smax<sum){
            smax=sum;
            smaxi=i;
        }
        if(smin>sum){
            smin=sum;
            smini=i;
        }
    }
    cout<<"Student with the highest average score is : "<<s[smaxi].name<<endl;
    cout<<"Student with the lowest average score is : "<<s[smini].name<<endl;
    return 0;
}