/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.05.03 [1-13_histograms_freq_words.c]
 * @lines    : 23
 *
 * In short:
 * -> you can : { use at will, even commercially } + { copy, redistribute and transform anyway you want }
 * -> you must: { preserve the same license for any derivative work and/or copy/redistribution} +
 *                KEEP THIS FILE HEADER COMMENT (FROM LINES 1 TO 22) IN THE BEGINNING OF YOUR SHARED/DERIVATIVE WORK }
 *
 */


/*
"
Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging.
"
*/



#include <stdio.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: Data Defs


#define IN  1 // inside a word
#define OUT 0 // outside a word


#define INT_MAX_LENGTH_WORD 100 // We put a maximum to word length


////////////////////////////// __END: Data Defs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


/*
We will assume definition of word as any sequence of 1+ chars contained exclusively in ranges: [0..9] + [a..z] + [A..Z]
By this definition (excluding "0 chars/empty words"), INT_MAX_LENGTH_WORD represents actual max word size (and not -1).
Oh, and of course we will implement BOTH histograms :)
*/
int main()
{
 long c;            // current char
 int len_this_word; // length of current word

 // Words of length n will be counted in array_freq_histogram[n-1], since by definition word -> 1+ chars! Otherwise,
 // position zero would be wasted...so, a classic case where "range of problem starts in 1", but "range of arrays in C
 // start in 0!"
 int array_freq_histogram[INT_MAX_LENGTH_WORD];

 ////////// _END: lvars //////////


 for (int i = 0; i < INT_MAX_LENGTH_WORD; i++) { array_freq_histogram[i] = 0;}

 len_this_word = 0;
 while ((c = getchar()) != EOF)
      {
       // The most obvious word checking would be: "if current char is a word char". This would be expressed by:
       // if ( (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' || c <= 'Z')
       //
       // But since we constructed our program with first if testing for word end (read: non word char) -> we may as
       // well preserve our previous program structure and apply pure Boolean logic NEGATION, in so transforming the
       // previous if into its inverse, read: "if current char is a NON WORD char"! Like this:
       if ( (c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') )
         {
          if (len_this_word)
            {
             array_freq_histogram[len_this_word-1]++;
            }
          len_this_word = 0; // this word has ended -> reset length for next word!
         }
       else {
             // __NOTICE: ALWAYS CHECK YOUR USER: INPUT && INPUT LIMITS!!!
             if (len_this_word < INT_MAX_LENGTH_WORD)
               {
                len_this_word++;
               }
             else {
                   // Proper error handling:
                   printf("FATAL ERROR!\n@File: |%s|\n@Line: |%d|\nError: length == %d!\n",
                          __FILE__, __LINE__, len_this_word);
                   exit(EXIT_FAILURE);
                  }

            }

      }

 // We must not forget the case where predecessor char to EOF was our last word last char!!
 if (len_this_word > INT_MAX_LENGTH_WORD)
   {
    // Proper error handling:
    printf("FATAL ERROR!\n@File: |%s|\n@Line: |%d|\nError: length == %d!\n",
            __FILE__, __LINE__, len_this_word);
    exit(EXIT_FAILURE);
   }
 else if (len_this_word)
     {
      array_freq_histogram[len_this_word-1]++;
     }



 // a) Print the HORIZONTAL HISTOGRAM for the full range of possible lengths in a word:
 printf("-----------------------------\n-  HISTOGRAM -> HORIZONTAL  -\n-----------------------------\n\n");
 printf("[word_length] | freq\n_____________ | ____\n\n");
 for (int i = 0, j = 1; i < INT_MAX_LENGTH_WORD; i++, j++)
    {
     printf("[%3d]:        | ", j);

     // __PERFORMANCE: notice how we avoid to always search at array index!
     int k = array_freq_histogram[i];
     while (k)
          {
           printf("*");
           k--;
          }
     printf("\n");
    }



 // b) Print the VERTICAL HISTOGRAM for the full range of possible lengths in a word: now the strategy will be building
 //    not for each array elem (WORD SIZE), but for WORD FREQUENCY -> TOP DOWN CHECKING ALL frequencies ELEMS FROM MAX TO
 //    MIN!
 //
 //    1st thing to do is to SEARCH FOR A MAX in array_freq_histogram[]...so that we can put a put a bound on our
 //    biggest bar in histogram!!!
 //
 int max_freq_in_any_length = 0;
 for (int i = 0; i < INT_MAX_LENGTH_WORD; i++)
    {
     if (max_freq_in_any_length < array_freq_histogram[i])
       {
        max_freq_in_any_length = array_freq_histogram[i];
       }
    }


 printf("\n\n\n---------------------------\n-  HISTOGRAM -> VERTICAL  -\n---------------------------\n\n");
 printf("freq -> max=|%d|\n\n", max_freq_in_any_length);

 for (int i = max_freq_in_any_length; i > 0; i--) // FOR EACH POSSIBLE N_WORDS IN ANY LENGTH
    {
     printf("               "); // 15 spaces for x-axis label "[word_length]:"
     for (int j = 0; j < INT_MAX_LENGTH_WORD; j++)
        {
         printf(" ");
         if (array_freq_histogram[j] >= i)
           {
            printf("*  ");
           }
         else printf("   ");
        }

      printf("\n");
     }
 printf("[word_length]: "\
        "001 002 003 004 005 006 007 008 009 010 011 012 013 014 015 016 017 018 019 020 "\
        "021 022 023 024 025 026 027 028 029 030 031 032 033 034 035 036 037 038 039 040 "\
        "041 042 043 044 045 046 047 048 049 050 051 052 053 054 055 056 057 058 059 060 "\
        "061 062 063 064 065 066 067 068 069 070 071 072 073 074 075 076 077 078 079 080 "\
        "081 082 083 084 085 086 087 088 089 090 091 092 093 094 095 096 097 098 099 100\n");


 return EXIT_SUCCESS;
}
