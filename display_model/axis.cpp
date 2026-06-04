#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

double dsin(double d) { return sin(d); }

int main() {
  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Canvas"};

  // Axis setup
  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};

  ya.set_color(Color::cyan);

  ya.label.set_color(Color::dark_red);

  // draw a sine function

  Function sine{dsin, 0, 100, Point{20, 150}, 1000, 50, 50};

  sine.set_color(Color::blue);

  // draw a Polygon
  Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});
  poly.set_color(Color::red);
  poly.set_style(Line_style(Line_style::dash, 4));

  // draw a Rectangle
  Rectangle r{Point{200, 200}, 100, 50};
  r.set_fill_color(Color::yellow);

  // draw a Polygon that looks like Rectangle
  Closed_polyline poly_rect;
  poly_rect.add(Point{100, 50});
  poly_rect.add(Point{200, 50});
  poly_rect.add(Point{200, 100});
  poly_rect.add(Point{100, 100});
  poly_rect.add(Point{50, 75});
  poly_rect.set_style(Line_style(Line_style::dash, 2));
  poly_rect.set_fill_color(Color::green);

  // define some text to be displayed
  Text t{Point{150, 150}, "Hello, graphical world!"};
  t.set_font(Font::times_bold);
  t.set_font_size(20);

  // start attach gui shape

  win.attach(xa);

  win.attach(ya);

  win.attach(sine);

  win.attach(poly);
  win.attach(r);

  win.attach(poly_rect);

  win.attach(t);

  win.set_label("Fill");

  win.wait_for_button();
}
