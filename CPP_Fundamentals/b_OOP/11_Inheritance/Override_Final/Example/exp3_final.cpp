class Base {
  virtual void h(int) final;

  virtual void g(long int);
};

class Derived: public Base {

  // ill-formed: base method declared final
  //virtual void h(int);
  
   // well-formed: a new virtual function
  virtual void h(double);

  virtual void g(long int) final;
};

class DerivedDerived: public Derived {
  //virtual void g(long int);
};

struct FinalClass final { };
//struct DerivedClass: FinalClass { };

int main(){

  Base base;
  Derived derived;
  DerivedDerived derivedDerived;

  FinalClass finalClass;
  //DerivedClass derivedClass;

};
