#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;
  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Exercise7"};

  Rectangle house{Point{150, 180}, 250, 170};

  Polygon roof;
  roof.add(Point{130, 180});
  roof.add(Point{275, 80});
  roof.add(Point{420, 180});

  // Door, left window, right window, chimney
  Rectangle door{Point{250, 270}, 50, 80};
  Rectangle left_window{Point{180, 220}, 50, 40};
  Rectangle right_window{Point{320, 220}, 50, 40};
  Rectangle chimney{Point{300, 110}, 30, 70};

  win.attach(house);
  win.attach(roof);
  win.attach(door);
  win.attach(left_window);
  win.attach(right_window);
  win.attach(chimney);

  win.set_label("Exercise 7");
  win.wait_for_button();
}
