//
//  linedrawing.h
//  Bresenham Drawing
//
//  Created by Siradanai Sutin on 25/2/2564 BE.
//

#ifndef linedrawing_h
#define linedrawing_h

#include <stdio.h>
#include "line.h"
#include "utility.h"


void performDrawing(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT]);


/// Original Bresenham Drawing algorithm
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawOriginalBresenham(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx);

/// Approve Bresenham Algorithm for handling
/// when slope of line is greater than 1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawGreatGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx);

/// Approve Bresenham Algorithm for handling negative slope
/// when the slope is < 0 but >= -1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawNegativeGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx);

/// Approve Bresenham Algorithm for handling negative slope
/// when slope of line is less than -1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawGreatNegativeGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx);



/// Draw vertical line
/// @param line set of 2 endpoints
void drawVerticalLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT]);

#endif /* linedrawing_h */
