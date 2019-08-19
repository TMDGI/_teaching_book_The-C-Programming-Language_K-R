/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.08.13 [1-02_printf_modifier.c]
 * @lines    : 25
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
 * Exercise 1-02
 *
 * "Experiment to find out what happens when printf’s argument string contains \c, where c is some character not listed
 *  above."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()



int main()
{
 printf("Hello World Exercise: |\p|\n"); // __COMPILER_WARNING "warning: unknown escape sequence: '\p'"


 return EXIT_SUCCESS;
}
