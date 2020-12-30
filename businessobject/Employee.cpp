#include "Employee.h"
#include <string>
#include <iostream>
#include "../libs/Utility.h"

Employee::Employee(){
    MemberName.resize(0);
    MemberValue.resize(0);
    MemberName = {"Id", "FName", "MInit", "LName", "SSN", "BDate",
                    "Address", "Sex", "Salary", "SuperSSN", "DNO"};
}
Employee::Employee(int id, string fName, string mInit, string lName,
                    long ssn, string bDate, string address, char sex,
                    int salary, long superSSN, int dno)
{
    this->Id = id;
    this->FName = fName;
    this->MInit = mInit;
    this->LName = lName;
    this->SSN = ssn;
    this->BDate = bDate;
    this->Address = address;
    this->Sex = sex;
    this->Salary = salary;
    this->SuperSSN = superSSN;
    this->DNO = dno;
}
string Employee::ToString(){
    string s;
    s += "{";
    s += to_string(Id) + ", ";
    s += FName + ", " + MInit + ", " + LName + ", ";
    s += to_string(SSN) + ", ";
    s += BDate + ", " + Address + ", ";
    s += std::string(1, Sex) + ", ";
    s += to_string(Salary) + ", ";
    s += to_string(SuperSSN) + ", ";
    s += to_string(DNO);
    s += "}";
    return s;

}
string Employee::ToStringFile()
{
    MemberValue = {to_string(Id), FName, MInit, LName, to_string(SSN),
                BDate, Address, to_string(Sex), to_string(Salary), 
                to_string(SuperSSN), to_string(DNO)};
    string sFile = Utility::ToString(MemberValue);
    return sFile;
}
void Employee::FromStringFile(string s){
    vector<string> vts = Utility::FromString(s);
    //Employee* e = new Employee();
    //for(auto i: vts) cout<<i<<endl;

    this->Id = stoi(vts[0]);
    this->FName = vts[1];
    this->MInit = vts[2];
    this->LName = vts[3];
    this->SSN = stol(vts[4]);
    this->BDate = vts[5];
    this->Address = vts[6];
    this->Sex = vts[7][0];
    this->Salary = stoi(vts[8]);
    this->SuperSSN = stol(vts[9]);
    this->DNO = stoi(vts[10]);
    //return e;
}