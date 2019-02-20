#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //



int
main(int argc, char const *argv[])
{

    char outFileName[255];
    char inFileName[255];

    printf("Welcome to the File Copy Program by Thomas Sechrist!\n");
    printf("Enter the name of the file to copy from:");
    scanf("%s", outFileName);
    printf("Enter the name of the file to copy to: ");
    scanf("%s", inFileName);

    int inFileStream = open(inFileName, O_RDONLY);
    int outFileStream = open(outFileName, O_WRONLY);

    if (inFileStream < 0)
    {
        perror("***READ FILE ERROR***");
        return -42;
    }

    if (outFileStream < 0)
    {
        close(inFileStream);
        perror("***WRITE FILE ERROR***");
        return -42;
    }

    printf("Both files opened correctly\n");

    close(inFileStream);
    close(outFileStream);

    return 0;
}