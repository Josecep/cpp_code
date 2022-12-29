#pragma once
#define PRINTFUN_ADDR std::cout<<static_cast<const char*>(__func__)<<" at "<<this<<std::endl;

//A.hpp
class A {
    int m_a = 1;
    int m_b = 2;
    int m_c = 3;
    uint8_t m_d = 4;
public:
    A(int a, int b, int c, uint8_t d);
    A(const A& other);
    A& operator=(const A& other);
    A();
    ~A();
    int Sum();
    void Dump();
};


