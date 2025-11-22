#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char s[1001];
        scanf("%s", s);
        
        int count = 0;
        int open = 0;
        
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '<') {
                open++;
            } else if (s[i] == '>' && open > 0) {
                count++;
                open--;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}