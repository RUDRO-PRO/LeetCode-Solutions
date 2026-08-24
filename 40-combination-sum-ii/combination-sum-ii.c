#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int start, 
               int* current, int currentSize, 
               int*** results, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (target == 0) {
        // Expand results array if capacity is reached
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *results = (int**)realloc(*results, sizeof(int*) * (*capacity));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*capacity));
        }
        
        // Allocate and copy the current combination
        (*results)[*returnSize] = (int*)malloc(sizeof(int) * currentSize);
        for (int i = 0; i < currentSize; i++) {
            (*results)[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        // Early pruning: since candidates is sorted, subsequent elements will also exceed target
        if (candidates[i] > target) {
            break;
        }

        // Skip duplicate numbers at the same recursion level
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // Include candidates[i]
        current[currentSize] = candidates[i];
        
        // Move to the next index (i + 1) because each element can only be used once
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, 
                  current, currentSize + 1, 
                  results, returnSize, returnColumnSizes, capacity);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the candidates array
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    // Initial allocations
    int capacity = 100;
    int** results = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int* current = (int*)malloc(sizeof(int) * candidatesSize);

    // 2. Start backtracking
    backtrack(candidates, candidatesSize, target, 0, current, 0, &results, returnSize, returnColumnSizes, &capacity);

    free(current);
    return results;
}