#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief This is an example of expression template. We overload the +, -, *, / operators of MyVector.
 * MyVector can be treated as a container adapter.
 * With Expression Templates, we can evaluate the arithmetic operators of MyVector and compile time.
 * The calculation will be done and run time.
 */

template <typename T, typename Cont = std::vector<T>>
class MyVector
{
    Cont cont;

public:
    // MyVector with initial size
    MyVector(const std::size_t n) : cont(n)
    {
    }

    // MyVector with initial size and value
    MyVector(const std::size_t n, const double initialValue) : cont(n, initialValue)
    {
    }

    // Constructor for underlying container
    MyVector(const Cont &other) : cont(other)
    {
    }

    // assignment operator for MyVector of different type
    template <typename T2, typename R2>
    MyVector &operator=(const MyVector<T2, R2> &other)
    {
        assert(size() == other.size());
        for (std::size_t i = 0; i < cont.size(); ++i)
            cont[i] = other[i];
        return *this;
    }

    // size of underlying container
    std::size_t size() const
    {
        return cont.size();
    }

    // index operators
    T operator[](const std::size_t i) const
    {
        return cont[i];
    }

    T &operator[](const std::size_t i)
    {
        return cont[i];
    }

    // returns the underlying data
    const Cont &data() const
    {
        return cont;
    }

    Cont &data()
    {
        return cont;
    }
};

// MyVector - MyVector
template <typename T, typename Lhs, typename Rhs>
class MyVectorSub
{
public:
    MyVectorSub(const Lhs& lhs, const Rhs& rhs) : m_lhs{lhs}, m_rhs{rhs}{}

    T operator [](const std::size_t i) const
    {
        return m_lhs[i] - m_rhs[i];
    }

    std::size_t size() const
    {
        return m_lhs.size();
    }

private:
    const Lhs& m_lhs;
    const Rhs& m_rhs;
};

// function template for the - operator
template<typename T, typename Lhs, typename Rhs>
MyVector<T, MyVectorSub<T, Lhs, Rhs>> operator - (const MyVector<T, Lhs>& lhs, const MyVector<T, Rhs>& rhs)
{
    return MyVector<T, MyVectorSub<T, Lhs, Rhs>>(MyVectorSub<T, Lhs, Rhs>(lhs.data(), rhs.data()));
}

// Myvector / MyVector
template <typename T, typename Lhs, typename Rhs>
class MyVectorDiv
{
public:
    MyVectorDiv(const Lhs& lhs, const Rhs& rhs) : m_lhs{lhs}, m_rhs{rhs}{}

    T operator [](std::size_t i) const
    {
        if (m_lhs[i] == 0 || m_rhs[i] == 0)
            throw std::runtime_error("divided by 0!!");

        return m_lhs[i] / m_rhs[i];
    }

    std::size_t size() const
    {
        return m_lhs.size();
    }

private:
    const Lhs& m_lhs;
    const Rhs& m_rhs;
};

// function template for the / operator
template <typename T, typename Lhs, typename Rhs>
MyVector<T, MyVectorDiv<T, Lhs, Rhs>> operator / (const MyVector<T, Lhs>& lhs, const MyVector<T, Rhs>& rhs)
{
    return MyVector<T, MyVectorDiv<T, Lhs, Rhs>>(MyVectorDiv<T, Lhs, Rhs>(lhs.data(), rhs.data()));
}


// MyVector + MyVector
template <typename T, typename Lhs, typename Rhs>
class MyVectorAdd
{
    const Lhs &op1;
    const Rhs &op2;

public:
    MyVectorAdd(const Lhs &a, const Rhs &b) : op1(a), op2(b)
    {
    }

    T operator[](const std::size_t i) const
    {
        return op1[i] + op2[i];
    }

    std::size_t size() const
    {
        return op1.size();
    }
};

// elementwise MyVector * MyVector
template <typename T, typename Lhs, typename Rhs>
class MyVectorMul
{
    const Lhs &op1;
    const Rhs &op2;

public:
    MyVectorMul(const Lhs &a, const Rhs &b) : op1(a), op2(b)
    {
    }

    T operator[](const std::size_t i) const
    {
        return op1[i] * op2[i];
    }

    std::size_t size() const
    {
        return op1.size();
    }
};

// function template for the + operator
template <typename T, typename R1, typename R2>
MyVector<T, MyVectorAdd<T, R1, R2>> operator+(const MyVector<T, R1> &a, const MyVector<T, R2> &b)
{
    return MyVector<T, MyVectorAdd<T, R1, R2>>(MyVectorAdd<T, R1, R2>(a.data(), b.data()));
}

// function template for the * operator
template <typename T, typename R1, typename R2>
MyVector<T, MyVectorMul<T, R1, R2>> operator*(const MyVector<T, R1> &a, const MyVector<T, R2> &b)
{
    return MyVector<T, MyVectorMul<T, R1, R2>>(MyVectorMul<T, R1, R2>(a.data(), b.data()));
}

// function template for << operator
template <typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &cont)
{
    std::cout << std::endl;
    for (int i = 0; i < cont.size(); ++i)
    {
        os << cont[i] << ' ';
    }
    os << std::endl;
    return os;
}

int main()
{

    MyVector<double> x(10, 5.4);
    MyVector<double> y(10, 10.3);

    MyVector<double> result(10);

    result = x + x + y * y;

    std::cout << result << std::endl;

    MyVector<double> x1(2, 1.0);
    MyVector<double> y1(2, 2.0);

    MyVector<double> result1(2);

    result1 = x1-y1 + x1/y1;
    std::cout << result1 << std::endl;
}
