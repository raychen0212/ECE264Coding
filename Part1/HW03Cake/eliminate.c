// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  int count = -1;  
  int index_update = n;
  // counting to k,
  // mark the eliminat//ed element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (index_update > 0)
	{
	    for (int index = 0; index < n; index++)
	    {
	        while(arr[index] == -1 && index < n-1)
	        {
	            index=index+1;
	        }
	        while(arr[index] == -1 && index == n -1)
	        {
	            index = 0;
	            while(arr[index] == -1)
	            {
	            index = index + 1;
	            }
	        }
	        count ++;
	        if (count == k - 1)
	        {
	        arr[index] = - 1;
	        count = - 1;
	        fprintf(stdout,"%d\n",index);
	        index_update--;
          if(index == n - 1)
	          {
	          index = -1;  
	          } 
	        } 
           
	    }
}


  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
