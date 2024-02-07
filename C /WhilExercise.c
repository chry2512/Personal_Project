#include <stdio.h>

int main()
{

    unsigned int count = 0;
    int num = 2147483648;           // warning LONG_MAX (2147483647) is too large for this compiler (32 bits)
    unsigned int num2 = 4294967295; // limit of unsigned int (32 bits) is 4294967295

    while (count < 10) // iterazione definita da contatore
    {
        printf("<<<<<<<<The Result is %d\n", num++);
        printf("<<<<<<<<The Result is %u\n", num2++);
        count++;
    }

    return 0;
}
