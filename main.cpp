#include"LATEX/INCLUDE/General.h"
#include"LATEX/INCLUDE/LatexFunctions.h"        // Библеотека содержащая в себе все функции связанные с выводов в Латех
#include"GetLabAtr/INCLUDE/GetLabAttribute.h"   // Библеотека содержащая в себе все функции свящанные с вводом

int main(void)
{
  DataBase DataBaseStatus = CheckCreatorDataBase();
  if (DataBaseStatus == ErrorDataBase)
    return 0;

  MakeTitle();

  return 0;
}