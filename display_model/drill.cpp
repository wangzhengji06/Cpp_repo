#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;

  Point tl{900, 500};
  Simple_window win{tl, 600, 400, "My Window"};

  win.set_label("My Window");

  win.wait_for_button();
}
