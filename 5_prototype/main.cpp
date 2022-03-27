#include <iostream>

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}

  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;

  Line(Point* const start, Point* const end)
      : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    auto*  new_start = new Point(start->x, start->y);
    auto* new_end = new Point(end->x, end->y);
    return Line(new_start, new_end);
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
