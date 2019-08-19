/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.06.03 [1-08_count_btn.c]
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
 * Exercise 1-08
 *
 * "Write a program to count blanks, tabs, and newlines."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: Data Defs

#define _C_DISPLAY_FIELD 3 // variable display field/padding: depending on text size, this can be very useful...

////////////////////////////// __END Data Defs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


int main()
{
 uint32_t uint32_n_blanks = 0; // input: count number of blanks
 uint32_t uint32_n_nls    = 0; // input: count number of new lines
 uint32_t uint32_n_tabs   = 0; // input: count number of tabs

 // input: current char read from getchar() -> must handle {-1, [0..255]} )! If not for the possible EOF==-1, type char
 // range would be covered with uint8_t type!!! See getchar() man RETURN definition ahead...
 int16_t  int16_char_cur;

 ////////// _END: lvars //////////


 // getchar(): "... return the character read as an unsigned char cast to an int or EOF on end of file or error."
 while ( (int16_char_cur = (int16_t)getchar()) != EOF )
      {
       // printf("int16_char_cur: |%"PRId16"|\n", int16_char_cur);

       // __NOTICE: it does not hurt __PERFORMANCE to order ifs by most likely char to come from our input...
       if (int16_char_cur == ' ')
         {
          uint32_n_blanks++;
         }
       else if (int16_char_cur == '\n')
              {
               uint32_n_nls++;
              }
       else if (int16_char_cur == '\t')
              {
               uint32_n_tabs++;
              }
      }

 printf("n_blanks:    |%*"PRIu32"|\nn_new_lines: |%*"PRIu32"|\nn_tabs:      |%*"PRIu32"|\n", _C_DISPLAY_FIELD,
         uint32_n_blanks, _C_DISPLAY_FIELD, uint32_n_nls, _C_DISPLAY_FIELD, uint32_n_tabs);


 return EXIT_SUCCESS;
}
