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
  {
    m_width = square.side;
    m_height = square.side;
  }
  int m_width, m_height;
  int height() const override {
    return m_height;
  }
  int width() const override {
    return m_width;
  }
};

int main() {

  return 0;
}
