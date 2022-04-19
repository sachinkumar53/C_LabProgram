#include <stdio.h>
#include <stdlib.h>

char str[100], ptr[100],rep[100], ans[100], *s,*e;
int i, j = 0, k = 0;

int main()
{
    printf("Enter main string\n");
    gets(str);

    printf("Enter pattern\n");
    gets(ptr);
    
    printf("Enter replacement\n");
    gets(rep);

    s = e = str;
    while (*s != '\0')
    {
        if (*e == ptr[j])
        {
            e++;
            j++;

            if (ptr[j] == '\0')
            {
                printf("Match found\n");

                for (i = 0; rep[i] != '\0'; i++,k++)
                    ans[k] = rep[i];

                j = 0;
                s = e;
            }
        }
        else
        {
            ans[k] = *s;
            k++;
            s++;
            e=s;
            j = 0;
        }
    }

    ans[k] = '\0';

    for (i = 0; ans[i] != '\0'; i++)
    {
        printf("%c",ans[i]);
    }

    printf("\n");
    
}