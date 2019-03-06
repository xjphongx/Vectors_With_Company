#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "person.cpp"
#include "person.h"

using namespace std;

//reading and writing files through pay file
void readData (vector<Person> & employee);
void getCompanies(vector<Person> & employee, vector<string> & companyNames);
void printHighestPaid (vector<Person> & employee);
void separateAndSave ( vector<Person> & employee, vector<string> & companyNames);
/****************************************************************
 * 
 *      Main Function
 *  
 * 
 * *************************************************************/
int main()
{
    //Format: vector <DataType> nameOfVector;
    vector<Person> employees; //vector of Person objects
        //This completes part 5
    vector<string> companyNames;
        //completes part 6

    //main function calls
    readData(employees); //completes part 7
    getCompanies(employees,companyNames); //completes part 8
    printHighestPaid(employees); //completes part 9
    separateAndSave(employees, companyNames);//completes part 10

    system("read -p 'Press Enter to Continue...' var");
    return 0;
}

/*****************************************************************
*  readData reads and passes the data by reference
*****************************************************************/
void readData(vector <Person> & employee)
{
    ifstream inputFile;
    inputFile.open("input.txt");

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
    for(unsigned a = 0; a <employee.size()-1; a++)//-1 bc last entry will duplicate
    {
        string test = employee.at(a).getFirstName();
        int test2 = employee.at(a).getEmployeeID();
        cout << test <<" "<<test2<< endl;
    }



    inputFile.close();
}

/**************************************************************
    getCompanies will retrieve the compan names from employees
    and add them to the companyNames Vector by 
    passing thru reference for both vecotrs
**************************************************************/
void getCompanies(vector<Person> & employee, vector<string> & companyNames)
{
    //put all the company names into the companyName vector first
    for (unsigned b = 0; b < employee.size();b++)
    {//use unsigned bc vectors
        //unsigned c = b-1;
        string tempName;
        tempName = employee.at(b).getCompanyName();
        companyNames.push_back(tempName);
        //after this companyNames should have ALL the company names
    }
    //companyNames should only contain unique names without duplication
    sort(companyNames.begin(), companyNames.end());
    //testing what sort will do
    cout << "sorted function results"<<endl;
    for (unsigned z = 0 ; z < companyNames.size(); z++)
    {
        cout<< companyNames.at(z) <<endl;
    }

    companyNames.erase(unique(companyNames.begin(), companyNames.end()),companyNames.end());
    //had to implement a sorting algorithm
//another test
    cout << "Filtered Results"<< endl;
    for (unsigned z = 0 ; z < companyNames.size(); z++)
    {
        cout<< companyNames.at(z) <<endl;
    }

}
/****************************************************************
 *  printHighestPaid will print the richest person
 * *************************************************************/
void printHighestPaid (vector<Person> & employee)
{
    Person richestPerson;//will hold the richest person object
    float highestPay = employee.at(0).getPayRate()*employee.at(0).getHoursWorked();
    float currentPay;

    //goes throught each vector to compare pay
    for(unsigned e = 0; e <employee.size();e++)
    {
        currentPay = employee.at(e).getPayRate()*employee.at(e).getHoursWorked();
        if ( highestPay <= currentPay)
        {
            highestPay = currentPay;
            richestPerson = employee.at(e);
        }


    }
    //print out rich person
    cout << "\nCalling the printHighestPaid function"<<endl;
    cout << "Highest paid: "<< richestPerson.getFirstName() << " "<< richestPerson.getLastName() <<endl;
    cout << "Employee ID: "<< richestPerson.getEmployeeID() <<endl;
    cout << "Employer: "<< richestPerson.getCompanyName() <<endl;
    cout << "Total Pay: $"<< fixed<< setprecision(2)<< highestPay << endl;
}
/*****************************************************************
 * separateAndSave will filter all the company employees into their
 * respected company text files
 * **************************************************************/
void separateAndSave ( vector<Person> & employee, vector<string> & companyNames)
{
    /*
    ERROR HERREEEEEEEEEEEEEEEE
        terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 17) >= this->size() (which is 17)
Aborted (core dumped)
    */
   
    ofstream intelFile, boeingFile, douglasFile, 
    raytheonFile, healthtechFile;
    
    //open all the txt files
    intelFile.open("Intel.txt");
    boeingFile.open("Boeing.txt");
    douglasFile.open("Douglas.txt");
    raytheonFile.open("Raytheon.txt");
    healthtechFile.open("HealthTech.txt");

    //unsigned num = distance(employee.begin(), employee.end());
    int intTotal = 0;
    int boeTotal = 0;
    int dougTotal = 0;
    int rayTotal = 0;
    int healthTotal = 0;

    for(unsigned index = 0; 0 < employee.size()-1;index++)
    {

        //condition statements to separate into company groups
        if(employee.at(index).getCompanyName() == "Intel")
        {
            intelFile << employee.at(index).fullName();
            intelFile << employee.at(index).getEmployeeID();
            intelFile << employee.at(index).getCompanyName();
            intelFile << employee.at(index).totalPay()<<"\n";
            intTotal += employee.at(index).totalPay();

        }else if(employee.at(index).getCompanyName() == "Boeing")
        {
            boeingFile << employee.at(index).fullName();
            boeingFile << employee.at(index).getEmployeeID();
            boeingFile << employee.at(index).getCompanyName();
            boeingFile << employee.at(index).totalPay()<<"\n";
            boeTotal += employee.at(index).totalPay();
        }else if (employee.at(index).getCompanyName() == "Douglas")
        {
            douglasFile << employee.at(index).fullName();
            douglasFile << employee.at(index).getEmployeeID();
            douglasFile << employee.at(index).getCompanyName();
            douglasFile << employee.at(index).totalPay()<<"\n";
            dougTotal += employee.at(index).totalPay();
        }else if (employee.at(index).getCompanyName() == "Raytheon")
        {
            raytheonFile << employee.at(index).fullName();
            raytheonFile << employee.at(index).getEmployeeID();
            raytheonFile << employee.at(index).getCompanyName();
            raytheonFile << employee.at(index).totalPay()<<"\n";
            rayTotal += employee.at(index).totalPay();
        }else if (employee.at(index).getCompanyName() == "HealthTech")
        {
            healthtechFile << employee.at(index).fullName();
            healthtechFile << employee.at(index).getEmployeeID();
            healthtechFile << employee.at(index).getCompanyName();
            healthtechFile << employee.at(index).totalPay()<<"\n";
            healthTotal += employee.at(index).totalPay();
        }

    }
    //cout total employee pay
    intelFile <<"$" << fixed<< setprecision(2)<<intTotal;
    boeingFile <<"$" << fixed<< setprecision(2)<<boeTotal;
    douglasFile <<"$" << fixed<< setprecision(2)<<dougTotal;
    raytheonFile <<"$" << fixed<< setprecision(2)<<rayTotal;
    healthtechFile <<"$" << fixed<< setprecision(2)<<healthTotal;

    intelFile.close();
    boeingFile.close();
    douglasFile.close();
    raytheonFile.close();
    healthtechFile.close();
    


}

