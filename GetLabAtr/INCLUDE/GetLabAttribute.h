#ifndef LAB_ATTRIBUTES
#define LAB_ATTRIBUTES

#include <sys/stat.h>
#include <string.h>

enum DataBase
{
    ErrorDataBase = 0,
    ErrorScanDataBase = 1,
    ErrorWriteDataBase = 2,
    NewCreator    = 3,
    OldCreator    = 4,
    SuccDataBase  = 5,
};

enum LabName
{
    CreatorName = 1,
    LabName     = 2,
};

struct Creator
{
    char Name[30];
    char Group[10];
    char AdInf[50];
};

DataBase CheckCreatorDataBase(void);
DataBase CreateDataBase(FILE* DataBase);
int ReadDataBase(FILE* file, struct Creator* Data);

// struct LabCreator
// {

// };

#endif

