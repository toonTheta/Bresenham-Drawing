//
//  utility.c
//  Bresenham Drawing
//
//  Created by Siradanai Sutin on 25/2/2564 BE.
//

#include "utility.h"
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* Open input file and read through to count the number of lines
 * then close.
 *    filename    file to read
 * Returns number of lines read, or -1 if file could not be opened.
 */
int countLines(char filename[])
{
    FILE* pIn = NULL;          /* file pointer for reading */
    int lineCount = 0;         /* return value */
    char input[256];           /* hold data read from file */
    pIn = fopen(filename,"r");
    if (pIn == NULL)   /*  can't open file */
       {
       printf("Error - failed to open file %s\n", filename);
       fprintf( stderr, "Errno %d, Error %s, opening text.txt for reading.\n", errno, strerror(errno));
       lineCount = -1;
       }
    else
       {
       while (fgets(input,sizeof(input),pIn) != NULL)
     lineCount++;
       fclose(pIn);  /* close only if we were successful opening! */
       }
    return lineCount;
}

/* check if passed string is all alphabetic.
 *    string      string to check
 * Return 1 if valid, 0 if non alpha characters found.
 * Also prints error message
 */
int checkAlpha(char string[])
{
    int i = 0;
    int valid = 1;
    /* loop until the end of the string or until an error is found */
    for (i = 0; (i < strlen(string)) && (valid); i++)
       {
       if (!isalpha(string[i]))
      valid = 0;
       }
    if (!valid)
       {
       printf("Error: string '%s' should be all alphabetic\n",string);
       }
    return valid;
}

/* check if passed string is all alphabetic or numeric
 *    string      string to check
 * Return 1 if valid, 0 if non alpha characters found.
 * Also prints error message
 */
int checkAlphaNum(char string[])
{
    int i = 0;
    int valid = 1;
    /* loop until the end of the string or until an error is found */
    for (i = 0; (i < strlen(string)) && (valid); i++)
       {
       if (!isalnum(string[i]))
      valid = 0;
       }
    if (!valid)
       {
       printf("Error: string '%s' should be all alphabetic or digits\n",string);
       }
    return valid;
}

/* check if passed string is all numeric
 *    string      string to check
 * Return 1 if valid, 0 if non alpha characters found.
 * Also prints error message
 */
int checkDigits(char string[])
{
    int i = 0;
    int valid = 1;
    /* loop until the end of the string or until an error is found */
    for (i = 0; (i < strlen(string)) && (valid); i++)
       {
       if (!isdigit(string[i]))
      valid = 0;
       }
    if (!valid)
       {
       printf("Error: string '%s' should be all digits\n",string);
       }
    return valid;
}


/// Perform validation on a line read from the file.
/// 1) must have at least 4 fields
/// 2) first must be alpha only
/// 3) second must be alphanumeric
/// 4) third must be positive integer
/// @param inputline line to validate
int validLine(char inputline[])
{
#define MAXCHARS 31  /* leave room for term */
    int valid = 1;
    char fieldvalues[3][64] = {0};/* temporary strings for fields */
    int fieldcount = 0;           /* count the fields */
    int i = 0;                    /* index into line string */
    int j = 0;                    /* index into field value */
    while (i < strlen(inputline))
       {
       j = 0;
       if (isspace(inputline[i]))
       {
       i++;  /* skip white space including at the beginning */
           }
       else
       {
       fieldcount++;
           if (fieldcount > 3)
           break;
           /* copy chars into the next value field */
       while ((!isspace(inputline[i])) && (j <= MAXCHARS))
          {
          fieldvalues[fieldcount-1][j] = inputline[i];
              i++;
              j++;
              }
           }
       }
    if (fieldcount != 3)
       {
       printf("Line has wrong number of fields: %s", inputline);
       valid = 0;
       }
    else
       {
       valid = checkAlpha(fieldvalues[0]);
       if (valid) /* if no error on the name field */
       valid = checkAlphaNum(fieldvalues[1]);
       if (valid)
       valid = checkDigits(fieldvalues[2]);
       }
    
    return valid;
}

void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}
