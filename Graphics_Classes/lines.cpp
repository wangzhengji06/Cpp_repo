#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

int main() {

  Application app;

  constexpr Point x{100, 100};

  Simple_window win{x, 600, 400, "two lines"};

  int x_size = win.x_max();
  int y_size = win.y_max();
  int x_grid = 80;
  int y_grid = 40;

  Lines grid;

  for (int x = x_grid; x < x_size; x += x_grid)
    grid.add(Point{x, 0}, Point{x, y_size});
  for (int y = y_grid; y < y_size; y += y_grid)
    grid.add(Point{0, y}, Point{x_size, y});

  grid.set_style(Line_style::dash);
  grid.set_color(Color::cyan);

  win.attach(grid);
  win.wait_for_button();
}
