#include <iostream>
#include <set>

class Graphic
{
public:
    virtual void print() const = 0;
    virtual ~Graphic()
    {
    }
};

class GraphicComposite : public Graphic
{
    std::set<Graphic const *> children;
    using grIter = std::set<Graphic const *>::const_iterator ;

public:
    void print() const
    {
        for (grIter it = children.begin(); it != children.end(); ++it)
            (*it)->print();
    }

    void add(Graphic const *component)
    {
        children.insert(component);
    }

    void remove(Graphic const *component)
    {
        children.erase(component);
    }
};

class Ellipse : public Graphic
{
public:
    void print() const
    {
        std::cout << "Ellipse ";
    }
};

class Circle : public Graphic
{
public:
    void print() const override
    {
        std::cout << "Circle ";
    }
};

void printGrafik(const std::string &name, const Graphic *graph)
{
    std::cout << name;
    graph->print();
    std::cout << "\n\n";
}

int main()
{
    Ellipse ellipse1, ellipse2, ellipse3, ellipse4;

    GraphicComposite graphic1, graphic2, graphicGroup;

    graphic1.add(&ellipse1);
    graphic1.add(&ellipse2);
    graphic1.add(&ellipse3);
    graphic2.add(&ellipse4);

    graphicGroup.add(&graphic1);
    graphicGroup.add(&graphic2);

    printGrafik("graphic2.print(): ", &graphic2);
    printGrafik("graphicGroup.print(): ", &graphicGroup);

    Circle circle1, circle2, circle3, circle4;
    graphic1.add(&circle1);
    graphic1.add(&circle2);
    graphic2.add(&circle3);
    graphic2.add(&circle4);

    printGrafik("graphicGroup.print(): ", &graphicGroup);
    return 0;
}
