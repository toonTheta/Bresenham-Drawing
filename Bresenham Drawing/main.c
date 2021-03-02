//
//  main.c
//  Bresenham Drawing
//
//  Created by Siradanai Sutin on 25/2/2564 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include <errno.h>
#include "line.h"
#include "linedrawing.h"
#include <time.h>



int main(int argc, const char * argv[]) {
    
    char input[256];        // buffer for reading file data
    char filename[128];     // input filename, from user
    FILE * pIn = NULL;      // File pointer for reading
    FILE * pOut = NULL;     // File pointer for writing
    LINE_T * lines;         // dynamic array of structures for lines
    int linesread = 0;      // count good and bad lines
    int i = 0;              // loop counter
    clock_t start, end;
    double cpu_time_used;
    int canvas [WINDOW_WIDTH][WINDOW_HEIGHT] = {0} ; // Canvas
    
    
    if (argc < 2) {
        printf("Please enter input file name on command line\n");
        exit(0);
    }
    
    sscanf(argv[1], "%s", filename);
    printf("%s\n", filename);
    
    int count = countLines(filename);
    if (count == 0)
        printf("File %s seems to be empty\n", filename);
    if (count <= 0)
        exit(1);
    
    printf("File has %d lines\n",count);
    
    lines = calloc(count, sizeof(LINE_T));
    if (lines == NULL) {
        printf("Error allocating array of %d lines records\n", count);
        exit(2);
    }
    
    pIn = fopen(filename, "r");
    
    i = 0;
    start = clock();
    while (fgets(input, sizeof(input), pIn) != NULL) {
        linesread += 1;
        sscanf(input, "%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
        lines[i].x1 -= 1;
        lines[i].y1 -= 1;
        lines[i].x2 -= 1;
        lines[i].y2 -= 1;
        
        performDrawing(lines[i], canvas);
        
        i+=1;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Lines Drawing took %f seconds to execute \n", cpu_time_used);
    pOut = fopen("output.txt", "w");
    
    // Convert to Q1 coordinate otherwise the canvas will be vertical fliped
    for (int y = WINDOW_HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WINDOW_WIDTH; x++) {
            fprintf(pOut, "%d ", canvas[x][y]);
        }
        fprintf(pOut, "\n");
    }
    
    fclose(pIn);
    fclose(pOut);
    free(lines);
    return 0;
    
    
    
}
