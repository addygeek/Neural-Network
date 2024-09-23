#include <iostream>
#include <vector>
using namespace std;

// Function to plot the points in all eight octants
void plotCirclePoints(int x_center, int y_center, int x, int y, vector<pair<int, int>>& points) {
    points.push_back({x_center + x, y_center + y});
    points.push_back({x_center - x, y_center + y});
    points.push_back({x_center + x, y_center - y});
    points.push_back({x_center - x, y_center - y});
    points.push_back({x_center + y, y_center + x});
    points.push_back({x_center - y, y_center + x});
    points.push_back({x_center + y, y_center - x});
    points.push_back({x_center - y, y_center - x});
}

// Midpoint Circle Drawing Algorithm
void midpointCircle(int x_center, int y_center, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;  // Initial decision parameter

    // Store points of the circle
    vector<pair<int, int>> circlePoints;
    plotCirclePoints(x_center, y_center, x, y, circlePoints);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;  // Choose the right pixel
        } else {
            y--;
            p += 2 * (x - y) + 1;  // Choose the diagonal pixel
        }
        plotCirclePoints(x_center, y_center, x, y, circlePoints);
    }

    // Plot the points as an ASCII representation of the circle
    for (int i = 0; i < circlePoints.size(); i++) {
        int px = circlePoints[i].first;
        int py = circlePoints[i].second;
        cout << "(" << px << ", " << py << ")\n";
    }
}

int main() {
    int x_center = 0;
    int y_center = 0;
    int radius = 10;
    
    cout << "Midpoint Circle Algorithm (ASCII Representation)\n";
    midpointCircle(x_center, y_center, radius);
    
    return 0;
}
