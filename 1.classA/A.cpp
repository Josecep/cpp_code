#include <cinttypes>
#include <iostream>
#include <functional>
#include "A.hpp"
using namespace std;

//A.cpp
A::A()
{
    PRINTFUN_ADDR;
}

A::~A()
{
    PRINTFUN_ADDR;
}

A::A(int a, int b, int c, uint8_t d)
    :m_a(a),m_b(b),m_c(c),m_d(d)
{
    PRINTFUN_ADDR;
}

A::A(const A& other)
//    :A(other.m_a,other.m_b,other.m_c,other.m_d) //Î¯ÍÐ¹¹Ôì
    :m_a(other.m_a),
    m_b(other.m_b),
    m_c(other.m_c),
    m_d(other.m_d)
{
    PRINTFUN_ADDR;
}

A& A::operator=(const A& other)
{
    m_a = other.m_a;
    m_b = other.m_b;
    m_c = other.m_c;
    m_d = other.m_d;
    PRINTFUN_ADDR;
    return *this;
}

void A::Dump()
{
    auto dumpItem = [this](auto name, auto& item) {
        std::cout << name << "@" << (void*)&item << ",size is " << sizeof(item) << endl;
    };
    dumpItem("m_a", m_a);
    dumpItem("m_b", m_b);
    dumpItem("m_c", m_c);
    dumpItem("m_d", m_d);
    cout << "the obj size: " << sizeof(*this) << endl;
}
A c{};
int A::Sum()
{
    return m_a + m_b + m_c + m_d;
}

int TestFunction(A& aval)
{
    return aval.Sum();
}

A PoorFactory(int a, int b, int c, uint8_t d)
{
    return A{ a,b,c,d };
}

int main()
{
    cout << __LINE__ << endl;
    /*A a{};
    A b{};
    b = a;
    A d{ a };
    a.Dump();
    b.Dump();
    c.Dump();
    d.Dump();*/

    A a = PoorFactory(3, 4, 5, 6);
    A* pa = new A{};
    pa->Dump();
    delete pa;


    cout << __LINE__ << endl;
    return 0;
}