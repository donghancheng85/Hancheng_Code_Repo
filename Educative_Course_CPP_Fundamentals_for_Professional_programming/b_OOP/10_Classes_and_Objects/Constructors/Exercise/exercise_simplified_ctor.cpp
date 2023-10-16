#include <iostream>

class Widget{
  public:

    // write simplified version of constructor here

    Widget() = default;

    Widget(int w): width(w), height(w*3/4){}

    Widget(int w, int h): width(w), height(h){}

    void show(){ std::cout << std::boolalpha << width << "x" << height
                           << ", frame: " << frame << ", visible: " << visible
                           << std::endl;
     }
  private:
    // int getHeight(int w){ return w*3/4; }
    int width = 640;
    int height = 480;
    bool frame = false;
    bool visible = true;
};

int main(){

  std::cout << std::endl;

  Widget wVGA;
  Widget wSVGA(800);
  Widget wHD(1280, 720);

  wVGA.show();
  wSVGA.show();
  wHD.show();

  std::cout << std::endl;

}