// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
FILE * file_integer;
file_integer = fopen(filename,"r");
if(file_integer == NULL)
{
  return false;
}
if(fseek(file_integer,0,SEEK_END) != 0)
{
  fclose(file_integer);
  return false;
}

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false

int file_size = ftell(file_integer);
  // use ftell to determine the size of the file
if(fseek(file_integer,0,SEEK_SET)!=0)
{
  fclose(file_integer);
  return false;
}

  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
*size = file_size / sizeof(int);
  // the number of integers is the file's size divided by
  // size of int  
int *array = malloc (sizeof(int) * *size);
if (array == NULL)
{
  fclose(file_integer);
  return false;
}  

  // allocate memory for the array
  // if malloc fails, fclose and return false
if(fread(array,sizeof(int),*size,file_integer)!=*size)
{
  free(array);
  fclose(file_integer);
  return false;  
}
  // use fread to read the number of integers in the file
  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
fclose(file_integer);

  // if fread succeeds
  // close the file

  
  // update the argument for the array address


  
  // update the size of the array


  *arr = array;
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
FILE * file_integer;
file_integer = fopen(filename,"w");
if(file_integer == NULL)
{
  return false;
}
if (fwrite(arr,sizeof(int),size,file_integer) != size)
  {
    fclose(file_integer);
    return false;
  }

fclose(file_integer);
return true;
  // if fopen fails, return false



  // use fwrite to write the entire array to a file



  // check whether all elements of the array have been written



  // fclose


  
  // if not all elements have been written, return false



  // if all elements have been written, return true





}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif
int max1 = m-l+1;
int max2 = r-m;
  // if one or both of the arrays are empty, do nothing
if(max1<1 || max2<1)
{
  return;
}
int * arr1 = malloc (sizeof(int)*max1);
int * arr2 = malloc(sizeof(int)*max2);
for (int index1 = 0; index1 < max1;index1++)
{
  arr1[index1]=arr[l+index1];
  //printf("%d\n",arr1[index1]);
}
//printf("end1\n");
for (int index2 = 0; index2 < max2;index2++)
{
  arr2[index2] = arr[m+1+index2];
  //printf("%d\n",arr2[index2]);
}
//printf("end2\n");
int mergeindex1=0;
int mergeindex2=0;
int mergetol = l;
while (mergeindex1 < max1 && mergeindex2 < max2)
{
  if (arr1[mergeindex1]<=arr2[mergeindex2])
  {
    arr[mergetol] = arr1[mergeindex1];
    mergeindex1+=1;
    //printf("%d\n", arr[mergetol]);
  }
  else
  {
    arr[mergetol] = arr2[mergeindex2];
    mergeindex2+=1;
    //printf("%d\n",arr[mergetol]);
    
  }
  //printf("end4\n");
  mergetol+=1;
}
for(int i1 = mergeindex1; i1<max1 ;i1++)
{
  arr[mergetol] = arr1[i1];
  //printf("%d\n", arr[mergetol]);
  mergetol+=1;
}
//printf("end5\n");
for (int i2 = mergeindex2; i2<max2;i2++)
{
  arr[mergetol] = arr2[i2];
  //printf("%d\n", arr[mergetol]);
  mergetol+=1;
  
}
//printf("end6\n");

free(arr1);
free(arr2);
  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write




  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif
int midpt;
  // if the array has no or one element, do nothing
if(l<r)
{
  midpt = (l+r)/2;
  mergeSort(arr,l,midpt);
  mergeSort(arr,midpt+1,r);
  merge(arr,l,midpt,r);
}
else
{
  return;
}
  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  




} 
#endif
