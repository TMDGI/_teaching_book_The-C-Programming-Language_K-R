/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.08.13 [1-04_celsius_to_fahr.c]
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
 * Exercise 1-04
 *
 * "Write a program to print the corresponding Celsius to Fahrenheit table."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/* print Celsius-Fahrenheit table
   for float_fahr = 0, 20, 300; floating-point version */

// __NOTICE: since "corresponding" is not exactly defined, we assume "reverse formula"->corresponding! Also, step and
//           start point are maintained at same values but now applied to Celsius, so table will NOT be symmetrical to
//           °F->°C (although there's a cross symmetrical value at 60°C/140°F).
int main()
{
 uint8_t  int8_step   = 20;  // step size
 uint16_t int16_lower = 0;   // temperature table: lower limit
 uint16_t int16_upper = 300; // temperature table: upper limit

 float float_celsius = (float)int16_lower; // temperature in Celsius
 float float_fahr;                         // temperature in Fahrenheit

 ////////// _END: lvars //////////


 printf("----------------\n");
 printf("|  °C  |  °F   |\n");
 printf("----------------\n");

 while (float_celsius <= int16_upper)
      {
       // float_celsius = 5.0F / 9.0F * (float_fahr - 32.0F);
       float_fahr = (9.0F / 5.0F) * float_celsius + 32.0F;
       printf("|%5.1f | %5.1f |\n", float_celsius, float_fahr);
       float_celsius += int8_step;
      }
 printf("----------------\n");


 return EXIT_SUCCESS;
}
