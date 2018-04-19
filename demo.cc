#include "operator_detection.hpp"

#include <iostream>
template< typename T >
void test()
{
    using namespace operator_detection;
    std::cout << "a=b : " << has_assignment_v<T> << std::endl;
    std::cout << "a=std::move(b) : " << has_move_assignment_v<T> << std::endl;
    std::cout << "a+b : " << has_addition_v<T> << std::endl;
    std::cout << "a-b : " << has_subtraction_v<T> << std::endl;
    std::cout << "+a : " << has_unary_plus_v<T> << std::endl;
    std::cout << "-a : " << has_unary_minus_v<T> << std::endl;
    std::cout << "a*b : " << has_multiplication_v<T> << std::endl;
    std::cout << "a/b : " << has_division_v<T> << std::endl;
    std::cout << "a%b : " << has_modulo_v<T> << std::endl;
    std::cout << "++a : " << has_prefix_increment_v<T> << std::endl;
    std::cout << "a++ : " << has_postfix_increment_v<T> << std::endl;
    std::cout << "--a : " << has_prefix_decrement_v<T> << std::endl;
    std::cout << "a-- : " << has_postfix_decrement_v<T> << std::endl;
    std::cout << "a==b : " << has_equal_to_v<T> << std::endl;
    std::cout << "a!=b : " << has_not_equal_to_v<T> << std::endl;
    std::cout << "a>b : " << has_greate_than_v<T> << std::endl;
    std::cout << "a<b : " << has_less_than_v<T> << std::endl;
    std::cout << "a>=b : " << has_greater_than_or_equal_to_v<T> << std::endl;
    std::cout << "a<=b : " << has_less_than_or_equal_to_v<T> << std::endl;
    std::cout << "!a : " << has_logical_not_v<T> << std::endl;
    std::cout << "a&&b : " << has_logical_and_v<T> << std::endl;
    std::cout << "a||b : " << has_logical_or_v<T> << std::endl;
    std::cout << "~a : " << has_bitwise_not_v<T> << std::endl;
    std::cout << "a&b : " << has_bitwise_and_v<T> << std::endl;
    std::cout << "a|b : " << has_bitwise_or_v<T> << std::endl;
    std::cout << "a^b : " << has_bitwise_xor_v<T> << std::endl;
    std::cout << "a<<n : " << has_bitwise_left_shift_v<T> << std::endl;
    std::cout << "a>>n : " << has_bitwise_right_shift_v<T> << std::endl;
    std::cout << "a+=b : " << has_addition_assignment_v<T> << std::endl;
    std::cout << "a-=b : " << has_subtraction_assignment_v<T> << std::endl;
    std::cout << "a*=b : " << has_multiplication_assignment_v<T> << std::endl;
    std::cout << "a/=b : " << has_division_assignment_v<T> << std::endl;
    std::cout << "a%=b : " << has_modulo_assignment_v<T> << std::endl;
    std::cout << "a&=b : " << has_bitwise_and_assignment_v<T> << std::endl;
    std::cout << "a|=b : " << has_bitwise_or_assignment_v<T> << std::endl;
    std::cout << "a<<=n : " << has_bitwise_left_shift_assignment_v<T> << std::endl;
    std::cout << "a>>=n : " << has_bitwise_right_shift_assignment_v<T> << std::endl;
    std::cout << "O<<a : " << has_ostream_v<T> << std::endl;
    std::cout << "I>>a : " << has_istream_v<T> << std::endl;
    std::cout << "a[0] : " << has_bracket_v<T> << std::endl;
    std::cout << "a[0] const : " << has_const_bracket_v<T> << std::endl;
    std::cout << std::endl;
}


struct dummy{ };

struct tummy
{
    tummy( dummy const& ) {}
};

void f() {}

struct uummy
{
    dummy operator[](int)
    {
        return {};
    }
};

struct vummy
{
    uummy operator[](int) const
    {
        return {};
    }
};

#include <iostream>
#include <complex>

int main()
{
    test<int>();


    //auto lambda = [](){};
    //test<decltype(lambda)>();

    //test<tummy>();

    //std::cout << "tummy = dummy : " << operator_detection::has_assignment_v2<tummy, dummy> << std::endl;


    test<std::complex<std::complex<short>>>();

    test<uummy>();

    test<vummy>();

    return 0;
}

