#include <unistd.h> // For write
#include <stdlib.h> // For malloc and free

// Function prototypes
void print_error();
void print_grid(int grid[4][4]);
int parse_input(char *input, int constraints[16]);
int is_valid(int grid[4][4], int constraints[16], int row, int col, int num);
int solve(int grid[4][4], int constraints[16], int row, int col);
int check_visibility(int grid[4][4], int constraints[16]);
int count_visible(int *line, int size);

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        print_error();
        return 1;
    }

    int constraints[16];
    if (!parse_input(argv[1], constraints)) {
        print_error();
        return 1;
    }

    int grid[4][4];
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            grid[i][j] = 0;
            j = j + 1;
        }
        i = i + 1;
    }

    if (!solve(grid, constraints, 0, 0)) {
        print_error();
        return 1;
    }

    print_grid(grid);
    return 0;
}

// Function to print "Error\n"
void print_error() {
    write(1, "Error\n", 6);
}

// Function to print the grid
void print_grid(int grid[4][4]) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            char c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < 3) {
                write(1, " ", 1);
            }
            j = j + 1;
        }
        write(1, "\n", 1);
        i = i + 1;
    }
}

// Function to parse input constraints
int parse_input(char *input, int constraints[16]) {
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        if (input[i] >= '1' && input[i] <= '4') {
            constraints[j] = input[i] - '0';
            j = j + 1;
        } else if (input[i] != ' ') {
            return 0;
        }
        i = i + 1;
    }
    if (j != 16) {
        return 0;
    } else {
        return 1;
    }
}

// Function to check if placing a number is valid
int is_valid(int grid[4][4], int constraints[16], int row, int col, int num) {
    int i = 0;
    while (i < 4) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
        i = i + 1;
    }

    grid[row][col] = num;
    if (col == 3 && !check_visibility(grid, constraints)) {
        grid[row][col] = 0;
        return 0;
    }
    if (row == 3 && !check_visibility(grid, constraints)) {
        grid[row][col] = 0;
        return 0;
    }

    grid[row][col] = 0;
    return 1;
}

// Function to count visible boxes from a given direction
int count_visible(int *line, int size) {
    int count = 0;
    int max_height = 0;
    int i = 0;
    while (i < size) {
        if (line[i] > max_height) {
            max_height = line[i];
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

// Function to check visibility constraints
int check_visibility(int grid[4][4], int constraints[16]) {
    int i = 0;
    int line[4];

    while (i < 4) {
        int j = 0;
        while (j < 4) {
            line[j] = grid[j][i];
            j = j + 1;
        }
        if (constraints[i] != count_visible(line, 4)) {
            return 0;
        }
        i = i + 1;
    }

    i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            line[j] = grid[3 - j][i];
            j = j + 1;
        }
        if (constraints[4 + i] != count_visible(line, 4)) {
            return 0;
        }
        i = i + 1;
    }

    i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            line[j] = grid[i][j];
            j = j + 1;
        }
        if (constraints[8 + i] != count_visible(line, 4)) {
            return 0;
        }
        i = i + 1;
    }

    i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            line[j] = grid[i][3 - j];
            j = j + 1;
        }
        if (constraints[12 + i] != count_visible(line, 4)) {
            return 0;
        }
        i = i + 1;
    }

    return 1;
}

// Backtracking solver function
int solve(int grid[4][4], int constraints[16], int row, int col) {
    if (row == 4) {
        return 1;
    }

    int next_row;
    int next_col;
    if (col == 3) {
        next_row = row + 1;
        next_col = 0;
    } else {
        next_row = row;
        next_col = col + 1;
    }

    int num = 1;
    while (num <= 4) {
        if (is_valid(grid, constraints, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, constraints, next_row, next_col)) {
                return 1;
            }
            grid[row][col] = 0;
        }
        num = num + 1;
    }
    return 0;
}

