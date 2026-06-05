#include "PPP/Graph.h"
#include "PPP/Point.h"
#include "PPP/Simple_window.h"

Point nw(const Rectangle &rec) { return rec.point(0); }

Point se(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width(), p.y + rec.height()};
}

Point ne(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width(), p.y};
}

Point sw(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x, p.y + rec.height()};
}

Point center(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width() / 2, p.y + rec.height() / 2};
}

Point n(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width() / 2, p.y};
}

Point s(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width() / 2, p.y + rec.height()};
}

Point e(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x + rec.width(), p.y + rec.height() / 2};
}

Point w(const Rectangle &rec) {
  Point p = rec.point(0);
  return Point{p.x, p.y + rec.height() / 2};
}

int main() {}
