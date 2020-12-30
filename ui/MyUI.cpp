#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "MyUI.h"
#include "../businessobject/TableUnit.h"
#include "../businessobject/Employee.h"
#include "../libs/Utility.h"

using namespace std;

MyUI::MyUI(){}

int MyUI::ExportToStringFile(TableData tD, string filename){
    ofstream outFile(filename, ios::out);
    if(!outFile) return 0;
    for (auto tU: tD.GetTableData()){
        outFile << tU->ToStringFile() <<endl;
    }
    outFile.close();
    return 1;
}
void MyUI::ImportFromStringFile(TableData* tD, string filename){
    tD->SetMaxID(0);
    tD->ReSize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize))
    {
        string s = buff;
        TableUnit *tU = tD->NewPoint();
        tU->FromStringFile(s);
        tD->PushBack(tU);
    }
    inFile.close();
}

void MyUI::AddToTable(TableData* tD)
{
    TableUnit* tU = tD->NewPoint();
    string stemp = "";
    vector<string> vts;
    cin.ignore();
    for(auto s: tU->MemberName)
    {
        string member = "";
        cout << s << ": ";
        getline(cin, member);
        //vts.push_back(Utility::SDecode(member));
        stemp = stemp + Utility::SEncode(member) + " ";
        //cout <<stemp<<endl;
    }
    stemp[stemp.length()] = 0;
    cout<<stemp<<endl;
    tU->FromStringFile(stemp);
    tD->PushBack(tU);
}