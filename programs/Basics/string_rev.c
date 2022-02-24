#include <stdio.h>
#include<string.h>

int main()
{
    char s[10],rev[10];
    int i,len = 0;
    printf("Enter a string\n");
    scanf("%s",s);

    len = strlen(s);
    
    for (i = 0; i < len; i++)
    {
        rev[i] = s[(len-i-1)];
    }
    
    rev[len] = '\0';
    
    printf("Reverse string is: %s",rev);

    return 0;
}
