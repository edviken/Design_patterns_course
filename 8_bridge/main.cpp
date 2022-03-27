#include <iostream>
#include <string>
using namespace std;

struct Renderer {
  virtual string what_to_render() const = 0;
};

struct VectorRenderer : Renderer {
  string what_to_render() const override {
    return std::string("lines");
  }
};

struct RasterRenderer : Renderer {
  string what_to_render() const override {
    return std::string("pixels");
  }
};

struct Shape
{
protected:
  const Renderer& renderer;
public:
  Shape(const Renderer& renderer) : renderer(renderer) {}

  virtual string str() {
    return "Drawing " + name + " as " + renderer.what_to_render();
//    cout << "Drawing " << name << " as " << renderer.what_to_render();
  };

  string name;
};

struct Triangle : Shape
{
  Triangle(const Renderer& renderer) : Shape(renderer)
  {
    name = "Triangle";
  }
};

struct Square : Shape
{
  Square(const Renderer& renderer) : Shape(renderer)
  {
    name = "Square";
  }
};

/*
struct VectorSquare : Square
{
  string str() const
  {
    return "Drawing " + name + " as lines";
  }
};

struct RasterSquare : Square
{
  string str() const
  {
    return "Drawing " + name + " as pixels";
  }
};
*/

// imagine e.g. VectorTriangle/RasterTriangle etc. here


int main() {
  cout << Triangle(RasterRenderer()).str(); // returns "Drawing Triangle as Pixels
  cout << "\n";
  cout << Square(VectorRenderer()).str(); // returns "Drawing Triangle as Pixels
  return 0;
}
