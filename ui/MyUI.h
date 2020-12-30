#ifndef Project_ui_MyUI_H_
#define Project_ui_MyUI_H_
#include <string>
#include "../dataaccess/TableData.h"

using namespace std;

class MyUI{
private:
public:
    MyUI();
    int ExportToStringFile(TableData tD, string filename);
    void ImportFromStringFile(TableData* tD, string filename);
    void AddToTable(TableData* tD);
};

#endif