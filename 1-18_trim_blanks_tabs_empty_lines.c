/* Exercise 1-18
Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
*/



#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */





/* getline: read a line into s, return length */
int Getline(char s[], int lim)
{
 int i, c = -1;

 for (i = 0; i < lim - 1 && (c = getchar( )) != EOF && c != '\n'; ++i)
    {
     s[i] = (char)c;
     // printf("s[%d]: |%c|\n", i, c);
    }

 if (c == '\n')
   {
    s[i] = (char)c; //casting
    // printf("s[%d]: |%c|\n", i, c);
    ++i;

   }

 s[i] = '\0';


 return i;
}



/* copy: copy 'from' into 'to'; assume to is big enough */
void Copy(char to[], char from[])
{
 int i;

 i = 0;
 while ((to[i] = from[i]) != '\0')
       ++i;
}






int main( )
{
 int len;               /* current line length */
 int cur;               /* cursor over line */
 char line[MAXLINE];    /* current input line */



 while ((len = Getline(line, MAXLINE)) > 0) // if there is a line (min. 1 char)
      {

       if (line[0] != '\n')
         {
          cur = len - 2; // printf("cur: |%d|\n", cur);
          while ( cur >= 0 && (line[cur] == ' ' || line [cur] == '\t') )
                cur--;

          if (cur >= 0)
            {
             line[cur+1] = '\n';
             line[cur+2] = '\0';

             printf("%s", line);
            }

          //printf("#%d\n%s", len, line);
         }

       // printf("[%d] %s", len, line);
      }

 return 0;
}
