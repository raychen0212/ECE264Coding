// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
  FILE * file_string;
  file_string = fopen(filename,"r");
  int sum;

  if (file_string == NULL)
  {
    return -1;
  }
  else
  {
    sum = 0;
    while (fgets(line,size,file_string) != NULL)
    {
      char *wording = line;
      
      while (wording != NULL)
        {
          wording = strstr(wording,word);
          if(wording != NULL)
          {
            wording = wording + strlen(word);
            sum += 1;
          }
        }
      
    }
    return sum;
  }

  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line
  // open a file whose name is filename for reading
  // if fopen fails, return -1. 
  // if fopen succeeds, set sum to zero
  // use fgets to read the file
  // if word appears in a line, add one to sum
  //
  // It is possible that the same word appears multiple times in a line
  // If this word is split in two or more lines, do not count the word.
  //
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.
  //
  // return sum
  //
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the
  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
fclose(file_string); 
  return 0;
}
#endif
