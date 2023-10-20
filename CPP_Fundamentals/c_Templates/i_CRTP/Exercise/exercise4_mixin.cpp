#include <iostream>
#include <memory>

// Implement the class here
class ShareMe: public std::enable_shared_from_this<ShareMe>
{
public:
    /**
     * static factory to create new instance of this class
    */
    static std::shared_ptr<ShareMe> create()
    {
        std::shared_ptr<ShareMe> p(new ShareMe());
        return p;
    }

    std::shared_ptr<ShareMe> getShared()
    {
        return shared_from_this();
    }

private:
    // Make the ctor private so the object cannot be treated on the stack
    // if the object is created on the stack then there will be a double delete
    // which will cause run time error
    ShareMe() = default;
};

int main() {
  // After implementing the shareMe class uncomment the code given below

  
  std::cout << std::endl;

  // share the same ShareMe object
  std::shared_ptr<ShareMe> shareMe = ShareMe::create();
  std::shared_ptr<ShareMe> shareMe1= shareMe->getShared();

  // both resources have the same address
  std::cout << "Address of resource of shareMe "<< (void*)shareMe.get() << " " << std::endl;
  std::cout << "Address of resource of shareMe1 "<< (void*)shareMe1.get() << " " << std::endl;

  // the use_count is 2
  std::cout << "shareMe.use_count(): "<< shareMe.use_count() << std::endl;
  std::cout << std::endl;
  
}