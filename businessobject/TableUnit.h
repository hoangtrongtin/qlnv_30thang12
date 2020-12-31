#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/json.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TableUnit{
protected:
    vector<string> MemberName;
    vector<string> MemberValue;
public:
    //vector<string> MemberName;
    //vector<string> MemberValue;
    TableUnit();
    //int Id;
    //int GetID();
    virtual string ToString() = 0;
    virtual void SetValueVector() = 0;
    vector<string> GetValueVector();
    virtual void SetNameVector() = 0;
    vector<string> GetNameVector();
    virtual string ToStringFile() = 0;
    virtual void FromStringFile(string) = 0;
    //int FindMember(string);
};

#endif