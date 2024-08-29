#include <stdio.h>

int find_the_winner(int n, int k) {
    int winner = 0;  // Start with the base case where only one person is present

    // Iteratively calculate the position of the winner
    for (int i = 2; i <= n; i++) {
        winner = (winner + k) % i;
    }

    // Adjust for 1-based indexing
    return winner + 1;
}

int main() {
    int n = 10;  // Number of friends
    int k = 3;  // Step count

    int winner = find_the_winner(n, k);

    printf("The winner is friend number %d\n", winner);

    return 0;
}
