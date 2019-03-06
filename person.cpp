/*
    Class Definition
*/
#include <iostream>
#include <string>

#include "person.h"

using namespace std;

Person::Person(){
    //will run this if an object without info is created
    firstName = "Jimmy";
    lastName = "Phong";
    employeeID = 123456;
    companyName = "Boeing";
    hoursWorked = 19;
    payRate = 17.50;
}
//first name
void Person::setFirstName(string fName)
{
    firstName = fName;
}
string Person::getFirstName()
{
    return firstName;
}
//last name
void Person::setLastName(string lName)
{
    lastName = lName;
}
string Person::getLastName()
{
    return lastName;
}
//employee id
void Person::setEmployeeID(int id)
{
    employeeID = id;
}
int Person::getEmployeeID()
{
    return employeeID;
}
//company name
void Person::setCompanyName(string coName)
{
    companyName = coName;
}
string Person::getCompanyName()
{
    return companyName;
}
//hours
void Person::setHoursWorked(float hours)
{
    hoursWorked = hours;
}
float Person::getHoursWorked()
{
    return hoursWorked;
}
//Pay rate
void Person::setPayRate(float rate)
{
    payRate = rate;
}
float Person::getPayRate()
{
    return payRate;
}
//other functions
float Person::totalPay()
{
    return payRate*hoursWorked;
}
string Person::fullName()
{
    string temp = firstName + " " + lastName;
    return temp;
}
