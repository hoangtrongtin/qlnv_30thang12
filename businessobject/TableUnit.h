#ifndef Project_businessobject_TableUnit_H_//sub class of all table
#define Project_businessobject_TableUnit_H_

#include "../libs/json.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TableUnit{
private:
public:
    vector<string> MemberName;
    vector<string> MemberValue;
    TableUnit();
    int Id;
    int GetID();
    virtual string ToString() = 0;
    virtual string ToStringFile() = 0;
    virtual void FromStringFile(string) = 0;
};

#endif