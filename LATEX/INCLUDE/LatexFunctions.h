
enum LabOptions
{
  LabInProgress = -1,
  EndOfLab  = 0,
  MakeTable = 1,
};

int CreateLab(void);
int MakeTitle(FILE* TexFile, FILE* DataBase);
int MakeTableFunc(FILE* TexFile);
int EndDocument(FILE* TexFile);