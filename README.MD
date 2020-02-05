# CSC 415 - File copy

## Student Name : Thomas Sechrist

## Build Instructions
Used MakeFile to create a program named fc. 
gcc -I -Wall filecopy.c -o fc

## Run Instructions
./fc in the terminal after the project is built.

## strace/dtruss output
The inital few lines of my strace is opening and reading a few libraries that
I have imported. After reading the libraries, then it uses mmap to map to 
specific spots in memory. After all of these mappings, it writes to the terminal
my entry prompt. After that it reads in the first file inputted then writes back
to the terminal to enter my next file then reads that in. It then opens each file
with the flags I set for the open commands. Then prints that both were opened
correctly. After that there are about 10 read and write calls that transfers over
the contents of the first file and writes it into the second. After it prints
a prompt that the file transfered correctly and prints the number of bytes that
were copied. Then it closes both files that were open and finally exits 0.

Welcome to the File Copy Program by Thomas Sechrist!
Enter the name of the file to copy from:test1
Enter the name of the file to copy to: test2
Both files opened correctly
File copied correctly
Number of bytes copied 196
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0        14           read
  0.00    0.000000           0        16           write
  0.00    0.000000           0         4           open
  0.00    0.000000           0         4           close
  0.00    0.000000           0         4           fstat
  0.00    0.000000           0         1         1 lseek
  0.00    0.000000           0         6           mmap
  0.00    0.000000           0         4           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         3         3 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    62         4 total

