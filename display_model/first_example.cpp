#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;

  Point tl{900, 500};

  Simple_window win{tl, 600, 400, "Canvas"};

  Text hello{{150, 150}, "Hello, PPP graphics!"};
  win.attach(hello);

  win.wait_for_button();
}
