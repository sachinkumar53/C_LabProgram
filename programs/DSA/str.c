#include <stdio.h>

int find_match(char str[100], char pat[100], char rep[100], char ans[100]);

void main()
{
    char str[100], pat[100], rep[100], ans[100];
    int flag;

    printf("enter the main string\n");
    gets(str);

    printf("enter the pattern string to be searched\n");
    gets(pat);

    printf("enter the replacement string\n");
    gets(rep);

    flag = find_match(str, pat, rep, ans);

    if (flag)
    {
        printf("\n pattern found\n");
        printf("\n the string after replacement is %s", ans);
    }
    else
    {
        printf("\n pattern not found\n");
    }
}

int find_match(char str[100], char pat[100], char rep[100], char ans[100])
{
    int i, j, m, c, flag, k;
    i = j = m = c = flag = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')
            {
                flag = 1;
                printf("The pattern is found in the position %d", c);
                for (k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
    return flag;
}
