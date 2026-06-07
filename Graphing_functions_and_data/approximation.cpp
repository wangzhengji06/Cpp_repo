#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

double fact(int n) {
  int r = 1;
  while (n > 1) {
    r *= n;
    --n;
  }
  return r;
};

double term(double x, int n) { return pow(x, n) / fact(n); }

double exp_n(double x, int n) {
  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += term(x, i);
  return sum;
}

int main() {
  Application app;

  constexpr int xmax = 600;
  constexpr int ymax = 400;

  constexpr int x_org = xmax / 2;
  constexpr int y_org = ymax / 2;
  constexpr Point org{x_org, y_org};

  constexpr int r_min = -10;
  constexpr int r_max = 11;

  constexpr int x_scale = 30;
  constexpr int y_scale = 30;

  constexpr int xlength = xmax - 40;
  constexpr int ylength = ymax - 40;

  Simple_window win{Point{100, 100}, xmax, ymax, "Three functions"};

  Axis x{Axis::x, Point{20, y_org}, xlength, xlength / x_scale, "one_notch==1"};
  Axis y{Axis::y, Point{x_org, ylength + 20}, ylength, ylength / y_scale,
         "one_notch==1"};

  x.set_color(Color::red);
  y.set_color(Color::red);

  win.attach(x);
  win.attach(y);
  // set function
  for (int n = 0; n < 50; ++n) {
    ostringstream ss;
    ss << "exp approximation; n==" << n;
    win.set_label(ss.str());

    // get next approximation:
    Function e{[n](double x) { return exp_n(x, n); },
               r_min,
               r_max,
               org,
               200,
               x_scale,
               y_scale};

    win.attach(e);
    win.wait_for_button();
    win.detach(e);
  }
}
