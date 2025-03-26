#include "INCLUDE/General.h"
#include "INCLUDE/LatexFunctions.h"
#include "../GetLabAtr/INCLUDE/GetLabAttribute.h"

const char* TexFileName  = "LATEX//OutPutFolder//lab.tex";
const char* DataBaseName = "DataBaseCreator/CreatorData.txt";

int CreateLab(void)
{
  FILE* TexFile = fopen(TexFileName, "w");
  FILE* DataBase = fopen(DataBaseName, "r");
  
  if (!TexFile||!DataBase)
  {                                         
    printf("Error in opening files in function %s line: %d\n", __FUNCTION__, __LINE__);
    return 0;
  }

  MakeTitle(TexFile, DataBase);
  fclose(DataBase);

  EndDocument(TexFile);
  fclose(TexFile);

  return 0;
}


int MakeTitle(FILE* TexFile, FILE* DataBase)
{
  struct Creator Data = {};
  ReadDataBase(DataBase, &Data);

  fprintf(TexFile,    

  "\\documentclass[a4paper,12pt]{article} %% тип документа\n"
                            
  "%%  Русский язык\n"
  "\\usepackage{multirow}\n"
  "\\usepackage{wrapfig}\n"
  "\\usepackage[T2A]{fontenc}			%% кодировка\n"
  "\\usepackage[utf8]{inputenc}			%% кодировка исходного текста\n"
  "\\usepackage[english,russian]{babel}	%% локализация и переносы\n"
  "\\usepackage{graphicx}\n"
  "\\usepackage{todonotes}\n"

  "%% Математика\n"
  "\\usepackage{amsmath,amsfonts,amssymb,amsthm,mathtools}\n"
  "\\usepackage{hyperref}\n"

  "%% графики\n"
  "\\usepackage{pgfplots}\n"
  "\\pgfplotsset{compat=1.9}\n"

  "\\begin{document}\n\\begin{center}\n"
  "{\\large МОСКОВСКИЙ ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ (НАЦИОНАЛЬНЫЙ ИССЛЕДОВАТЕЛЬСКИЙ УНИВЕРСИТЕТ)}\n"
  "\\end{center}\n"
  "\\begin{center}\n"
  "{\\largeФизтех-школа Радиотехники и Компьютерных Технологий}\n"
  "\\end{center}\n"
  "\\vspace{3.5cm}\n"
  "\\vspace{0.1cm}\n"
  "{\\huge\n"
  "\\begin{center}\n"
  "{\\bf Дифференциальная работа 3.3.3}\\\n"
  "\\end{center}\n"
  "}\n"
  "\\vspace{5cm}\n"
  "{\\LARGE Авторы:\\\\ %s \\\\\n"
  "\\newline\n"
  "%s}\n"
  "\\end{flushright}\n"
  "\\vspace{1.5cm}\n"
  "\\begin{center}\n"
  "Долгопрудный 2024\n"
  "\\end{center}\n"
  "\\end{titlepage}\n", Data.Name, Data.Group
  );
  
  return 0;
}


int EndDocument(FILE* TexFile)
{
  fprintf(TexFile, "\\end{document}\n");
  return 0;
}