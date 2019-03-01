//begin person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
    private:
        string firstName;
        string lastName;
        int employeeID;
        string companyName;
        float hoursWorked;
        float payRate;
    //^^^these are all variables that each object of person will have
    public:
        //constuctor for every class made
        Person();
        //setters and getters for the private variables
        void setFirstName(string fName);
        string getFirstName();
        void setLastName(string lName);
        string getLastName();
        void setEmployeeID(int id);
        int getEmployeeID();
        void setCompanyName(string coName);
        string getCompanyName();
        void setHoursWorked(float hours);
        float getHoursWorked();
        void setPayRate(float rate);
        float getPayRate();

        //Actual functions for calculations and prints
        float totalPay();
        string fullName();
        

};
#endif
//ends the header
