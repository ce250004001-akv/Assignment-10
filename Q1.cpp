/**
 * Write a C++ program to define a structure Item with members id (integer), name (string), and cost (float).
Declare an array of 8 Item structures, read their details from user input, and then:
Sort the array in descending order of cost.
Display the sorted list of items.
Additionally, display the average cost of all items.
 */
 #include <iostream>
 using namespace std;
 struct Student{
    int id;
    string name;
    float cost;

 };
 int main(){
    Student s[8];//Array of 8 student structure

    //Input details for 8 student
    for(int i=0;i<8;i++){
        cout<<"Enter the detail for student " << i+1 <<":"<<endl;
        cout<<"ID: ";
        cin>>s[i].id;
        cout<<"Name: ";
        cin.ignore();
        getline(cin, s[i].name);
       // cin>>s[i].name;
        cout<<"Cost: ";
        cin>>s[i].cost;
    }

    float sum=0;
    //sorting in descending order of cost via bubble sort
    for(int i=0;i<8;i++){
        sum+=s[i].cost;
        for(int j=0;j<8-i-1;j++){
            if(s[j].cost>s[j+1].cost){
                //int e=s[j+1];
                 //string s[j+1];
                Student d=s[j];
                s[j]=s[j+1];
                s[j+1]=d;
                
            }
        }
    }

    cout<<"\n\n\n\nSorted list of items are : "<<endl;
    for(int i=0;i<8;i++){
        cout<<"student " << i+1 <<":"<<endl;
        cout<<"ID: "<<s[i].id<<endl;
       
        cout<<"Name: "<<s[i].name<<endl;
      
        cout<<"Cost: "<<s[i].cost<<endl;
  
    }
    cout<<"average of the cost of items is  :  "<<sum<<endl;
    return 0;
}