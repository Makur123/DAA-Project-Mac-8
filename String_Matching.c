#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pattern, int M, int* lps) {
    int length = 0;  // length of the previous longest prefix suffix
    int i = 1;

    // LPS[0] is always 0
    lps[0] = 0;

    // Compute LPS array
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[M];

    // Preprocess the pattern to create the LPS array
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            // mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[100], pattern[100];

    // Taking input from user
    printf("Enter the text string: ");
    scanf("%s", text);
    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    // Calling KMP Search to find the pattern in the text
    KMPSearch(text, pattern);

    return 0;
}
