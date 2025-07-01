#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_solutions(int size, int *set, int *check)
{
    int printed = 0; // Compteur d'éléments effectivement imprimés
    for (int i = 0; i < size; i++)
    {
        if (check[i])
        {
            if (printed > 0)
                printf(" ");
            printf("%d", set[i]);
            printed++;
        }
    }
    if (printed > 0)
        printf("\n");
}

void powerset(int target, int size_set, int *set, int *check, int index, int sum)
{
    if (index == size_set)
    {
        if (sum == target)
            print_solutions(size_set, set, check);
        return ;
    }
    check[index] = 1;
    powerset(target, size_set, set, check, index + 1, sum + set[index]);
    check[index] = 0;
    powerset(target, size_set, set, check, index + 1, sum);

}

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    int n = atoi(av[1]);
    int size_set = ac - 2;
    int *set = malloc(sizeof(int) *size_set);
    for (int i = 0; i < size_set; i++)
    {
        set[i] = atoi(av[i+2]);
    }
    int *check = malloc(sizeof(int) *size_set);
    for (int i = 0; i < size_set; i++)
    {
        check[i] = 0;
    }
    powerset(n, size_set, set, check, 0, 0);
    free(set);
    free(check);
    return (0);
}