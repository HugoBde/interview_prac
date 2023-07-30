#include <bits/stdc++.h>

using namespace std;

int getArtisticPhotographCount(int N, string C, int X, int Y)
{
    // Number of artistic photos we can take
    long long count = 0;

    // Number of photographers and backdrops to the left
    // and to the right of our "cursor"
    //             P  B
    int left[]  = {0, 0};
    int right[] = {0, 0};

    // Fill 'right' with the first X to Y values before
    // we start iterating
    for (int i = X; i <= Y; i++) {
        char c = C[i];
        if (c == 'P')
            right[0]++;
        else if (c == 'B')
            right[1]++;
    }

    // Start iterating
    for (int i = 0; i < N; i++) {
        char c = C[i];

        // Each time our cursor is on an actor,
        // increment count by the number of combinations
        // of photographers to the left and backdrops to the right
        // and vice-versa
        if (c == 'A') {
            count += left[0] * right[1];
            count += left[1] * right[0];
        }

        // Update 'right'
        if (i + X < N) {
            // This is the cell that is about to leave the valid range on the right
            char c = C[i + X];

            if (c == 'P')
                right[0]--;
            else if (c == 'B')
                right[1]--;

            // We nest this check here because if i + X is out of bounds, then i + Y + 1 will be too
            if (i + Y + 1 < N) {
                // This is the cell that is about to enter the valid range on the right
                char c = C[i + Y + 1];
                if (c == 'P')
                    right[0]++;
                else if (c == 'B')
                    right[1]++;
            }
        }

        // Update 'rigth'
        if (i - X + 1 >= 0) {
            // This is the cell that is about to enter the valid range on the left
            char c = C[i - X + 1];

            if (c == 'P')
                left[0]++;
            else if (c == 'B')
                left[1]++;

            // We nest this check here because if i - X + 1 is out of bounds, then i - Y  will be too
            if (i - Y >= 0) {
                // This is the cell that is about to leave the valid range on the left
                char c = C[i - Y];
                if (c == 'P')
                    left[0]--;
                else if (c == 'B')
                    left[1]--;
            }
        }
    }

    return count;
}

int main()
{
    cout << getArtisticPhotographCount(5, "APABA", 1, 2) << '\n';
    cout << getArtisticPhotographCount(5, "APABA", 2, 3) << '\n';
    cout << getArtisticPhotographCount(8, ".PBAAP.B", 1, 3) << '\n';
    return 0;
}
