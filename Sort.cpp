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
        double temp = 0;
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
        
        for(int j = (i + 1); j < sortNum; ++j){
            if(myArray[j] < myArray[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            double temp = myArray[i];
            myArray[i] = myArray[minIndex];
            myArray[minIndex] = temp;
        }
        
    }
}

double Sort::insertSort(double myArray[], int sortNum){
    //int i = 0;
    for(int j = 1; j < sortNum;j++){
        double temp = myArray[j];
        int k = j - 1;
        while(k >= 0 && myArray[k] >= temp){
            myArray[k + 1] = myArray[k];
            --k;
        }
        myArray[k + 1] = temp;
    }
}

void Sort::swap(double& a, double& b)  
{  
    double t = a;  
    a = b;  
    b = t;  
} 
int Sort::partition (double myArray[], int low, int high)  
{  
    double pivot = myArray[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (myArray[j] <= pivot)  
        {  
            i++; // increment index of smaller element  
            swap(myArray[i], myArray[j]);  
        }  
    }  
    swap(myArray[i + 1], myArray[high]);  
    return (i + 1);  
}  
  
void Sort::quickSort(double myArray[], int low, int high)  
{ 
    if (low < high)  
    {  
        double pi = partition(myArray, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(myArray, low, pi - 1);  
        quickSort(myArray, pi + 1, high);  
    } 
}

void Sort::merge(double myArray[], int l, int m, int r) 
{ 
    int i, j; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
   double* leftArray = new double[n1];
   double* rightArray = new double[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < n1; i++){
        leftArray[i] = myArray[l + i];
    }
         
    for (int j = 0; j < n2; j++){
        rightArray[j] = myArray[m + 1+ j];
    }     
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (leftArray[i] <= rightArray[j]) 
        { 
            myArray[k] = leftArray[i]; 
            i++; 
        } 
        else
        { 
            myArray[k] = rightArray[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        myArray[k] = leftArray[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        myArray[k] = rightArray[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void Sort::mergeSort(double myArray[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(myArray, l, m); 
        mergeSort(myArray, m+1, r); 
  
        merge(myArray, l, m, r); 
    } 
} 

