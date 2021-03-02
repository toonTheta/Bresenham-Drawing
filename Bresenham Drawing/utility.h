//
//  utility.h
//  Bresenham Drawing
//
//  Created by Siradanai Sutin on 25/2/2564 BE.
//

#ifndef utility_h
#define utility_h

#include <stdio.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

/* Open input file and read through to count the number of lines
 * then close.
 *    filename    file to read
 * Returns number of lines read, or -1 if file could not be opened.
 */
int countLines(char filename[]);

void swap(int *a, int *b);

#endif /* utility_h */
