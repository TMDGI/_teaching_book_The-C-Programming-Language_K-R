/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.06.03 [1-06_verify_getchar_EOF.c]
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
 * Exercise 1-06
 *
 * "Verify that the expression getchar ( ) 1 = EOF is 0 or 1."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/*
EOF can be given from stdin/keyboard with CTRL+D (Linux) or CTRL+Z (Windows)
*/

int main()
{
 // current char being read: VERY EXCEPTIONALLY, we can use uint8 type because here we DON'T READ -1 from getchar()!
 uint8_t uint8_char_cur;

 ////////// _END: lvars //////////


 do {
     uint8_char_cur = getchar() != EOF;
     printf("|%"PRIu8"|\n", uint8_char_cur);
    }
 while ( uint8_char_cur != 0 );


 return EXIT_SUCCESS;
}
