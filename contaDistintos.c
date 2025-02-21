#include <stdio.h>

void main()
{
    int a, aux = 0;
    scanf("%d", &a);

    for (int i = 0; i < a; i++)
    {
        int b;
        scanf("%d", &b);
        
        if (b != aux)
        {
            aux = b;
        }
        printf("%d", b);
    }
    
}