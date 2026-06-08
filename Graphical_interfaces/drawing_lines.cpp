#include "PPP/GUI.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include <sstream>

struct Lines_window : Window {
  Lines_window(Application &application, Point xy, int w, int h,
               const string &title);
  Open_polyline lines;
  void wait_for_button();

private:
  Application *app = nullptr;
  Button quit_button;
  In_box next_xy;
  Out_box xy_out;
  void next();
  void quit();
};

Lines_window::Lines_window(Application &application, Point xy, int w, int h,
                           const string &title)
    : Window{xy, w, h, title}, app(&application),
      quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", [this]() { quit(); }},
      next_xy{Point{250, 0}, 50, 20, "next xy;", [this]() { next(); }},
      xy_out{Point{10, 10}, "current (x,y): "} {
  attach(lines);
  attach(quit_button);

  next_xy.hide_buttons(); // a Qt input box comes with buttons; we decided to
                          // hide them
  attach(next_xy);
  next_xy.show(); // but we do want the box itself to show

  xy_out.label.set_font_size(8); // use a smaller than default font
  xy_out.data.set_font_size(8);
  attach(xy_out);
}

void Lines_window::quit() {
  end_button_wait();
  next_xy.dismiss();
  app->quit();
}

void Lines_window::next() {
  if (next_xy.last_result() == In_box::accepted) {
    string s = next_xy.last_string_value();
    istringstream iss{s};
    int x = 0;
    char ch = 0;
    int y = 0;
    iss >> x >> ch >> y;
    lines.add(Point{x * 30, y * 30});

    ostringstream oss;
    oss << '(' << x << ',' << y << ')';
    xy_out.put(oss.str());
  }
  next_xy.clear_last_result();
}

int main() {
  try {
    Application app;
    Lines_window win{app, Point{100, 100}, 600, 400, "lines"};
    app.gui_main();
  } catch (exception &e) {
    cerr << "exception: " << e.what() << "\n";
    return 1;
  } catch (...) {
    cerr << "some exception\n";
    return 2;
  }
}
