#include <iostream>
#include <string>
using namespace std;
using namespace std::string_literals;

/*Renders definition*/

// Renderers interface
struct Renderer
{
    virtual ~Renderer() = default;
    virtual std::string what_to_render_as() const = 0;
};

struct RasterRenderer : public Renderer
{
    std::string what_to_render_as() const override
    {
        return " as pixels";
    }
};

struct VectorRenderer : public Renderer
{
    std::string what_to_render_as() const override
    {
        return " as vectors";
    }
};


/*Shapes definition*/

//Shape Interface
struct Shape
{
protected:
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer){}
public:
    virtual ~Shape() = default;
    string name;
    virtual std::string str() const = 0;
};

struct Triangle : public Shape
{
    Triangle(Renderer& renderer) : Shape{renderer}
    {
        name = "Triangle";
    }

    std::string str() const override
    {
        return "Drawing "s + name + renderer.what_to_render_as();
    }
};

struct Square : public Shape
{
    Square(Renderer& renderer) : Shape{renderer}
    {
        name = "Square";
    }

        std::string str() const override
    {
        return "Drawing "s + name + renderer.what_to_render_as();
    }
};

// struct VectorSquare : Square
// {
//     string str() const
//     {
//         return "Drawing " + name + " as lines";
//     }
// };

// struct RasterSquare : Square
// {
//     string str() const
//     {
//         return "Drawing " + name + " as pixels";
//     }
// };

// imagine e.g. VectorTriangle/RasterTriangle etc. here
int main()
{
    RasterRenderer rr;
    Triangle t(rr);

    std::cout << t.str() << "\n";
}