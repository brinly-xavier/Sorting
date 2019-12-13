
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
#include <chrono> 
#include <ctime> 

using namespace std;
using namespace std::chrono;
//string filename;
int sortNum;
string answer;
int main(int argc, char **argv){
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
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
        return 0;
    }
    
    string sNum = "";
    getline(exlist, line);
    //this sets the height and width from the file
    sortNum = stod(line);
    double* bubbleArray = new double[sortNum];
    double* selectArray = new double[sortNum];
    double* insertArray = new double[sortNum];
    double* quickArray = new double[sortNum];
    double* mergeArray = new double[sortNum];
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
        mergeArray[i] = stod(line);
        
    }
    cout << "Start of bubble sort: " <<ctime(&timenow) << endl; 
    sorting.bubbleSort(bubbleArray, sortNum);
    cout << "End of bubble sort: " <<ctime(&timenow) << endl; 
    cout<<"The Bubble Sort is: "<<endl;
    sorting.printArray(bubbleArray, sortNum);
    cout<<endl;

    cout << "Start of selection sort: " <<ctime(&timenow) << endl; 
    sorting.selectionSort(selectArray, sortNum);
    cout << "End of selection sort: " <<ctime(&timenow) << endl; 
    cout<<"The Selection Sort is: "<<endl;
    sorting.printArray(selectArray, sortNum);
    cout<<endl;

    cout << "Start of insert sort: " <<ctime(&timenow) << endl; 
    sorting.insertSort(insertArray, sortNum);
    cout << "End of insert sort: " <<ctime(&timenow) << endl;
    cout<<"The Insertion Sort is: "<<endl;
    sorting.printArray(insertArray, sortNum);
    cout<<endl;
    
    cout << "Start of quick sort: " <<ctime(&timenow) << endl; 
    sorting.quickSort(quickArray, 0, sortNum - 1);
    cout << "End of quick sort: " <<ctime(&timenow) << endl;
    cout<<"The Quick Sort is: "<<endl;
    sorting.printArray(quickArray, sortNum);
    cout<<endl;
    
    cout << "Start of insert sort: " <<ctime(&timenow) << endl; 
    sorting.mergeSort(mergeArray, 0, sortNum - 1);
    cout << "End of merge sort: " <<ctime(&timenow) << endl;
    cout<<"The Merge Sort is: "<<endl;
    sorting.printArray(mergeArray, sortNum);
    cout<<endl; 

    exlist.close();
    return 0;
}