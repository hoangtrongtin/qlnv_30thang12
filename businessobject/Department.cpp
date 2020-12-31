#include "Department.h"
#include <string>
#include <iostream>
#include "../libs/Utility.h"

Department::Department(){
    MemberName.resize(0);
    MemberValue.resize(0);
    SetNameVector();
}
Department::Department(string dName, int dno, long mgrSSN, string mgrStartDate)
{
    this->DName = dName;
    this->DNO = dno;
    this->MGRSSN = mgrSSN;
    this->MGRStartDate = mgrStartDate;
}
string Department::ToString()
{
    string s = "";
    s += "{";
    s += DName + ", " + to_string(DNO) + ", " + to_string(MGRSSN) + ", " + MGRStartDate + "}";
    return s;
}
void Department::SetValueVector()
{
    MemberValue = {DName, to_string(DNO), to_string(MGRSSN), MGRStartDate};
}
void Department::SetNameVector()
{
    MemberName = {"DName", "DNO", "MGRSSN", "MGRStartDate"};
}
string Department::ToStringFile(){
    SetValueVector();
    string sFile = Utility::ToString(MemberValue);
    return sFile;
}
