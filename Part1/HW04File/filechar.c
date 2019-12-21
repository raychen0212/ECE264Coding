// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  FILE * get_char_data;
  int onechar;
  get_char_data = fopen(filename,"r");
  if (get_char_data == NULL)
  {
    return false; 
  }
  else 
  {
    do
    {
      onechar = fgetc(get_char_data);
      if (onechar >= 0 && onechar < size)
      {
        counts[onechar] += 1;
        
      }

    }while(onechar!=EOF);
  }
  fclose(get_char_data);
  
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  for (int ind = 0; ind>=0 && ind < size; ind++)
  {
    
    if (ind <= 90 && ind >= 65 && counts[ind]!=0)
    {
      printf("%d, %c, %d\n",ind,(char)ind,counts[ind]);
    }
    else if(ind>=97 && ind<=122 && counts[ind]!=0)
    {
      printf("%d, %c, %d\n",ind, (char)ind, counts[ind]);
    }
    else if(counts[ind] != 0)
    {
      printf("%d, %c, %d\n",ind,(char) 32, counts[ind]);
    }
  }
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
#endif
