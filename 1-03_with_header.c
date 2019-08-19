/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.08.13 [1-03_with_header.c]
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
 * Exercise 1-03
 *
 * "Modify the temperature conversion program to print a heading above the table."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/* print Fahrenheit-Celsius table
   for float_fahr = 0, 20, 300; floating-point version */

int main()
{
 uint8_t  uint8_step   = 20;  // step size
 uint16_t uint16_lower = 0;   // temperature table: lower limit
 uint16_t uint16_upper = 300; // temperature table: upper limit

 float float_fahr = (float)uint16_lower; // temperature in Fahrenheit
 float float_celsius;                    // temperature in Celsius

 ////////// _END: lvars //////////


 printf("----------------\n");
 printf("|  °F  |  °C   |\n");
 printf("----------------\n");

 while (float_fahr <= uint16_upper)
      {
       float_celsius = 5.0F / 9.0F * (float_fahr - 32.0F);
       printf("|%5.1f | %5.1f |\n", float_fahr, float_celsius);
       float_fahr = float_fahr + uint8_step;
      }
 printf("----------------\n");


 return EXIT_SUCCESS;
}
