#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);

}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int is_safe(char *s, int len)
{
    int right = 0;
    int left = 0;
    for (int i= 0; i < len; i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')' && left > 0)
            left--;
        else if (s[i] ==')')
            right++;
    }
    if (left == 0 && right == 0)
        return (1);
    return (0);
}
void rip(int len, int cost_max, char *s, int index, int cost)
{
    if (index == len)
    {
        if (cost == cost_max && is_safe(s, len) == 1)
        {
            ft_putstr(s);
        }
        return ;
    }
    rip(len, cost_max, s, index + 1, cost);
    char c = s[index];
    s[index] = ' ';
    rip(len, cost_max, s, index + 1, cost + 1);
    s[index] = c;

}

int calculate_cost(char *s, int len)
{
    int right =0;
    int left = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')' && left > 0)
            left--;
        else if (s[i] ==')')
            right++;
    }
    return (left + right);
}
int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    int len = ft_strlen(av[1]);
    char *s = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        s[i] = av[1][i];
    }
    s[len] = '\0';
    int cost = calculate_cost(s, len); 
    rip(len, cost, s, 0, 0);
    free(s);
    return (0);
}