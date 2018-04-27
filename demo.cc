#include "operator_traits.hpp"

#include <iostream>

void test_addition()
{
	std::cout << std::boolalpha;
	std::cout << operator_traits::has_addition<void>::value << std::endl;
	std::cout << operator_traits::has_addition_v<void> << std::endl;
	std::cout << operator_traits::has_addition<bool>::value << std::endl;
	std::cout << operator_traits::has_addition_v<bool> << std::endl;
	std::cout << operator_traits::has_addition<char>::value << std::endl;
	std::cout << operator_traits::has_addition_v<char> << std::endl;
	std::cout << operator_traits::has_addition<int>::value << std::endl;
	std::cout << operator_traits::has_addition_v<int> << std::endl;
	std::cout << operator_traits::has_addition<double>::value << std::endl;
	std::cout << operator_traits::has_addition_v<double> << std::endl;
	std::cout << operator_traits::has_addition<void(*)()>::value << std::endl;
	std::cout << operator_traits::has_addition_v<void(*)()> << std::endl;
}

void test_assignment()
{
	struct S{};
	struct T
	{
		T& operator =(T const&) = delete;
		T& operator =(S const&) { return *this; }
	};

	std::cout << std::boolalpha;
	std::cout << operator_traits::has_assignment<S>::value << std::endl;
	std::cout << operator_traits::has_assignment_v<T> << std::endl;
	std::cout << operator_traits::has_assignment<S, T>::value << std::endl;
	std::cout << operator_traits::has_assignment_v2<T, S> << std::endl;
}

void test_move_assignment()
{
	struct S{};
	struct T
	{
		T& operator =(T&&) = delete;
		T& operator =(S&&) { return *this; }
	};

	std::cout << std::boolalpha;
	std::cout << operator_traits::has_move_assignment<S>::value << std::endl;
	std::cout << operator_traits::has_move_assignment_v<T> << std::endl;
	std::cout << operator_traits::has_move_assignment<S, T>::value << std::endl;
	std::cout << operator_traits::has_move_assignment_v2<T, S> << std::endl;
}

template< typename T >
void test()
{
    using namespace operator_traits;
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
    std::cout << "a>b : " << has_greater_than_v<T> << std::endl;
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
    std::cout << "Testing assignment:\n";
    test_assignment();

    std::cout << "Testing type bool:\n";
    test<bool>();

    std::cout << "Testing type int:\n";
    test<int>();

    std::cout << "Testing type lambda([](){}):\n";
    auto lambda = [](){};
    test<decltype(lambda)>();

    std::cout << "Testing type lambda([=](){}):\n";
    auto mambda = [=](){};
    test<decltype(mambda)>();

    std::cout << "Testing type void(*)():\n";
    test<void(*)()>();

    std::cout << "Testing type complex<cmplex<short>>:\n";
    test<std::complex<std::complex<short>>>();

    std::cout << "Testing type dummy:\n";
    test<dummy>();

    std::cout << "Testing type uummy:\n";
    test<uummy>();

    std::cout << "Testing type vummy:\n";
    test<vummy>();

    std::cout << "Testing type std::ostream&:\n";
    test<decltype(std::cout)>();

    std::cout << "Testing assignment:\n";
    test_assignment();

    std::cout << "Testing move assignment:\n";
    test_move_assignment();

    std::cout << "Testing addition:\n";
    test_addition();


    return 0;
}

