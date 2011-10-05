#include "../picoc.h"
#include "../interpreter.h"

/* mark where to end the program for platforms which require this */
jmp_buf PicocExitBuf;

void PlatformInit()
{
}

void PlatformCleanup()
{
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen, const char *Prompt)
{
    if (Prompt != NULL)
        printf("%s", Prompt);
        
    fflush(stdout);
    return fgets(Buf, MaxLen, stdin);
}

/* get a character of interactive input */
int PlatformGetCharacter()
{
    fflush(stdout);
    return getchar();
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh, union OutputStreamInfo *Stream)
{
    putchar(OutCh);
}

/* read a file into memory */
char *PlatformReadFile(const char *FileName)
{
    struct stat FileInfo;
    char *ReadText;
    FILE *InFile;
    int BytesRead;
    
    if (stat(FileName, &FileInfo))
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    ReadText = malloc(FileInfo.st_size + 1);
    if (ReadText == NULL)
        ProgramFail(NULL, "out of memory\n");
        
    InFile = fopen(FileName, "r");
    if (InFile == NULL)
        ProgramFail(NULL, "can't read file %s\n", FileName);
    
    BytesRead = fread(ReadText, 1, FileInfo.st_size, InFile);
    if (BytesRead == 0)
        ProgramFail(NULL, "can't read file %s\n", FileName);

    ReadText[BytesRead] = '\0';
    fclose(InFile);
    
    return ReadText;    
}

/* read and scan a file for definitions */
void PicocPlatformScanFile(const char *FileName)
{
    char *SourceStr = PlatformReadFile(FileName);

    PicocParse(FileName, SourceStr, strlen(SourceStr), TRUE, FALSE, TRUE, TRUE);
}

/* exit the program */
void PlatformExit(int RetVal)
{
    PicocExitValue = RetVal;
    longjmp(PicocExitBuf, 1);
}
