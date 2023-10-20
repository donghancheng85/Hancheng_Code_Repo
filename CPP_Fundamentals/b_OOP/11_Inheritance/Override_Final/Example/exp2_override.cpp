class Base {

  void func1();
  virtual void func2(float);
  virtual void func3() const;
  virtual long func4(int);

  virtual void f();

};

class Derived: public Base {

  // ill-formed; no virtual method func1 exists
  void fun1(){}; //override;

  // ill-formed: bad type
  virtual void func2(float) override{};

  // ill-formed: const missing
  virtual void func3() const override{};

  // ill-formed: wrong return type
  virtual long func4(int) override{};

  // well-formed: f override Base::f
  virtual void f() override;

};

int main(){

  Base base;
  Derived derived;

};
