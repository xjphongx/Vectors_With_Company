#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include "person.cpp"

using namespace std;

//reading and writing files through pay file
void readData (vector<Person> & employee);
void getCompanies(vector<Person> & employee, vector<string> & companyNames);

int main()
{
    //Format: vector <DataType> nameOfVector;
    vector<Person> employees; //vector of Person objects
        //This completes part 5
    vector<string> companyNames;
        //completes part 6

    readData(employees);

    getCompanies(employees,companyNames);
    

    system("read -p 'Press Enter to Continue...' var");
    return 0;
}
/*
    readData reads and passes the data by reference
*/
void readData(vector <Person> & employee)
{
    ifstream inputFile;
    inputFile.open("input.txt");
/*
    //*****************************
    //I need to find the size first
    int fileCount = 0;
    string line;
    while (getline(inputFile,line))
    {
        fileCount++;
    }
    //this will resize the vector based on file lines in the text file
    employee.resize(fileCount); 
*/
    //create a temp object to store into the vector

    //Maria    Brown      10 Intel      42.75 39.0
    string fname, lname, companyname;
    int id;
    float hour, payrate;

    while(!inputFile.eof())
    {
        //create temp object here
        Person temp;
        inputFile >> fname;
        inputFile >> lname;
        inputFile >> id;
        inputFile >> companyname;
        inputFile >> hour;
        inputFile >> payrate;
        //after getting the inputs, set them to temp and pushback
        temp.setFirstName(fname);
        temp.setLastName(lname);
        temp.setEmployeeID(id);
        temp.setCompanyName(companyname);
        temp.setHoursWorked(hour);
        temp.setPayRate(payrate);
        employee.push_back(temp);//this pushes back by referencing to the vector
    }
    //testing this
    for(int a = 0; a <employee.size()-1; a++)//-1 bc last entry will duplicate
    {
        string test = employee.at(a).getFirstName();
        int test2 = employee.at(a).getEmployeeID();
        cout << test <<" "<<test2<< endl;
    }//this reads everthing incorrectly 



    inputFile.close();
}

/*
    getCompanies will retrieve the compan names from employees
    and add them to the companyNames Vector by 
    passing thru reference for both vecotrs
*/
void getCompanies(vector<Person> & employee, vector<string> & companyNames)
{
    //put all the company names into the companyName vector first
    for (int b = 0; b < employee.size();b++)
    {
        string tempName;
        tempName = employee.at(b).getCompanyName();
        companyNames.push_back(tempName);

    }//companyNames should only contain company names in order

    //next, call companyNames and filter out duplicates
    
    for(int c = 0; c < companyNames.size();c++)
    {
         cout << "Loop "<< c <<endl;
        for(int d = c+1; d <companyNames.size();d++)
        {
           
            
            if(companyNames.at(c)==companyNames.at(d))
            {
                //companyNames.erase(companyNames.at(d));
                companyNames.erase(companyNames.begin()+d);
                
                
            }
            cout << companyNames.at(d)<< " ";//test
            cout <<endl;
        }

        cout << endl;


    }
//another test

    cout << "Filtered Results"<< endl;
    for (int z = 0 ; z < companyNames.size(); z++)
    {
        cout<< companyNames.at(z) <<endl;
    }

}


