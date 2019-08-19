/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.06.03 [1-05_with_header_reverse.c]
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
 * Exercise 1-05
 *
 * "Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0."
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
 int8_t  int8_step    = -20; // step size (negative, to achieve reverse order)
 uint16_t int16_lower = 0;   // temperature table: lower limit
 uint16_t int16_upper = 300; // temperature table: upper limit

 float float_fahr = (float)int16_upper; // temperature in Fahrenheit (now initialized with upper bound value...)
 float float_celsius;                   // temperature in Celsius

 ////////// _END: lvars //////////


 printf("----------------\n");
 printf("|  °F  |  °C   |\n");
 printf("----------------\n");

 while (float_fahr >= int16_lower)
      {
       float_celsius = 5.0F / 9.0F * (float_fahr - 32.0F);
       printf("|%5.1f | %5.1f |\n", float_fahr, float_celsius);
       float_fahr = float_fahr + int8_step;
      }
 printf("----------------\n");


 return EXIT_SUCCESS;
}
