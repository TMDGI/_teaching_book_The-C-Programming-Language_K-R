/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.03 [1-14_histogram_freq_chars.c]
 * @lines    : 21
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT FROM LINES 1 TO @lines IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */


/*
"
Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
"
*/



#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: Data Defs


#define IN  1 // inside a word
#define OUT 0 // outside a word

#define INT_MAX_ASCII_RANGE 128 // Original ascii charset range: [0..127]


////////////////////////////// __END: Data Defs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/*
__SEE: http://www.asciitable.com/
Original ascii table charset ranges from 0 to 127, while extended ranges from 0 to 255.
Since nothing is said for using one or the other, we will only count individual char frequencies on the ascii original
range, while counting all other characters as the same "nos standard char"!
*/

int main()
{
 int  int_char_cur;                             // current char read
 long long_non_standard_chars = 0;              // count the number of non-standard/"out of ascii range" chars
 int array_freq_histogram[INT_MAX_ASCII_RANGE]; // array containing the char frequency histogram

 ////////// _END: lvars //////////


 for (int i = 0; i < INT_MAX_ASCII_RANGE; i++) { array_freq_histogram[i] = 0;}


 while ((int_char_cur = getchar()) != EOF)
      {
       if (int_char_cur >= 0 && int_char_cur < INT_MAX_ASCII_RANGE)
         {
          array_freq_histogram[int_char_cur]++;
         }
       else {
             long_non_standard_chars++;
             printf("NS: (%d) |%c|\n", int_char_cur, (char)int_char_cur);
            }
      }


 // Print the HORIZONTAL HISTOGRAM for chars freq:
 printf("----------------------------\n-  HISTOGRAM -> Char Freq  -\n----------------------------\n\n");
 printf("char [i,c] | freq\n__________ | ____\n\n");
 for (int i = 0; i < INT_MAX_ASCII_RANGE; i++)
    {
     if (i != 27) // escape char problematic in consoles...
       {
        printf("[%3d , %c]  | ", i, (char)i);
       }

     // __PERFORMANCE: notice how we avoid to always search at array index!
     int k = array_freq_histogram[i];
     while (k)
          {
           printf("*");
           k--;
          }
     printf("\n");
    }
 printf("\nNON-STANDARD CHARS FREQ: |%ld|\n", long_non_standard_chars);


 return EXIT_SUCCESS;
}
