#include <stdio.h>
#define SIZE 20

int main(void)
{
    char string1[SIZE];
    char string2[] = "string literal";

    printf("%s", "Enter a string:   (NB - The String are less 19 chars): \n");
    scanf("%19s", string1);

    printf("String1 is: %s\n", string1);
    printf("String2 is: %s\n", string2);

    printf("String1 with spaces between characters is:\n");

    for(size_t i = 0; i <SIZE && string1[i] != '\0'; ++i)
    {
        printf("%c ", string1[i]);
        
    }
    puts("");

    
    


}