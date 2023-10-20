// templateClassTemplateGeneralFriendship.cpp

#include <iostream>

template <typename T> void myFriendFunction(T);
template <typename U> class MyFriend;


class GrantingFriendshipAsClass{

  template <typename U> friend void myFriendFunction(U);
  template <typename U> friend class MyFriend;

private:
  std::string secret{"My secret from GrantingFriendshipAsClass."};

};

template <typename T>
class GrantingFriendshipAsClassTemplate{

  template <typename U> friend void myFriendFunction(U);
  template <typename U> friend class MyFriend;

private:
  std::string secret{"My secret from GrantingFriendshipAsClassTemplate."};

};

template <typename T>
void myFriendFunction(T){
  GrantingFriendshipAsClass myFriend;
  std::cout << myFriend.secret << std::endl;

  GrantingFriendshipAsClassTemplate<double> myFriend1;
  std::cout << myFriend1.secret << std::endl;
}

template <typename T>
class MyFriend{
public:
  MyFriend(){
    GrantingFriendshipAsClass myFriend;
    std::cout << myFriend.secret << std::endl;

    GrantingFriendshipAsClassTemplate<T> myFriend1;
    std::cout << myFriend1.secret << std::endl;
  }
};

int main(){

  std::cout << std::endl;

  int a{2011};
  myFriendFunction(a);

  MyFriend<double> myFriend;

  std::cout << std::endl;

}
