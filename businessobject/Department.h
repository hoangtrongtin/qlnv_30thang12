#ifndef Project_businessobject_Department_H_
#define Project_businessobject_Department_H_

#include <string>
#include "TableUnit.h"

using namespace std;

class Department: public TableUnit{
private:
    string DName;
    int DNO;
    long MGRSSN;
    string MGRStartDate;
public:
    Department();
    Department(string dName, int dno, long mgrSSN, string mgrStartDate);
    string ToString();
    void SetValueVector();
    void SetNameVector();
    string ToStringFile();
    void FromStringFile(string); 
};

#endif