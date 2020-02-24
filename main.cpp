
//10671406 - DAA Assignment
#include <iostream>
using namespace std;

void mergeFunction(int array1[], int l, int m, int r)
{
    int indexOfSortedArray;
    int upperHalf = m - l + 1;
    int lowerHalf =  r - m;

    /* creating temporary arrays */
    int SubArray1[upperHalf], SubArray2[lowerHalf];
    for ( int i = 0; i < upperHalf; i++)
    {

        SubArray1[i] = array1[l + i];
    }



    for ( int j = 0; j < lowerHalf; j++)
    {

        SubArray2[j] = array1[m +1+ j];
    }

    //Block to merge the subarrays
    int i = 0;
    int j = 0;
    indexOfSortedArray = l;
    while (i < upperHalf && j < lowerHalf)
    {
        if (SubArray1[i] <= SubArray2[j])
        {
            array1[indexOfSortedArray] = SubArray1[i];
            i++;
        }
        else
        {
            array1[indexOfSortedArray] = SubArray2[j];
            j++;
        }
        indexOfSortedArray++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < upperHalf)
    {
        array1[indexOfSortedArray] = SubArray1[i];
        i++;
        indexOfSortedArray++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < lowerHalf)
    {
        array1[indexOfSortedArray] = SubArray2[j];
        j++;
        indexOfSortedArray++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSortFunction(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSortFunction(arr, l, m);
        mergeSortFunction(arr, m+1, r);

        mergeFunction(arr, l, m, r);
    }
}


//Main function
int main()
{
    int testArray[] = {44,723,89,76,45,23};
    int length = sizeof(testArray)/sizeof(testArray[0]);

    cout<< "Unsorted Array"<<endl;

    for (int i=0; i < length; i++)
    {
        cout<<testArray[i]<<endl;
    }

    mergeSort(testArray, 0, length - 1);

    cout<<"Array sorted with merge sort"<<endl;
    for (int i=0; i < length; i++)
    {
        cout<<testArray[i]<<endl;
    }
    return 0;
}
