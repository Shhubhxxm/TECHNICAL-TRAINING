#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int boxes;
    int port;
} Box;

int minTrips(Box* boxes, int boxesSize, int portsCount, int maxBoxes, int maxWeight) {
    int totalWeight = 0, totalBoxes = 0, trips = 0;
    int portVisited = 0, lastPort = 0;
    int start = 0, lastTrip = 0;

    for (int end = 0; end < boxesSize; end++) {
        totalWeight += boxes[end].boxes;
        totalBoxes++;

        // Start a new trip if necessary
        if (totalBoxes > maxBoxes || totalWeight > maxWeight || (end > 0 && boxes[end].port != boxes[end - 1].port)) {
            trips++;
            start = end;
            totalWeight = boxes[end].boxes;
            totalBoxes = 1;
            lastPort = boxes[end - 1].port;
            lastTrip = end;
        }

        // Reduce trip count if the last trip ends at the same port
        if (end < boxesSize - 1 && boxes[end].port == boxes[end + 1].port) {
            trips--;
        }
    }

    // Count the final trip
    trips++;

    return trips;
}

int main() {
    Box boxes[] = {{1, 1}, {2, 1}, {1, 2}, {2, 2}, {3, 3}};
    int boxesSize = sizeof(boxes) / sizeof(boxes[0]);
    int portsCount = 3;
    int maxBoxes = 5;
    int maxWeight = 6;

    int result = minTrips(boxes, boxesSize, portsCount, maxBoxes, maxWeight);
    printf("Minimum number of trips: %d\n", result);

    return 0;
}
