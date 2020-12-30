#include <iostream>
#include <string>
#include <fstream>
#include "businessobject/Employee.h"
#include "businessobject/TableUnit.h"
#include "dataaccess/EmployeeData.h"
#include "dataaccess/TableData.h"
#include "ui/MyUI.h"

using namespace std;

/** @brief Function generate Employee Data
*
* Function generate Employee Data _________
* @return a Vector contain employee data
*/
EmployeeData GenerateEmployeeData()
{
    //Employee e(1, "Chau", "Bao", "Ngo", 111222333, "1975-04-30", "Chicago", 'M', 10000, -1, 5);
    Employee* e1 = new Employee(1, "John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee* e2 = new Employee(2, "franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee* e3 = new Employee(3, "Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring, TX", 'F', 25000, 987654321, 4);
    Employee* e4 = new Employee(4, "Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry, Bellaire, TX", 'F', 43000, 888665555, 4);
    Employee* e5 = new Employee(5, "Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", 'M', 38000, 333445555, 5);
    Employee* e6 = new Employee(6, "Joyce", "A", "English", 453453453, "1972-07-31", "5631 Ric, Houston, TX", 'F', 25000, 333445555, 5);
    Employee* e7 = new Employee(7, "Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", 'M', 25000, 987654321, 4);
    Employee* e8 = new Employee(8, "James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    EmployeeData employeedata;
    employeedata.PushBack(e1);
    employeedata.PushBack(e2);
    employeedata.PushBack(e3);
    employeedata.PushBack(e4);
    employeedata.PushBack(e5);
    employeedata.PushBack(e6);
    employeedata.PushBack(e7);
    employeedata.PushBack(e8);
    return employeedata;
    
}
int main()
{
    cout<<"Hello World"<<endl;
    MyUI myUI;
    TableData* employeeData = new EmployeeData();
    TableUnit* employee = new Employee();

    myUI.ImportFromStringFile(employeeData, "data/EmployeesString.data");
    cout << employeeData->ToString();
    //myUI.ExportToStringFile(*employeeData, "data/EmployeesString.data");
    myUI.AddToTable(employeeData);
    cout << employeeData->ToString();

    return 0;
}