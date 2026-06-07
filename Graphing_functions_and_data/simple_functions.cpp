#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

double one(double) { return 1; }

double slope(double x) { return 0.5 * x; }

double square(double x) { return x * x; }

double dcos(double d) { return cos(d); }

double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {
  Application app;

  constexpr int xmax = 600;
  constexpr int ymax = 400;

  constexpr int x_org = xmax / 2;
  constexpr int y_org = ymax / 2;
  constexpr Point org{x_org, y_org};

  constexpr int r_min = -10;
  constexpr int r_max = 11;

  constexpr int n_points = 400;

  constexpr int x_scale = 30;
  constexpr int y_scale = 30;

  Simple_window win{Point{100, 100}, xmax, ymax, "Three functions"};

  Function s{one, r_min, r_max, org, n_points, x_scale, y_scale};
  Function s2{slope, r_min, r_max, org, n_points, x_scale, y_scale};
  Function s3{square, r_min, r_max, org, n_points, x_scale, y_scale};
  Function s4{dcos, r_min, r_max, org, 400, 30, 30};
  s4.set_color(Color::blue);
  Function s5{sloping_cos, r_min, r_max, org, 400, 30, 30};
  s5.set_color(Color::green);

  // Put text to notate the function
  Text ts{Point{100, y_org - 40}, "one"};
  Text ts2{Point{100, y_org + y_org / 2 - 20}, "0.5*x"};
  Text ts3{Point{x_org - 100, 20}, "x*x"};
  win.set_label("Functional Programming: label functions");

  // Set axsesz
  constexpr int xlength = xmax - 40;
  constexpr int ylength = ymax - 40;

  Axis x{Axis::x, Point{20, y_org}, xlength, xlength / x_scale, "one_notch==1"};
  Axis y{Axis::y, Point{x_org, ylength + 20}, ylength, ylength / y_scale,
         "one_notch==1"};

  x.set_color(Color::red);
  y.set_color(Color::red);

  win.attach(s);
  win.attach(s2);
  win.attach(s3);
  win.attach(s4);
  win.attach(s5);

  win.attach(x);
  win.attach(y);
  win.wait_for_button();
}
