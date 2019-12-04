
/*
Brinly Xavier
2316142
xavier@chapman.edu
CPSC 350 -01
Sorting Assignment: 06
*/

#include "Sort.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//string filename;
int sortNum;
string answer;
int main(int argc, char **argv){
    string filename = argv[1]; 
    ifstream exlist;
    string line;
    exlist.open(filename);
    //this checks to make sure that the file that the user wants to open is legit
    if (exlist.is_open())
    {
        cout<< "File successfully open"<<endl;
    }
    else
    {
        throw runtime_error("The file you entered could not be opened. Try again Later.");
    }
    
    string sNum = "";
    getline(exlist, line);
    //this sets the height and width from the file
    sortNum = stod(line);
    double* bubbleArray = new double[sortNum];
    double* selectArray = new double[sortNum];
    double* insertArray = new double[sortNum];
    double* quickArray = new double[sortNum];
    //initialize the array
    Sort sorting;
    
    //this takes the file and puts it into an array

    //this for loop takes the characters from the file and sets them into the board
    for(int i = 0; i < sortNum; ++i){
        getline(exlist, line);
        bubbleArray[i] = stod(line);
        selectArray[i] = stod(line);
        insertArray[i] = stod(line);
        quickArray[i] = stod(line);
        
    }
    sorting.bubbleSort(bubbleArray, sortNum);
    sorting.selectionSort(selectArray, sortNum);
    sorting.insertSort(insertArray, sortNum);
    //sorting.quickSort(quickArray, sortNum);
    exlist.close();
   
    cout<<"The Bubble Sort is: "<<endl;
    sorting.printArray(bubbleArray, sortNum);
    
    cout<<"The Selection Sort is: "<<endl;
    sorting.printArray(selectArray, sortNum);
    
    cout<<"The Insertion Sort is: "<<endl;
    sorting.printArray(insertArray, sortNum);

    cout<<"The Quick Sort is: "<<endl;
    sorting.printArray(quickArray, sortNum);


    return 0;
}