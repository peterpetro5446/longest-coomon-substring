#include <stdio.h>
#include <string.h>

#define LEN 10000
#define MAX(a,b) (((a)<(b)) ? (b) : (a))

int main() {
    char seq1[LEN+1];
    char seq2[LEN+1];

    // Read two input sequences (strings) from the user
    scanf("%s", seq1);
    scanf("%s", seq2);

    int max_length = 0;  // Stores the length of the longest common substring
    int start1 = 0;      // Starting index in seq1
    int start2 = 0;      // Starting index in seq2

    // Try every pair of starting positions in seq1 and seq2
    for (int st1 = 0; seq1[st1]; st1++) {
        for (int st2 = 0; seq2[st2]; st2++) {
            int pos = 0;

            // Count how long the match continues from these positions
            while (seq1[st1 + pos] && seq2[st2 + pos] && seq1[st1 + pos] == seq2[st2 + pos]) {
                pos++;
            }

            // Update max length and starting positions if this match is longer
            if (pos > max_length) {
                max_length = pos;
                start1 = st1;
                start2 = st2;
            }
        }
    }

    // If a match was found, print it
    if (max_length > 0) {
        char longest_substring[LEN + 1];
        strncpy(longest_substring, &seq1[start1], max_length);
        longest_substring[max_length] = '\0';
        printf("\n\nLongest contiguous common subsequence: [%s]\n", longest_substring);
    }

    return 0;
}
