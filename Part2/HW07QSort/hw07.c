// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  FILE * file_int;
  file_int = fopen(filename,"r");
  int int_num;
  int count = 0;
  if (file_int == NULL)
  {
    return -1;
  }
  else
  {
    while (fscanf(file_int, "%d", &int_num)!=EOF)
    {
      count++;
    }
    return count;
  }
  fclose(file_int);
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  return true;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  int int_num;
  int count=0;
  FILE * file_int;
  file_int = fopen(filename,"r");
  if (file_int == NULL)
  {
    return false;
  }
  else
  {
    while (fscanf(file_int, "%d", &int_num)!=EOF)
    {
      intArr[count] = int_num;
      count ++;
    }
    if (count != size)
    {
      return false;
    }
  }
  fclose(file_int);
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true

  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  const int * num1 = (const int*)p1;
  const int * num2 = (const int*)p2;
  int value1 = *num1;
  int value2 = *num2;
  if (value1 < value2)
  {
    return -1;
  }
  if (value1 == value2)
  {
    return 0;
  }
  return 1;
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  FILE * file_int;
  file_int = fopen(filename,"w");
  if (file_int == NULL)
  {
    return false;
  }
  else 
  {
    for (int index; index < size; index++)
    {
    fprintf(file_int, "%d\n",intArr[index]);
    }
  }
  fclose(file_int);
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
  return true;
}
#endif
