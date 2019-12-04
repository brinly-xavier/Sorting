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

void Sort::bubbleSort(double myArray[], int sortNum){
    for(int i = 0; i < sortNum; ++i){
        int temp = 0;
        for(int j =  0; j < (sortNum - 1); ++j){
            if(myArray[j] > myArray[j + 1]){
                temp = myArray[j+1];
                myArray[j+1] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
}
double Sort::printArray(double myArray[], int sortNum)  
{  
    for (int i = 0; i < sortNum; i++){
        cout << myArray[i] << " ";  
        cout << endl;
    }  
         
} 
double Sort::selectionSort(double myArray[], int sortNum){
    int minIndex;
    for(int i = 0; i < (sortNum - 1); ++i){
        minIndex = i;
        for(int j = i + 1; j < sortNum; ++j){
            if(myArray[j] < myArray[minIndex]){
                minIndex = j;
            }
            if(minIndex != i){
                int temp = myArray[i];
                myArray[i] = myArray[minIndex];
                myArray[minIndex] = temp;
            }
        }
    }
}

double Sort::insertSort(double myArray[], int sortNum){
    int i = 0;
    for(int j = 1; j < sortNum; ++j){
        int temp = myArray[i];
        int k = j;
        while(k > 0 && myArray[k - 1] >= temp){
            myArray[j] = myArray[k -1];
            --k;
        }
        myArray[k] = temp;
    }
}

void Sort::swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 
int Sort::partition (double myArray[], int low, int high)  
{  
    int pivot = myArray[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (myArray[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            //swap(&myArray[i], &myArray[j]);  
        }  
    }  
    //swap(&myArray[i + 1], &myArray[high]);  
    return (i + 1);  
}  
  
void Sort::quickSort(double myArray[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(myArray, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(myArray, low, pi - 1);  
        quickSort(myArray, pi + 1, high);  
    }  
}  

