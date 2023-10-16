#include <iostream>

struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual ~Rectangle() = default;
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
    : square(square) 
  { }
    
  int width() const override
  {
    return square.side;
  }
  
  int height() const override
  {
    return square.side;
  }
  
  // The adapter need to hold a pointer or reference to the adaptee!!!!
  const Square& square;
};

int main()
{
  Square sq{5};
  SquareToRectangleAdapter rec{sq};

  std::cout << "area of rectangle is: " << rec.area() << "\n";
}