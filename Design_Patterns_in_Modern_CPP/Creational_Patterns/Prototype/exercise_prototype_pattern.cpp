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
    return Line{new Point{start->x, start->y}, new Point(end->x, end->y)};
  }
};

int main()
{
  Line line1{new Point{3,3}, new Point{4,4}};
  auto line2 = line1.deep_copy();
  
  line2.start->x = 555;

  std::cout << line1.start->x << "\n";
  std::cout << line2.start->x << "\n";
}