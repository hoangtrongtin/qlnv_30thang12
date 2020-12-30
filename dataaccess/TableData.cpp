#include "TableData.h"
#include <iostream>

using json = nlohmann::json;

TableData::TableData(){
    _maxId = 0;
    _data.resize(0);
}
int TableData::GetMaxID(){
    return _maxId;
}
void TableData::SetMaxID(int i){
    _maxId = i;
}
vector <TableUnit*> TableData::GetTableData(){
    return _data;
}
void TableData::SetTableData(TableUnit* tU, int i){
    if(i >= 0 && i < _data.size()) _data[i] = tU;
}
void TableData::ReSize(int n){
    _data.resize(n);
}
void TableData::DeleteUnit(int i){
    _data.erase(_data.begin() + i);
}
int TableData::PushBack(TableUnit* tU){
    // if(_maxId < tU->GetID()){
    //     _maxId = tU->GetID();
    // }
    _data.push_back(tU);
    return _maxId;
    
}
TableUnit* TableData::GetPointer(int i){
    TableUnit* tU = nullptr;
    if(i >= 0 && i < _data.size()) tU = _data[i];
    return tU;
}
string TableData::ToString(){
    string s("");
    int i = 0;
    for (auto d:_data){
        s += to_string(++i) + ". ";
        s += (*d).ToString();
        s += "\n";
    }
    return s;
}
TableUnit* TableData::NewPoint(){
    TableUnit* tU;
    return tU;
}
int TableData::FindUnit(string name, string value){
    vector<string> vtName = _data[0]->MemberName;
    int pos = -1;
    for(int i = 0; i < vtName.size(); i++){//tim ten member
        if (vtName[i] == name) pos = i;
    }
    if (pos == -1) return pos;// khong tim thay member
    for (int i = 0; i < _data.size(); i++){//tim gia tri member
        _data[i]->SetValueVector();
        vector<string> vtValue = _data[i]->MemberValue;
        if ((_data[i]->MemberValue)[pos] == value) return i;//tra ve vi tri member
    }
    return -1;
}