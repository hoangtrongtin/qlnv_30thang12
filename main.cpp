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
    Employee* e1 = new Employee("John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee* e2 = new Employee("franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee* e3 = new Employee("Alicia", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring, TX", 'F', 25000, 987654321, 4);
    Employee* e4 = new Employee("Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry, Bellaire, TX", 'F', 43000, 888665555, 4);
    Employee* e5 = new Employee("Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Humble, TX", 'M', 38000, 333445555, 5);
    Employee* e6 = new Employee("Joyce", "A", "English", 453453453, "1972-07-31", "5631 Ric, Houston, TX", 'F', 25000, 333445555, 5);
    Employee* e7 = new Employee("Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas, Houston, TX", 'M', 25000, 987654321, 4);
    Employee* e8 = new Employee("James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
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
    cout << "0. exit"<<endl;
    cout << "1. add table" <<endl;
    cout << "2. edit table" <<endl;
    cout << "3. delete unit of table" <<endl;
    int choose; cin >> choose; cin.ignore();
    switch (choose)
    {
        case 0: break;
        case 1: {
            myUI.AddToTable(employeeData);
            break;
        }
        case 2:{
            myUI.EditTable(employeeData);
            break;
        }
        case 3:{
            myUI.DeleteUnitTable(employeeData);
            break;
        }
    }
    

    return 0;
}