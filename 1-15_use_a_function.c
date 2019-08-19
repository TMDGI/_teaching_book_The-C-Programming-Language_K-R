/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.05 [1-15_use_a_function.c]
 * @lines    : 22
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT (FROM LINES 1 TO 21) IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */


/*
"
Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion.
"
*/


#include <stdio.h>
#include <stdlib.h>





void Fahr_To_Celsius()
{
 float fahr, Celsius;
 int lower, upper, step;


 lower = 0;    // lower limit of temperature table
 upper = 300;  // upper limit
 step  = 20;   // step size

 printf("----------------\n");
 printf("|  °C  |  °F   |\n");
 printf("----------------\n");

 fahr = lower;
 while (fahr <= upper)
      {
       Celsius = (5.0 / 9.0) * (fahr - 32.0);
       printf("|%5.1f | %5.1f |\n", fahr, Celsius);
       fahr = fahr + step;
      }

 printf("----------------\n");
}





/* print Celsius-Fahrenheit table
for fahr = 0, 20, 300; floating-point version */

int main()
{
 Fahr_To_Celsius();


 return EXIT_SUCCESS;
}
