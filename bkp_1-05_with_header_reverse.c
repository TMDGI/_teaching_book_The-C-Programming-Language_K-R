Exercise 1-05. Modify the temperature conversion program to print the table in/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.03 [1-05_with_header_reverse.c]
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
Exercise 1-05. Modify the temperature conversion program to print the table in
reverse order, that is, from 300 degrees to 0
"
*/



#include <stdio.h>
#include <stdlib.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/* print Fahrenheit-Celsius table
for fahr = 300, -20, 0; floating-point version */

int main()
{
 float fahr, Celsius;
 int lower, upper, step;

 ////////// _END: lvars //////////


 lower = 0;   // lower limit of temperature table
 upper = 300; // upper limit
 step  = -20; // step size

 printf("----------------\n");
 printf("|  °F  |  °C   |\n");
 printf("----------------\n");

 fahr = (float)upper;
 while (fahr >= lower)
      {
       Celsius = 5.0F / 9.0F * (fahr-32.0F);
       printf("|%5.1f | %5.1f |\n", fahr, Celsius);
       fahr = fahr + step;
      }
 printf("----------------\n");


 return EXIT_SUCCESS;
}
