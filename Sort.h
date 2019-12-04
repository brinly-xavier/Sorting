/*
Brinly Xavier
2316142
xavier@chapman.edu
CPSC 350 -01
Sorting Assignment: 06
*/

using namespace std;
class Sort
{
  public:
    void bubbleSort(double myArray[], int sortNum);
    double selectionSort(double myArray[], int sortNum);
    double insertSort(double myArray[], int sortNum);
    void swap(int* a, int* b);
    int partition (double myArray[], int low, int high);
    void quickSort(double myArray[], int low, int high);
    double printArray(double myArray[], int sortNum);
};