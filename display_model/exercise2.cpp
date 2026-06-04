#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Exercise2"};

  Rectangle r{Point{250, 185}, 100, 30};

  Text t{Point{250, 185}, "Howdy!"};

  win.attach(r);
  win.attach(t);

  win.set_label("Exercise 2");

  win.wait_for_button();
}
