#include"INCLUDE/General.h"
#include"INCLUDE/GetLabAttribute.h"

size_t BufferLength = 100;
const char* FileName = "DataBaseCreator/CreatorData.txt";

char* buffer = (char*) calloc(BufferLength, sizeof(char));
static void CleanBuffer(char* buffer, size_t Length);

static void CleanBuffer(char* buffer, size_t Length)
{
    for (size_t i = 0; i <= Length; i++)
        buffer[i] = 0;
}

DataBase CheckCreatorDataBase(void)
{
    FILE* DataBase =  fopen(FileName, "a+");

    if (!DataBase)
        return ErrorDataBase;
    
    fseek(DataBase, 0, SEEK_END);
    long Position = ftell(DataBase);
    rewind(DataBase);
    
    
    if (Position == 0)               // Check if file is empty; __ if pointer of file points to the EOF  
        Position = NewCreator;       // feof return non-zero value, else returns 0
    else Position = OldCreator;

    int Error = 0;

    switch (Position)
  {
    case NewCreator:
      printf("We are happy to see somebody new joining us!\n");
      Error = CreateDataBase(DataBase);
      if (Error == ErrorScanDataBase || Error == ErrorWriteDataBase)
      {
        printf("Error number %d", Error);
        return ErrorDataBase;
      }
      break;

    case OldCreator:
      printf("We are happy to see you my old friend!\n");
      break;

    default:
      printf("Somebody made a mess in main\n");
     break;
  }

  fclose(DataBase);

  return SuccDataBase;
    // struct stat file_inf = {};
    // stat(FileName, &file_inf);
  
    // char* buffer = (char*)calloc((size_t)file_inf.st_size + 1, sizeof(char));
    // fread(buffer, sizeof(char), (size_t)file_inf.st_size, file);
}

DataBase CreateDataBase(FILE* DataBase)
{
    //size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
    
    printf("Enter your full name you want to see in your lab:\n");
    if (!scanf("%[^\n]", buffer))
        return ErrorScanDataBase;

    int NameRead = 0;
    if ((NameRead = fwrite(buffer, sizeof(char), strlen(buffer), DataBase)) != strlen(buffer))
        return ErrorWriteDataBase;
    fprintf(DataBase, "\n%d\n", NameRead);

    //Cleaning buffers
    while(getchar()!= '\n');
    CleanBuffer(buffer, strlen(buffer));


    printf("Enter your study group\n");
    if (!scanf("%[^\n]", buffer))
        return ErrorScanDataBase;

    int GroupName = 0;
    if ((GroupName = fwrite(buffer, sizeof(char), strlen(buffer), DataBase)) != strlen(buffer))
        return ErrorWriteDataBase;
    fprintf(DataBase, "\n%d\n", GroupName);

    //Cleaning buffers
    while(getchar()!= '\n');
    CleanBuffer(buffer, strlen(buffer));
    

    printf("Tell something about yourself\n");
    if (!scanf("%[^\n]", buffer))
        return ErrorScanDataBase;

    int AddInfo= 0;
    if ((AddInfo = fwrite(buffer, sizeof(char), strlen(buffer), DataBase)) != strlen(buffer))
        return ErrorWriteDataBase;

    fprintf(DataBase, "\n%d\n", AddInfo);
    //Cleaning buffer
    while(getchar()!= '\n');
    CleanBuffer(buffer, strlen(buffer));
    
    return SuccDataBase;
}




int ReadDataBase(FILE* file, struct Creator* Data)
{
    int NameRead = 0;
    int ReadGroup = 0;

    
    fscanf(file, "%[^\n]%d\n", buffer, &NameRead);
    
    for (size_t i = 0; i < NameRead; i++)
    {
       Data->Name[i] = buffer[i]; 
       printf("%c", buffer[i]);
    }

    printf("\n");
    CleanBuffer(buffer, BufferLength);

    fscanf(file, "%[^\n]%d\n", buffer, &ReadGroup);

    for (size_t i = 0; i < ReadGroup; i++)
    {
        Data->Group[i] = buffer[i];
        printf("%c", buffer[i]);
    }

    CleanBuffer(buffer, BufferLength);


    return 0;
}

int GetOption()
{
    int Arg = 0;
    while(!scanf("%d", &Arg))
    {
        printf("Anable to read\nPlease try again\n");
        while(getchar()!= '\n');
    }

    while(getchar()!= '\n');

    return Arg;
}

char* GetStringAtr(void)
{
    while (!scanf("%[^\n]", buffer))
    {
        printf("Sorry couldn't read the line\n");
        while(getchar()!= '\n');
    }

    while(getchar()!= '\n');
    
    return buffer;
}