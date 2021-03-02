//
//  linedrawing.c
//  Bresenham Drawing
//
//  Created by Siradanai Sutin on 25/2/2564 BE.
//

#include "linedrawing.h"


void performDrawing(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT]) {
    
    if (line.x1 == line.x2) {
        drawVerticalLine(line, canvas);
        return;
    }
    
    if (line.x1 > line.x2) {
        swap(&line.x1, &line.x2);
        swap(&line.y1, &line.y2);
    }
    
    int dy = line.y2 - line.y1;
    int dx = line.x2 - line.x1;
    
    if (dy > dx && dy >= 0) { // Slope Grater Than 1
        drawGreatGradientLine(line, canvas, dy, dx);
        return;
    }
    
    if (dy <= dx && dy >= 0) { // Bresenham's Original Case
        drawOriginalBresenham(line, canvas, dy, dx);
        return;
    }
    
    if (-dy <= dx) { // Negative Gradient
        drawNegativeGradientLine(line, canvas, dy, dx);
        return;
    }
    
    if (-dy > dx) { // Great Negative Gradient
        drawGreatNegativeGradientLine(line, canvas, dy, dx);
        return;
    }
    
}


/// Original Bresenham Drawing algorithm
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawOriginalBresenham(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx) {
    
    int currentY = line.y1;
    int p = 2 * dy - dx;
    
    for(int x = line.x1; x <= line.x2; x++) {
        canvas[x][currentY] = 1;
        
        if (p >= 0) {
            currentY += 1;
            p = p + (2 * dy) - (2 * dx);
        } else {
            p = p + (2 * dy);
        }

    }
}

/// Improve Bresenham Algorithm for handling
/// when slope of line is greater than 1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawGreatGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx) {
    int currentX = line.x1;
    int p = 2 * dx - dy;
    
    for (int y = line.y1; y <= line.y2; y++) {

        canvas[currentX][y] = 1;
        if (p >= 0) {
            currentX += 1;
            p = p + (2 * dx) - (2 * dy);
        } else {
            p = p + (2 * dx);
        }
    }
}

/// Improve Bresenham Algorithm for handling negative slope
/// when the slope is < 0 but >= -1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawNegativeGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx) {
    
    int currentY = line.y1;
    int p = -2 * dy - dx;
    
    for (int x = line.x1; x <= line.x2; x++) {
        
        canvas[x][currentY] = 1;
        
        if(p >= 0) {
            currentY -= 1;
            p = p - (2 * dy) - (2 * dx);
        } else {
            p = p - (2 * dy);
        }
    }
}

/// Improve Bresenham Algorithm for handling negative slope
/// when slope of line is less than -1
/// @param line 2 endpoints
/// @param dy differece of points in vertical direction
/// @param dx differece of points in horizontal direction
void drawGreatNegativeGradientLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT], int dy, int dx) {
    int currentX = line.x1;
    int p = -2 * dx - dy;
    
    for (int y = line.y1; y>= line.y2; y--) {
        canvas[currentX][y] = 1;
        
        if (p > 0) {
            p = p -(2 * dx);
        } else {
            currentX += 1;
            p = p - (2 * dx) - (2 * dy);
        }
        
    }
}



/// Draw vertical line
/// @param line set of 2 endpoints
void drawVerticalLine(LINE_T line, int canvas[WINDOW_WIDTH][WINDOW_HEIGHT]) {
    if (line.y1 < line.y2) {
        for (int y = line.y1; y <= line.y2; y++) {
            canvas[line.x1][y] = 1;
        }
    } else {
        for (int y = line.y2; y <= line.y1; y++) {
            canvas[line.x1][y] = 1;
        }
    }
    
}
