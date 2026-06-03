#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

int main() {
  Application app;

  Simple_window win{{100, 100}, 600, 400, "PPP graphics test"};

  Text hello{{150, 150}, "Hello, PPP graphics!"};
  win.attach(hello);

  win.wait_for_button();
}
