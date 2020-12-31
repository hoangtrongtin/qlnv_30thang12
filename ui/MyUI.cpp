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
TableUnit* EditUnit(TableData* tD)
{
    TableUnit* tU = tD->NewPoint();
    string stemp = "";
    vector<string> vts;
    for(auto s: tU->GetNameVector())
    {
        string member = "";
        cout << s << ": ";
        getline(cin, member);
        stemp = stemp + Utility::SEncode(member) + " ";
    }
    stemp[stemp.length()] = 0;
    //cout<<stemp<<endl;
    tU->FromStringFile(stemp);
    return tU;
}
void MyUI::AddToTable(TableData* tD)
{
    tD->PushBack(EditUnit(tD));
    cout << "New Table: "<< endl;
    cout << tD->ToString();
}
void MyUI::EditTable(TableData* tD){
    cout << tD->ToString();
    cout << "Edit Employee has SSN: ";///// Chuyen vao ham main()
    string ssn; cin >> ssn; cin.ignore();
    int result = tD->FindUnit("SSN", ssn);
    if (result == -1) cout << "Opp! There no match data."<<endl;
    else{
        cout << "Old data: " << result+1 << ". " << tD->GetTableData()[result]->ToString() << endl;
        cout << "New data: " << endl;
        tD->SetTableData(EditUnit(tD), result);
        cout << "New Table: "<< endl;
        cout << tD->ToString();
    }

}
void MyUI::DeleteUnitTable(TableData* tD){
    cout << tD->ToString();
    cout << "Edit Employee has SSN: ";///// Chuyen vao ham main()
    string ssn; cin >> ssn; cin.ignore();
    int result = tD->FindUnit("SSN", ssn);
    if (result == -1) cout << "Opp!"<<endl;
    else{
        cout << "Old data: " << result << ". " << tD->GetTableData()[result]->ToString() << endl;
        tD->DeleteUnit(result);
        cout << "New Table: "<< endl;
        cout << tD->ToString();
    }
}