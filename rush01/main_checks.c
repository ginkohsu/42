/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:32:38 by jinxu             #+#    #+#             */
/*   Updated: 2025/01/26 19:42:14 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>


int check_constraints(int grid[4][4], int visualcount[16]);
int check_numvalid(int grid[4][4], int row, int col, int num);
void print_grid(int grid[4][4]);
int	solve(int grid[4][4], int visualcount[16], int row, int col);

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int visualcount[16];
	int grid[4][4];

// Initialize the array using nested loops
	
	i = 0;
	while (i < 4)
	{
    	j = 0;
    	while (j < 4)
    	{
        	grid[i][j] = 0;
        	j++;
   		 }
	    i++;
	}
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}


//check whether there are only 31 chars in the string	
	k = 0;
	while (argv[1][k] != '\0')
		k++;
	if (k != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
//check whether the inbetween chars of the input string are spaces
	j = 0;
	while( j < 15)
	{
		if (argv[1][1 + (j * 2)] != ' ')
		{
			write (1, "Error\n", 6);
			return (0);
		}
		j++;
	}
//these bottom parts can be one subfunction, the top ones can be two subfunctions.
//check the input is  only  `1' to '4'; derive the array of integers called visualcount from the input string
	i = 0;
	j = 0;	
	while (argv[1][j] != '\0')
	{
		if (argv[1][j] >= '1' && argv[1][j] <= '4')
			{
				visualcount[i] = argv[1][j] - '0';
				i ++;
			}
		j++;
	}
//check whether it is 16 numbers
	if (i != 16)
	{
		write(1, "Error\n", 6);
		return (0);
	}
//the realdeal/////////////////////////////////////////////////////////////////////////////////////////////


	if(!solve(grid,visualcount, 0, 0))
	{
		write(1, "Error\n", 6);
		return 0;
	}
	print_grid(grid);
	return 0;
}


//top -down visualcount[col] check
int check_topdown(int grid[4][4], int visualcount[16])
{
	int max_height;
	int col;
	int row;          
	int v_countnow;

	col = 0;
	while(col < 4) 
	{
		max_height = 0;
		v_countnow = 0;
		row = 0;
		while (row < 4)
		{
			if (grid[row][col] > max_height)
			{
				max_height = grid [row][col];
				v_countnow++;
			}
			row++;
		}
		if (v_countnow != visualcount[col])
			return 0;
		col ++;
	}
	return 1;
	}

int check_botup(int grid[4][4], int visualcount[16])
{
    int max_height;
    int col;
    int row;
    int v_countnow;

    col = 0;
    while(col < 4)
    {
        max_height = 0;
        v_countnow = 0;
        row = 3;
        while (row >= 0)
        {
            if (grid[row][col] > max_height)
            {
                max_height = grid [row][col];
                v_countnow++;
            }
            row--;
        }
        if (v_countnow != visualcount[col + 4])
            return 0;
        col ++;
    }
    return 1;
    }
int check_leftright(int grid[4][4], int visualcount[16])
{
    int max_height;
    int col;
    int row;       
    int v_countnow;

    row = 0;
    while(row < 4)
    {
        max_height = 0;
        v_countnow = 0;
        col = 0;
        while (col < 4)
        {
            if (grid[row][col] > max_height)
            {
                max_height = grid [row][col];
                v_countnow++;
            }
            col++;
        }
        if (v_countnow != visualcount[row + 8])
            return 0;
        row ++;
    }
    return 1;
    }


int check_rightleft(int grid[4][4], int visualcount[16])
{
    int max_height;
    int col;
    int row;
    int v_countnow;

    row = 0;
    while(row < 4)
    {
        max_height = 0;
        v_countnow = 0;
        col = 3;
        while (col >= 0)
        {
            if (grid[row][col] > max_height)
            {   
                max_height = grid [row][col];
                v_countnow++;
            }   
            col--;
        }   
        if (v_countnow != visualcount[row + 12]) 
            return 0;
        row ++; 
    }   
    return 1;
    }

int check_constraints(int grid[4][4], int visualcount[16])
{
	if(check_topdown(grid, visualcount)  && 
	check_botup(grid, visualcount) && 
	check_leftright(grid, visualcount) && 
	check_rightleft(grid, visualcount))
	{
		return (1);
	}
	return (0);
}

int check_numvalid(int grid[4][4], int row, int col, int num)
{
	int	i;

//repeating number check, before we pass in a number in the box:
//in the same row or col is there already a repeating number?
	i = 0;
	while ( i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void print_grid(int grid[4][4])
{
	char	num;
	int	i;
	int j;
	
	i = 0;
	while (i < 4)
	{	
		j = 0;
		while (j < 4)
		{
			num = grid[i][j] + '0';
			write(1, &num, 1);
			if (j < 3)
				write (1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	solve(int grid[4][4], int visualcount[16], int row, int col)
{
	int next_row;
	int next_col;

	//base case:the grid is full.
	if (row == 4)
		return check_constraints(grid, visualcount);//check all constraits meet.

	//calculate the next box indexes	
	if (col == 3)
	{
		next_row = row + 1;//when we have gone thru all four rows and reached the [3][3] box, the last output of next_row: 4, lead us to base case.
		next_col = 0;
	}
	else
	{
		next_row = row;
		next_col = col + 1;// we start with [0][0],the next box will be [0][1], so loop thru each row first and when col == 3 go to the next row, from index[0][next_row].
	}
	
	//fill in numbers 1 to 4 in each box, starting from [0][0] which is the left-top point.
	int num = 1;
	while (num  <= 4)
	{
		if (check_numvalid(grid, row, col, num)) //check is the num valid(repeating)

		{
			grid[row][col] = num;//place the number temporarily
			if (solve(grid, visualcount, next_row, next_col)) //recursion to fill next box, then next box... until reach base case(filling full grid).
				return (1);//found the correct matrix, stop
			grid[row][col] = 0;//if fail to find, backtrack: remove the number
		}
		num++;
	}
	return 0;
}


