#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n == 1)
        return (1);
    return (n * factorial(n -1));
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

void swap_char(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_string(char **s1, char **s2)
{
    char *temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void bubble_sort(char *s, int len)
{
    for (int i = 0; i < len -1; i++)
    {
        for (int j = 0;j < len -1;j++)
        {
            if (s[j] > s[j+1])
                swap_char(&s[j], &s[j+1]);
        }
    }
}

void permutation(char *s, int len, char **table, int index, int *index_table)
{
    if (index == len)
    {
        for (int i = 0; i < len;i++)
        {
            table[*index_table][i] = s[i];
        }
        table[*index_table][len] = '\0';
        (*index_table)++;
        return ;
    }
    for (int i = 0; i <= index; i++)
    {
        swap_char(&s[i], &s[index]);
        permutation(s, len, table, index + 1, index_table);
        swap_char(&s[i], &s[index]);
    }
}

int need_to_swap(char *s1, char *s2, int len)
{
    int i = 0;
    while (i < len)
    {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (0);
        i++;
    }
    return (0);
}
void order_print_table(char **table, int sol, int len)
{
    for (int i = 0; i < sol - 1; i++)
    {
        for (int j = 0; j < sol - 1; j++)
        {
            if (need_to_swap(table[j], table[j+1], len) == 1)
                swap_string(&table[j], &table[j+1]);
        }
    }
    for (int i = 0; i < sol; i++)
    {
        printf("%s\n", table[i]);
    }
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (1);
    int len = ft_strlen(av[1]);
    char *s = malloc(sizeof(char) * (len +1));
    for (int i = 0;i < len; i++)
    {
        s[i] = av[1][i];
    }
    s[len] = '\0';
    bubble_sort(s, len);
    int sol = factorial(len);
    char **table = malloc(sizeof(char *) * (sol + 1));;
    for (int i = 0; i < sol; i++)
    {
        table[i] = malloc(sizeof(char) * (len +1));
    }
    table[sol] = "\0";
    int index = 0;
    permutation(s, len, table, 0, &index);
    order_print_table(table, sol, len);
    for (int i = 0; i < sol; i++)
    {
        free(table[i]);
    }
    free(table);
    free(s);
    return (0);
}