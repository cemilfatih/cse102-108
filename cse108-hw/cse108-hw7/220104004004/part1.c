#include <stdio.h>
#include <string.h>
#include <ctype.h>

int minOps(char* s) {
    int freq[26] = {-1};  
    int len = strlen(s);


    for (int i = 0; i < len; i++) {
        if (islower(s[i])) {  
            freq[s[i] - 'a']++;
        }
    }

    int ops = 0;


    for (int i = 0; i < 26; i++) {
        if (freq[i] < 0) continue;  

        for (int j = i + 1; j < 26; j++) {
            if (freq[j] < 0) continue; 

            while (freq[i] > 0 && freq[j] > 0) {
                freq[i]--;
                freq[j]--;
                ops++;
            }
        }
    }

    return ops;
}

int main() {
    char s[100];
    printf("Enter a string of lowercase letters: ");
    scanf("%s", s);

    int ops = minOps(s);
    printf("Minimum number of operations required: %d\n", ops);

    return 0;
}

