#include <stdio.h>
#include <stdlib.h>

// Helper to compute largest rectangle in a histogram using a monotonic stack
int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        // Use 0 as a sentinel value at index n to flush remaining bars from the stack
        int currentHeight = (i == n) ? 0 : heights[i];

        while (top >= 0 && currentHeight < heights[stack[top]]) {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            int area = h * width;
            if (area > maxArea) {
                maxArea = area;
            }
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int));
    int maxOverallArea = 0;

    for (int r = 0; r < rows; r++) {
        // Update histogram heights for the current row
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] == '1') {
                heights[c] += 1;
            } else {
                heights[c] = 0;
            }
        }

        // Calculate maximal rectangle with row 'r' as base
        int currentMax = largestRectangleArea(heights, cols);
        if (currentMax > maxOverallArea) {
            maxOverallArea = currentMax;
        }
    }

    free(heights);
    return maxOverallArea;
}