# detect-language

Detect language using statistics, The program read the file located in data and use the given frequencies, This file has to have the CSV separated by a comma ','

## Encoding 
As the program handles several languages, it was mecessary to use more suitable encoding than the standard ascii. The program use the en_US.utf8. Please check the enviromment variable LANG and ensure that the package is installed in the machine or give the desired encoding the program argument. 

### Example 
./detect_language $LANG

## Implementation 

The program has been implemented in C++ because it is optimal and can show the programming skills, especially the exercise is quite challenging and makes fun 
The program was compiled with gcc 10.2 and tested for clang but it should work as well for Mingw or cygwin because it uses only POSIX.

## Method

The program calculates the letter frequency inside a given string and performs some operation to get the error compared to the excepted frequency for all the predefined languages.

## Language predefinition 
The folder data contains two files the letter frequency is used for the application itself while all frequency file has more languages which can be copied into the letter frequency using a table program reader or to change the INPUT FREQUENCIES DATA from the detect language header file to this file to get more language support


## Features 
It is possible to print the supported languages and to see the whole letter frequency.  
