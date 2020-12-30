#ifndef Project_dataaccess_Employee_Data_H_
#define Project_dataaccess_Employee_Data_H_
#include <vector>
#include <string>
#include "../businessobject/Employee.h"
#include "TableData.h"

class EmployeeData: public TableData{
private:
    //vector<Employee> _data;
    //int _maxId;
public:
    EmployeeData();
    EmployeeData(string);
    TableUnit* NewPoint();

};
#endif
