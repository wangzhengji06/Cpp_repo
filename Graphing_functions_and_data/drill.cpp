#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <cmath>

double one(double) { return 1; }

double slope(double x) { return 0.5 * x; }

double square(double x) { return x * x; }

int main() {
  Application app;
  constexpr int x_max = 600;
  constexpr int y_max = 600;

  Simple_window win{Point{100, 100}, x_max, y_max, "Function Graphs"};

  constexpr int xlength = x_max - 200;
  constexpr int ylength = y_max - 200;

  constexpr int x_org = x_max / 2;
  constexpr int y_org = y_max / 2;

  constexpr int x_scale = 20;
  constexpr int y_scale = 20;

  Axis x{Axis::x, Point{100, y_org}, xlength, xlength / x_scale,
         "one notch == 20 pixels"};

  Axis y{Axis::y, Point{x_org, ylength + 100}, ylength, ylength / y_scale,
         "one notch == 20 pixels"};

  x.set_color(Color::red);
  y.set_color(Color::red);

  constexpr int r_min = -10;
  constexpr int r_max = 11;

  constexpr int n_points = 400;

  constexpr Point orig{x_org, y_org};

  Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Text ts2{Point{100, 390}, "0.5x"};
  Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s4{[](double x) { return cos(x); },
              r_min,
              r_max,
              orig,
              n_points,
              x_scale,
              y_scale};
  s4.set_color(Color::blue);
  Function s5{[](double x) { return slope(x) + cos(x); },
              r_min,
              r_max,
              orig,
              n_points,
              x_scale,
              y_scale};

  win.attach(x);
  win.attach(y);
  win.attach(s);
  win.attach(s2);
  win.attach(ts2);
  win.attach(s3);
  win.attach(s4);
  win.attach(s5);
  win.wait_for_button();
}
