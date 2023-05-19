#include <stdio.h>
#include <string.h>


void matches_rule(char *word, char *rule) {
    int word_len = strlen(word);
    int rule_len = strlen(rule);
    
    if (word_len < rule_len) {
        return 0;
    }
    
    for (int i = 0, j = 0; i < word_len && j < rule_len; i++, j++) {
        if (rule[j] == '*') {
            j++;
            if (j == rule_len) {
                return 1; 
            }
            while (i < word_len && word[i] != rule[j]) {
                i++;
            }
            if (i == word_len) {
                return 0;
            }
        } else if (rule[j] == '?') {
            continue; 
        } else if (word[i] != rule[j]) {
            return 0;
        }
    }
    
    return 1;
}

char *filter_text(char *s, char *rule) {
    int len = strlen(s);
    char result[len+1];
    int j = 0;
    
    for (int i = 0; i < len; ) {
        int start = i;
        while (s[i] != ' ' && i < len) {
            i++;
        }
        int end = i;
        if (matches_rule(s+start, rule)) {

        } else {
            if (j > 0) {
                result[j++] = ' '; 
            }
            for (int k = start; k < end; k++) {
                result[j++] = s[k]; 
            }
        }
        if (s[i] == ' ') {
            i++; 
        }
    }
    
    result[j] = '\0';
    return strdup(result); 
}

int main() {
    char s[1000], rule[100];
    printf("Enter a string: ");
    fgets(s, 1000, stdin);

    printf("Enter a rule: ");
    scanf("%s", rule);
    
    char *filtered = filter_text(s, rule);
    printf("Filtered text: %s\n", filtered);
    }

