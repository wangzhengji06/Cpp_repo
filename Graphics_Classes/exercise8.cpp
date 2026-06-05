#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <cmath>

constexpr double pi = 3.1415;

struct Regular_polygon : Polygon {
  Regular_polygon(Point center, int n, int radius);
};

Regular_polygon::Regular_polygon(Point center, int n, int radius) {
  for (int i = 0; i < n; ++i) {
    int x = center.x + radius * cos(2 * pi * i / n);
    int y = center.y + radius * sin(2 * pi * i / n);
    add(Point{x, y});
  }
}
