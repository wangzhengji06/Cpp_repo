#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

class Group : public Shape {
public:
  Group(const Group &);
  void move(int dx, int dy) override;
  void add(Shape &p);

protected:
  void draw_specifics(Painter &painter) const override;

private:
  Vector_ref<Shape> shapes;
};

void Group::add(Shape &p) { shapes.push_back(p); }

void Group::move(int dx, int dy) {
  for (Shape *x : shapes) {
    x->move(dx, dy);
  }
}

void Group::draw_specifics(Painter &painter) const {
  for (Shape *x : shapes) {
    x->draw(painter);
  }
}
