/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.06.03 [1-09_copy_input_trim_spaces.c]
 * @lines    : 24
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT FROM LINES 1 TO @lines IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *
 * Exercise 1-09
 *
 * "Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


int main()
{
 int16_t int16_char_prev = EOF; // input : no previous char has been read!
 int16_t int16_error_put = 1;   // output: test for output write error (will hold EOF in case of error!)

 int16_t int16_char_cur; // input: current char read from a getchar() call


 ////////// _END: lvars //////////


 while ( ((int16_char_cur = (int16_t)getchar()) != EOF) && (int16_error_put != EOF) )
      {
       // printf("int_char_cur: |%d|\n", int_char_cur);
       /*
       This would be the "1st try amateur code"...don't forget to always perform "if analysis" on nested if branches!
       if (int_char_cur == ' ')
         {
          if (int_char_prev != ' ')
            {
             int_error_put = putchar(int_char_cur);
            }
         }
       else {
             int_error_put = putchar(int_char_cur);
            }
       */

       if (int16_char_cur != ' ' || int16_char_prev != ' ')
         {
          // __NOTICE: although both putchar() and printf() can be used -> for large volumes of input-output copy,
          //           putchar() as "the C lib function" should have at least some performance advantage over printf();
          //           however, this should be tested, per OS!
          //
          // printf("%c", int_char_cur);
          int16_error_put = (int16_t)putchar(int16_char_cur);
         }

       int16_char_prev = int16_char_cur;
      }

 // __NOTICE: EOF does NOT need to be copied!

 // This if checks the limit scenario where a write error occurred in the last char to be copied!
 if (int16_error_put == EOF)
   {
    printf("FATAL ERROR: could not copy full input file -> check for write permissions on output and/or destination\
            full!");
    exit(EXIT_FAILURE);
   }


 return EXIT_SUCCESS;
}
