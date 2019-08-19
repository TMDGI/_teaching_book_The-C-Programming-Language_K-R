/**
 * @author   : Tiago Ildefonso
 * @copyright: Tiago Ildefonso
 * @link     : https://github.com/tmgi
 * @license  : https://creativecommons.org/licenses/by-sa/4.0/ (Attribution-ShareAlike 4.0 International)
 * @version  : 2019.06.04 [1-10_copy_unambiguous.c]
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
 * Exercise 1-10
 *
 * "Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash
 *  by \\. This makes tabs and backspaces visible in an unambiguous way."
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
#include <string.h>





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// __START: main()


int main()
{
 // __NOTICE: Since it may not be trivial to generate an input containing the '\b', we are going to take this exercise
 //           further and split it into 2 parts: FIRST, we are going to generate a test input file with same name than
 //           this file except for the extension, which will be .in; THEN we process this test input file and do what
 //           the exercise asks.


 ///////////////////// __START: PART 1/2: Generate input file...


 char* str_filename_this_ext = strrchr(__FILE__, '.'); // string pointer to last occurrence of '.' -> extension!

 ////////// _END: lvars //////////


 printf("file: |%s|\nEXT: |%s|\n", __FILE__, str_filename_this_ext);
//1-10_copy_input_unambiguous.in

 if (str_filename_this_ext != NULL)
   {
    // 1.1 Allocate memory for new string containing input filename

    // Name of input file to create
    size_t csize = strlen(__FILE__) - strlen(str_filename_this_ext) + 1 + 2 + 1; // filename. + in + '\0'
    //char* str_filename_in = calloc(1, csize);
    char* str_filename_in = malloc(csize);

    // 1.2 - Get pos from pointer arithmetic: don't forget that __FILE__ behaves like "char* " -> points to 1st
    // char/pos 0 of/ this file name!!!
    int int_pos_char_ext = (int)(str_filename_this_ext - __FILE__); // position to copy until extension char
    printf("csize: |%zd|\nint_pos_char_ext: |%d|\nsizeof: |%zd|\n", csize, int_pos_char_ext, strlen(str_filename_in));


    // Copy this filename until extension char + append "in" input extension:
    memcpy( (char*)memcpy(str_filename_in, __FILE__, int_pos_char_ext + 1) + int_pos_char_ext + 1, "in", 2);

    printf("FINAL: |%s| (%zd)\n", str_filename_in, strlen(str_filename_in));
    if (str_filename_in[30] == '\0') printf("\\0 OK\n"); else printf("\\0 not ok: |%c|\n", str_filename_in[30]);

    // strncat(str_filename_in, "in", 2); // printf("%s\n", str_filename_in);


    // Now that we have our self generated input filename -> lets fill it!
    FILE* rfile_handle = fopen(str_filename_in, "w");
    if (rfile_handle == NULL)
      {
       printf("FATAL ERROR: in |%s| -> line: |%d|\n", __FILE__, __LINE__); exit(EXIT_FAILURE);
      }

    char*  str_file_content = "\bThis file has:\n\t\t3 tabs\t, \b\b\b4 backspaces and \\\\3 backslashes!\n\\";
    size_t st_len_file_content = strlen(str_file_content);
    size_t st_n_bytes_written  = fwrite(str_file_content, 1, st_len_file_content, rfile_handle);

    if (st_n_bytes_written != st_len_file_content)
      {
       printf("FATAL ERROR: in |%s| -> line: |%d| @ fwrite()\n", __FILE__, __LINE__); exit(EXIT_FAILURE);
      }

    if ( fclose(rfile_handle) != 0)
      {
       printf("FATAL ERROR: in |%s| -> line: |%d| @ fclose()\n", __FILE__, __LINE__); exit(EXIT_FAILURE);
      }

   }
 else {
       // err...this files does not end in .c? WTF!!!
       printf("FATAL ERROR: could not find char '.' in |%s|\n", __FILE__); exit(EXIT_FAILURE);
      }

 ///////////////////// __END: PART 1/2


/*
 ///////////////////// __START: PART 2/2: Do as exercise tells you on generated input!

 // 0 == NULL -> must ini so that first char to read from input is always different from ini value!

 int int_char_cur = 0;  // input: current  char read
 int int_error_put = 0; // test for error on putchar() call

 // __NOTICE: inside this while, there is a lot of newbie code (ex: non-factorization into function, spaghetti if, ...)
 //           But for learning purposes/sequential thinking -> at this stage, better leave it the more transparent
 //           possible!
 while ((int_char_cur = getchar()) != EOF && int_error_put != EOF)
      {
       // printf("int_char_cur: |%d|\n", int_char_cur);
       if (int_char_cur == '\t')
         {
          int_error_put = putchar('\\');
          if (int_error_put != EOF)
            {
             int_error_put = putchar('t');
            }
         }

       else if (int_char_cur == '\b')
              {
               int_error_put = putchar('\\');
               if (int_error_put != EOF)
                 {
                  int_error_put = putchar('b');
                 }
              }

       else if (int_char_cur == '\\')
              {
               int_error_put = putchar('\\');
               if (int_error_put != EOF)
                 {
                  int_error_put = putchar('\\');
                 }
              }

         else {
               // Regular char -> just copy it!
               int_error_put = putchar(int_char_cur);
              }

      } // _ENDS while ((int_char_cur = getchar()) != EOF && int_error_put != EOF)


 // if an error occurs in writing the last copied char ("most nested if") -> we catch it here!
 if (int_error_put == EOF)
   {
    printf("FATAL ERROR: could not copy full input file -> check for write permissions on output and/or destination\
            full!");
    exit(EXIT_FAILURE);
   }

 ///////////////////// __END: PART 2/2
*/

 return EXIT_SUCCESS;
}
