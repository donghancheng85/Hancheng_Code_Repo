/**
 * @file decoratorPatternDemo.cpp
 * @brief A demo of decorator pattern.
 * Rectangle is the concrete component to be decorated. MarginShape and BorderShape is the decorator.
 *
 */

#include <iostream>
#include <string>

struct Shape
{
    virtual std::string str() = 0;
    virtual float getWidth() = 0;
    virtual float getHeight() = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
    float width = 10.0f;
    float height = 5.0f;

public:
    std::string str() override
    {
        return std::string("A rectangle of width ") + std::to_string(width) + " and height " + std::to_string(height);
    }
    float getWidth() override
    {
        return width;
    }
    float getHeight() override
    {
        return height;
    }
};

class MarginShape : public Shape
{
    float margin;
    Shape &shape;
    float width;
    float height;

public:
    MarginShape(float m, Shape &s) : shape(s)
    {
        margin = m;
        width = shape.getWidth() + 2 * margin;
        height = shape.getHeight() + 2 * margin;
    }
    std::string str() override
    {
        return shape.str() + std::string(" with a margin of ") + std::to_string(margin);
    }
    float getWidth() override
    {
        return width;
    }
    float getHeight() override
    {
        return height;
    }
};

class BorderShape : public Shape
{
public:
    BorderShape(float b, Shape &s)
        : border{b}, shape{s}, width{shape.getWidth() + border}, height{shape.getHeight() + border}
    {
    }

    std::string str() override
    {
        return shape.str() + std::string(" with a border of ") + std::to_string(border);
    }

    float getWidth() override
    {
        return width;
    }

    float getHeight() override
    {
        return height;
    }

    void foo(){};

private:
    float border;
    Shape &shape;
    float width;
    float height;
};

int main()
{
    Rectangle rectangle;
    MarginShape marginShape(2.0f, rectangle);

    std::cout << rectangle.str() << " Width: " << rectangle.getWidth() << " and Height: " << rectangle.getHeight()
              << std::endl;
    std::cout << marginShape.str() << " Width: " << marginShape.getWidth() << " and Height: " << marginShape.getHeight()
              << std::endl;

    Rectangle rectangle1;
    BorderShape borderShape(2.0f, rectangle1);
    std::cout << rectangle1.str() << " Width: " << rectangle1.getWidth() << " and Height: " << rectangle1.getHeight()
              << std::endl;
    std::cout << borderShape.str() << " Width: " << borderShape.getWidth() << " and Height: " << borderShape.getHeight()
              << std::endl;

    return 0;
}
