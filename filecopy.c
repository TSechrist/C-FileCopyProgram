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
    char bufferRead[BUFF_MAX];
    int sum = 0;

    printf("Welcome to the File Copy Program by Thomas Sechrist!\n");
    printf("Enter the name of the file to copy from:");
    scanf("%s", inFileName);
    printf("Enter the name of the file to copy to: ");
    scanf("%s", outFileName);

    int inFileStream = open(inFileName, O_RDONLY);
    int outFileStream = open(outFileName, O_WRONLY | O_CREAT, 0666);
    ssize_t bufferReadSum;

    //If inFileStream isn't a readable file
    if (inFileStream < 0)
    {
        close(inFileStream);
        close(outFileStream);
        perror("***READ FILE ERROR***");
        return -42;
    }

    //If outFileStream isn't a real file or newly created file
    if (outFileStream < 0)
    {
        close(inFileStream);
        close(outFileStream);
        perror("***WRITE FILE ERROR***");
        return -42;
    }

    printf("Both files opened correctly\n");

    for (bufferReadSum = read(inFileStream, bufferRead, BUFF_MAX);
    bufferReadSum > 0; bufferReadSum = read(inFileStream, bufferRead, BUFF_MAX))
    {
        //This check is for newlines, to make sure it is not skipping empty lines
        if(bufferReadSum != write(outFileStream, bufferRead, (size_t)bufferReadSum))
        {
            close(inFileStream);
            close(outFileStream);
            perror("***COPY FILE ERROR***");
            return -42;
        }
        sum = sum + (size_t)bufferReadSum;
    }

    //Test to see if read returned -1
    if (bufferReadSum < 0)
    {
        close(inFileStream);
        close(outFileStream);
        perror("***FILE READ ERROR***");
        return -42;
    }

    printf("File copied correctly\n");
    printf("Number of bytes copied %d\n", sum);

    close(inFileStream);
    close(outFileStream);

    return 0;
}
