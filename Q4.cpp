#include <iostream>
#include <fstream>
using namespace std;
/*Define a structure SalesRecord with members month (string), amount (float).
Allow the user to input the sales data for all 12 months, and then:
Write all data to a text file named "sales_data.txt".
Read the data back from the file.
Display the month(s) where sales were above the yearly average.*/
struct SalesRecord{
    string month;
    float amount ;
};
int main(){
    SalesRecord sales[12];
    double total=0.0;

    //Input the sale for 12 month
    cout<<"Input the sale for 12 month";
    for(int i=0;i<12;i++){
        cout<<"month: "<<i+1<<" name: ";
        cin>>sales[i].month;
        cout<<"Amount: ";
        cin>>sales[i].amount;
        total+=sales[i].amount;
    }

    //Write data to file
    ofstream outFile("sales_data.txt");//to write data to a file           sales_data.txt is the file name where sales data will be stored 
    if(!outFile){    //checks whether the file was successfully created or opened 
        cout<<"Error creating file!"<<endl; //if something goes wrong( ex. no permission , bad path ), the program prints "Error creating file !" and exits
        return 1;
    }
        /*
        Your comment asks what it means.
        ➤ return 1; means the program ended abnormally (with an error).
        return 0; → success
        return 1; → error or failure


for code line 48-51
        this loop writes each record (month +amount) from your array sales[] to the file        
        each line in the file will look like this :
        Jan 12000
        Feb 9500
        March 10500
        ....
        */
    for(int i=0;i<12;i++){  
        outFile<< sales[i].month<<" "<<sales[i].amount<<endl;
    }
    outFile.close();//properly closes the file to save changes and free system resources

    //Read data back from the file
    ifstream inFile("sales_data.txt");   //ifstream = input stream ---> used to read data from a file......it tries to open the same "sales_data.txt" file you just wrote and if file doesn't exist or can't be opened thent he program exitss
    if(!inFile){
        cout<<"ERROR OPENING FILE!"<<endl;
        return 1;
    }

    SalesRecord readSales[12];
    int count=0; 
    /*this reads the file word by word splitting by whitespaces: 
    first token ---> month
    second token ---> amount
    it continues until the ends 
    the loop fills a new array readSales[] with the same data from the file
    */
    while(inFile>>readSales[count].month>>readSales[count].amount){
        count++;
    }
    inFile.close();

    //Calculating yearly average
    double yearlyAverage = total/12;

    //displaying month above average
    cout<<"\n Yearly Average Sales: "<<yearlyAverage<<endl;
    cout<<"Months with sales above yearly average:\n";
    for(int i=0;i<12;i++){
        if(readSales[i].amount>yearlyAverage){
            cout<<readSales[i].month<<"-->"<<readSales[i].amount<<endl;
        }
    }
    return 0;
}