#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_safe(int row, int col, int *table)
{
    for (int i= 0; i < col; i++)
    {
        if (table[i] == row)
            return (0);
        if (table[i] - row == col - i)
            return (0);
        if (table[i] - row == i - col)
            return (0);
    }
    return (1);
}
void queens(int n, int *table, int col)
{
    if (col == n)
    {
        for (int i = 0; i < n;i++)
        {
            char c = table[i] + '0';
            printf("%c", c);
            if (i < n -1)
                printf(" ");
        }
        printf("\n");
        return ;
    }
    for (int row = 0; row < n; row++)
    {
        if (is_safe(row, col, table) == 1)
        {
            table[col] = row;
            queens(n, table, col + 1);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int n = atoi(av[1]);
    if (n <=0)
        return (1);
    int *table = malloc(sizeof(int) *n);
    queens(n, table, 0);
    free(table);
    return (0);
}