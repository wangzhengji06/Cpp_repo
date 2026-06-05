#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <cmath>
#include <vector>

constexpr double pi = 3.14159265358979323846;

struct Arrow : Shape {
  Arrow(Point start, Point end);

private:
  void draw_specifics(Painter &painter) const override;
  std::vector<Point> calculate_arrow_points() const;
};

Arrow::Arrow(Point start, Point end) : Shape{start, end} {}

std::vector<Point> Arrow::calculate_arrow_points() const {
  std::vector<Point> arrows;
  Point start = point(0);
  Point end = point(1);

  double dx = end.x - start.x;
  double dy = end.y - start.y;

  double len = std::sqrt(dx * dx + dy * dy);
  if (len == 0)
    return {};
  double ux = dx / len;
  double uy = dy / len;

  double bx = -ux;
  double by = -uy;
  double theta = 15.0 * pi / 180.0;

  double lx = bx * cos(theta) - by * sin(theta);
  double ly = bx * sin(theta) + by * cos(theta);
  double rx = bx * cos(-theta) - by * sin(-theta);
  double ry = bx * sin(-theta) + by * cos(-theta);

  double head_len = len * 0.1;

  Point left{end.x + int(lx * head_len), end.y + int(ly * head_len)};

  Point right{end.x + int(rx * head_len), end.y + int(ry * head_len)};

  arrows.push_back(left);
  arrows.push_back(right);
  return arrows;
}

void Arrow::draw_specifics(Painter &painter) const {
  if (!color().visibility())
    return;
  std::vector<Point> arrows = calculate_arrow_points();
  if (arrows.size() < 2)
    return;
  Point left = arrows[0];
  Point right = arrows[1];

  painter.draw_line(point(0), point(1));
  painter.draw_line(point(1), left);
  painter.draw_line(point(1), right);
}

int main() {
  Application app;

  Simple_window win{Point{100, 100}, 600, 400, "Arrow test"};

  Arrow a1{Point{100, 100}, Point{300, 100}}; // horizontal
  Arrow a2{Point{100, 100}, Point{100, 300}}; // vertical
  Arrow a3{Point{300, 300}, Point{100, 100}}; // reverse diagonal

  win.attach(a1);
  win.attach(a2);
  win.attach(a3);

  win.wait_for_button();
}
