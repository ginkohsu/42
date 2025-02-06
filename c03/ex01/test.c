int solve_matrix(int grid[4][4], int visualcount[16], int row, int col) {
    // Base Case: If we are past the last row, the grid is fully filled
    if (row == 4)
        return check_constraints(grid, visualcount); // Validate solution

    // Calculate the next cell's coordinates
    int next_row = (col == 3) ? row + 1 : row; // Move to the next row if at the last column
    int next_col = (col + 1) % 4;             // Wrap around to the first column

    // Try placing numbers 1 to 4 in the current cell
    for (int num = 1; num <= 4; num++) {
        if (is_valid(grid, row, col, num)) { // Check if placement is valid
            grid[row][col] = num;            // Place the number in the grid
            if (solve_matrix(grid, visualcount, next_row, next_col)) // Recurse to the next cell
                return 1; // If the solution works, return success
            grid[row][col] = 0; // Backtrack: Remove the number and try the next one
        }
    }

    // If no number works in this cell, return failure
    return 0;
}

