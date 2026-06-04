#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;
  Point tl{900, 500};

  Simple_window win{tl, 1000, 800, "Exercise7"};

  Rectangle box1{Point{350, 700}, 250, 50};

  Text t{Point{360, 710}, "int main() {...}"};

  win.attach(box1);
  win.attach(t);

  win.set_label("Exercise 10");
  win.wait_for_button();
}
