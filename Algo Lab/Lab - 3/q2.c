#include <stdio.h>
#include <string.h>
int main() {
    int textlen, patternl, flag = 0, count = 0;
    printf("Enter the Text: \n");
    char text[100];
    scanf("%s", text);
    printf("Enter the Pattern: \n");
    char pattern[100];
    scanf("%s", pattern);
    textlen = strlen(text);
    patternl = strlen(pattern);
    for (int i = 0; i <= textlen - patternl; i++) {
        int j = 0;
        while (j < patternl && pattern[j] == text[j + i]) {
            count++;
            j++;
        }
        if (j == patternl) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Pattern Found at Position: %d \n", i);
    else
        printf("Pattern not Found! \n");

    printf("Count is: %d\n", count);
    return 0;
}
