/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.03 [1-11_test_wc.c]
 * @lines    : 22
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT FROM LINES 1 TO @lines IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */


/*
"
Exercise 1-11. How would you test the word count program? What kinds of
input are most likely to uncover bugs if there are any?
"
*/



#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: Data Defs


#define IN  1 // inside a word
#define OUT 0 // outside a word


////////////////////////////// __END: Data Defs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/*
__NOTICE: In response to this exercise, we will use the same source code presented in the book (ok: changed counters
from int to long...also, nicer user output!), and will craft an input file such as to test a good amount of cases that
to our best imagination would be a nice set test, although a complete test set would have to include multiple input
files and test at least for at least the following cases:

1. first char is any of: { ' ', '\n', '\t' }
2. first n chars (n > 1) are also in set: { ' ', '\n' or '\t' }
3. first char is alphanumeric ( { a..z, A..Z, 0-9 } ) then any of { ' ', '\n', '\t' }
4. first n chars are alphanumeric

5. Repeat previous items 1-4 at THE END of the input test file.

6. "Test limits" -> very large words (ex: > 100 chars)

7. Experiment with various different combinations in the middle of the file, including all chars in ASCII range (__SEE:
http://www.asciitable.com)

...
*/

int main()
{
 long c, nl, nw, nc, state;

 ////////// _END: lvars //////////


 state = OUT;
 nl = nw = nc = 0;

 while ((c = getchar()) != EOF)
      {
       printf("c is: |%ld| (%c)\n", c, (char)c);
       ++nc;
       if (c == '\n')
          ++nl;

       if (c == ' ' || c == '\n' || c == '\t')
          state = OUT;
       else if (state == OUT)
              {
               state = IN;
               ++nw;
              }
      }

 printf("\nn_lines: |%ld| *** n_words: |%ld|\n n_chars: |%ld|\n", nl, nw, nc);


 return EXIT_SUCCESS;
}
