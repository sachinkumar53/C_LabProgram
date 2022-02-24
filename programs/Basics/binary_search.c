#include <stdio.h>

int main()
{
    int n, a[10], key, low,high,mid,flag = 0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    
    printf("Enter the elements of the array in sorted order.\n");
    
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    
    printf("Enter the key element to be searched\n");
    scanf("%d",&key);
    
    low = 0;
    high = n-1;

    while ( low <= high)
    {
        mid = (low+high)/2;

        if (a[mid] == key)
        {
            flag = 1;
            break;
        }else{
            if (key < a[mid])
            {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
    }
    
    if (flag)
        printf("%d is found at position %d",key,mid+1);
    else 
        printf("Key element is does not exist in the array.\n");
        
    
    return 0;
}
