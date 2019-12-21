// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  FILE * file_data;
  int integer_value;
  * sum = 0;
  file_data = fopen(filename,"r");
  if (file_data == NULL)
  {
    return false;
  }
  else
  {
    while (fscanf(file_data,"%d", &integer_value) != EOF)
    {
    *sum += integer_value;
    }
    fclose(file_data);

  }
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  //int integer_value;
  FILE * file_data;
  file_data = fopen(filename, "w");
  if (file_data == NULL)
  {
    return false;
  }
  else
  {
    
      fprintf(file_data, "%d\n",sum);
    
  }
  fclose(file_data);
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  return true;
}
#endif
