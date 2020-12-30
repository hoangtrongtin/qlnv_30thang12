#include "EmployeeData.h"
#include <fstream>
#include <string>


EmployeeData::EmployeeData() : TableData(){}
EmployeeData::EmployeeData(string filename){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        string s = buff;
        Employee* e = new Employee();
        e->FromStringFile(s);
        _data.push_back(e);
    }
    inFile.close();
}
TableUnit* EmployeeData::NewPoint()
{
    TableUnit *tU = new Employee();
    return tU;
}
