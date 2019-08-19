/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.03 [1-12_one_word_per_line.c]
 * @lines    : 21
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT (FROM LINES 1 TO 20) IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */


/*
"
Exercise 1-12. Write a program that prints its input one word per line.
"
*/



#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: Data Defs


#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */


////////////////////////////// __END: Data Defs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


int main()
{
 long c, state;

 ////////// _END: lvars //////////


 state = OUT;
 while ((c = getchar()) != EOF)
      {
       if (c == ' ' || c == '\n' || c == '\t')
         {
          // Print 1 word per line -> always print \n immediatly AFTER WORD END!
          // This means that "IF WE WERE on a word and CURRENT CHAR NOT '\n' interrupts it" -> print the '\n'!
          if (state == IN && c != '\n')
            {
             printf("\n");
            }
          state = OUT;
         }
       else {
             if (state == OUT)
               {
                state = IN;
               }
            }
       printf("%c", (char)c);
      }


 return EXIT_SUCCESS;
}
