# operator\_traits

A single header file to heck if an [operator](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) defined or not.


## Type categories 


| type category  | function  | comment  |
|---|---|---|
|  [has_assignment](#has_assignment) | checks if `auto operato =(T const)` exist or not  |   |
|  [has_move_assignment](#has_move_assignment) | checks if `auto operator=(T&&)` exist or not  |   |
|  [has_addition](#has_addition) | checks if `a+b` exist or not  |   |
|  [has_subtraction](#has_subtraction) | checks if `a - b` exist or not  |   |
|  [has_unary_plus](#has_unary_plus) | checks if `+a` exist or not  |   |
|  [has_unary_minus](#has_unary_minus) | checks if `-a` exist or not  |   |
|  [has_multiplication](#has_multiplication) | checks if `a*b` exist or not  |   |
|  [has_division](#has_division) | checks if `a/b` exist or not  |   |
|  [has_modulo](#has_modulo) | checks if `a%b` exist or not  |   |
|  [has_prefix_increment](#has_prefix_increment) | checks if `++a` exist or not  |   |
|  [has_postfix_increment](#has_postfix_increment) | checks if `a++` exist or not  |   |
|  [has_prefix_decrement](#has_prefix_decrement) | checks if `--a` exist or not  |   |
|  [has_postfix_decrement](#has_postfix_decrement) | checks if `a--` exist or not  |   |
|  [has_equal_to](#has_equal_to) | checks if `a==b` exist or not  |   |
|  [has_not_equal_to](#has_not_equal_to) | checks if `a!=b` exist or not  |   |
|  [has_greater_than](#has_greater_than) | checks if `a>b` exist or not  |   |
|  [has_less_than](#has_less_than) | checks if `a<b` exist or not  |   |
|  [has_greater_than_or_equal_to](#has_greater_than_or_equal_to) | checks if `a>=b` exist or not  |   |
|  [has_less_than_or_equal_to](#has_less_than_or_equal_to) | checks if `a<=b` exist or not  |   |
|  [has_logical_not](#has_logical_not) | checks if `!a` exist or not  |   |
|  [has_logical_and](#has_logical_and) | checks if `a&&b` exist or not  |   |
|  [has_logical_or](#has_logical_or) | checks if <code>a\|\|b</code> exist or not  |   |
|  [has_bitwise_not](#has_bitwise_not) | checks if `~a` exist or not  |   |
|  [has_bitwise_and](#has_bitwise_and) | checks if `a&b` exist or not  |   |
|  [has_bitwise_or](#has_bitwise_or) | checks if <code>a\|b</code> exist or not  |   |
|  [has_bitwise_xor](#has_bitwise_xor) | checks if `a^b` exist or not  |   |
|  [has_bitwise_left_shift](#has_bitwise_left_shift) | checks if `a<<N` exist or not  |   |
|  [has_bitwise_right_shift](#has_bitwise_right_shift) | checks if `a>>N` exist or not  |   |
|  [has_addition_assignment](#has_addition_assignment) | checks if `a+=b` exist or not  |   |
|  [has_subtraction_assignment](#has_subtraction_assignment) | checks if `a-=b` exist or not  |   |
|  [has_multiplication_assignment](#has_multiplication_assignment) | checks if `a*=b` exist or not  |   |
|  [has_division_assignment](#has_division_assignment) | checks if `a/=b` exist or not  |   |
|  [has_modulo_assignment](#has_modulo_assignment) | checks if `a%=b` exist or not  |   |
|  [has_bitwise_and_assignment](#has_bitwise_and_assignment) | checks if `a&=b` exist or not  |   |
|  [has_bitwise_or_assignment](#has_bitwise_or_assignment) | checks if <code>a\|=b</code> exist or not  |   |
|  [has_bitwise_leftshift_assignment](#has_bitwise_leftshift_assignment) | checks if `a<<=N` exist or not  |   |
|  [has_bitwise_rightshift_assignment](#has_bitwise_rightshift_assignment) | checks if `a>>=N` exist or not  |   |
|  [has_ostream](#has_ostream) | checks if `std::cout<<a` exist or not  |   |
|  [has_istream](#has_istream) | checks if `std::cin>>a` exist or not  |   |
|  [has_bracket](#has_bracket) | checks if `a[N]` exist or not  |   |
|  [has_const_bracket](#has_const_bracket) | checks if `auto const& a = xxx; a[N];` exist or not  |   |



## `has_addition`

```cpp
template<typename T>
struct has_addition;
```

Checks if 'auto operator + (T const&, T const&)' exists or not.


### Helper variable template `has_addition_v`

```cpp
template< class T >
inline constexpr bool has_addition_v = has_addition<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_addition<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_addition_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_addition<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_addition_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_addition<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_addition_v<void(*)()> << std::endl;
	return 0;
}
```




## `has_move_assignment`

```cpp
template<typename T, typename U> 
struct has_move_assignment;

template<typename T>
struct has_move_assignment;
```

Checks if `auto T::operator=(U&&)` or `auto T::operator=(T&&)` exist or not.

###  Helper variable template `has_move_assignment_v` and `has_move_assignment_v2`

```cpp
template< class T >
inline constexpr bool has_move_assignment_v = has_move_assignment<T>::value;

template< class T, class U >
inline constexpr bool has_move_assignment_v2 = has_move_assignment<T, U>::value;
```

### Example

```
#include "operator_traits.hpp"
#include <iostream>

struct S{};
struct T
{
T& operator =(T&&) = delete;
T& operator =(S&&) { return *this; }
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << operator_traits::has_move_assignment<S>::value << std::endl; //true
	std::cout << operator_traits::has_move_assignment_v<T> << std::endl; //false
	std::cout << operator_traits::has_move_assignment<S, T>::value << std::endl; //false
	std::cout << operator_traits::has_move_assignment_v2<T, S> << std::endl; //true
	return 0;
}

```


## `has_assignment`

```cpp
template<typename T, typename U> 
struct has_assignment;

template<typename T>
struct has_assignment;
```

Checks if `auto T::operator=(T const&)` or `auto T::operator=(T const&)` exist or not.

###  Helper variable template `has_assignment_v` and `has_assignment_v2`

```cpp
template< class T >
inline constexpr bool has_assignment_v = has_assignment<T>::value;

template< class T, class U >
inline constexpr bool has_assignment_v2 = has_assignment<T, U>::value;
```

### Example

```
#include "operator_traits.hpp"
#include <iostream>

struct S{};
struct T
{
T& operator =(T const&) = delete;
T& operator =(S const&) { return *this; }
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << operator_traits::has_assignment<S>::value << std::endl; //true
	std::cout << operator_traits::has_assignment_v<T> << std::endl; //false
	std::cout << operator_traits::has_assignment<S, T>::value << std::endl; //false
	std::cout << operator_traits::has_assignment_v2<T, S> << std::endl; //true
	return 0;
}

```


## `has_subtraction`

```cpp
template<typename T>
struct has_subtraction;
```

Checks if 'a - b' exists or not.


### Helper variable template `has_subtraction_v`

```cpp
template< class T >
inline constexpr bool has_subtraction_v = has_subtraction<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_subtraction<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_subtraction_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_subtraction<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_subtraction_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_subtraction<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_subtraction_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_unary_plus`

```cpp
template<typename T>
struct has_unary_plus;
```

Checks if '+a' exists or not.


### Helper variable template `has_unary_plus_v`

```cpp
template< class T >
inline constexpr bool has_unary_plus_v = has_unary_plus<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_unary_plus<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_unary_plus_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_unary_plus<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_unary_plus_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_unary_plus<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_unary_plus_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_unary_minus`

```cpp
template<typename T>
struct has_unary_minus;
```

Checks if '-a' exists or not.


### Helper variable template `has_unary_minus_v`

```cpp
template< class T >
inline constexpr bool has_unary_minus_v = has_unary_minus<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_unary_minus<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_unary_minus_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_unary_minus<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_unary_minus_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_unary_minus<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_unary_minus_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_multiplication`

```cpp
template<typename T>
struct has_multiplication;
```

Checks if 'a*b' exists or not.


### Helper variable template `has_multiplication_v`

```cpp
template< class T >
inline constexpr bool has_multiplication_v = has_multiplication<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_multiplication<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_multiplication_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_multiplication<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_multiplication_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_multiplication<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_multiplication_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_division`

```cpp
template<typename T>
struct has_division;
```

Checks if 'a/b' exists or not.


### Helper variable template `has_division_v`

```cpp
template< class T >
inline constexpr bool has_division_v = has_division<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_division<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_division_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_division<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_division_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_division<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_division_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_modulo`

```cpp
template<typename T>
struct has_modulo;
```

Checks if 'a%b' exists or not.


### Helper variable template `has_modulo_v`

```cpp
template< class T >
inline constexpr bool has_modulo_v = has_modulo<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_modulo<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_modulo_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_modulo<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_modulo_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_modulo<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_modulo_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_prefix_increment`

```cpp
template<typename T>
struct has_prefix_increment;
```

Checks if '++a' exists or not.


### Helper variable template `has_prefix_increment_v`

```cpp
template< class T >
inline constexpr bool has_prefix_increment_v = has_prefix_increment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_prefix_increment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_prefix_increment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_prefix_increment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_prefix_increment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_prefix_increment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_prefix_increment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_postfix_increment`

```cpp
template<typename T>
struct has_postfix_increment;
```

Checks if 'a++' exists or not.


### Helper variable template `has_postfix_increment_v`

```cpp
template< class T >
inline constexpr bool has_postfix_increment_v = has_postfix_increment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_postfix_increment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_postfix_increment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_postfix_increment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_postfix_increment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_postfix_increment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_postfix_increment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_prefix_decrement`

```cpp
template<typename T>
struct has_prefix_decrement;
```

Checks if '--a' exists or not.


### Helper variable template `has_prefix_decrement_v`

```cpp
template< class T >
inline constexpr bool has_prefix_decrement_v = has_prefix_decrement<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_prefix_decrement<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_prefix_decrement_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_prefix_decrement<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_prefix_decrement_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_prefix_decrement<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_prefix_decrement_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_postfix_decrement`

```cpp
template<typename T>
struct has_postfix_decrement;
```

Checks if 'a--' exists or not.


### Helper variable template `has_postfix_decrement_v`

```cpp
template< class T >
inline constexpr bool has_postfix_decrement_v = has_postfix_decrement<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_postfix_decrement<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_postfix_decrement_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_postfix_decrement<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_postfix_decrement_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_postfix_decrement<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_postfix_decrement_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_equal_to`

```cpp
template<typename T>
struct has_equal_to;
```

Checks if 'a==b' exists or not.


### Helper variable template `has_equal_to_v`

```cpp
template< class T >
inline constexpr bool has_equal_to_v = has_equal_to<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_equal_to<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_equal_to_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_equal_to<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_equal_to_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_equal_to<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_equal_to_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_not_equal_to`

```cpp
template<typename T>
struct has_not_equal_to;
```

Checks if 'a!=b' exists or not.


### Helper variable template `has_not_equal_to_v`

```cpp
template< class T >
inline constexpr bool has_not_equal_to_v = has_not_equal_to<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_not_equal_to<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_not_equal_to_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_not_equal_to<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_not_equal_to_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_not_equal_to<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_not_equal_to_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_greater_than`

```cpp
template<typename T>
struct has_greater_than;
```

Checks if 'a>b' exists or not.


### Helper variable template `has_greater_than_v`

```cpp
template< class T >
inline constexpr bool has_greater_than_v = has_greater_than<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_greater_than<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_greater_than_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_greater_than<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_greater_than_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_greater_than<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_greater_than_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_less_than`

```cpp
template<typename T>
struct has_less_than;
```

Checks if 'a<b' exists or not.


### Helper variable template `has_less_than_v`

```cpp
template< class T >
inline constexpr bool has_less_than_v = has_less_than<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_less_than<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_less_than_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_less_than<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_less_than_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_less_than<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_less_than_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_greater_than_or_equal_to`

```cpp
template<typename T>
struct has_greater_than_or_equal_to;
```

Checks if 'a>=b' exists or not.


### Helper variable template `has_greater_than_or_equal_to_v`

```cpp
template< class T >
inline constexpr bool has_greater_than_or_equal_to_v = has_greater_than_or_equal_to<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_greater_than_or_equal_to<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_greater_than_or_equal_to_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_greater_than_or_equal_to<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_greater_than_or_equal_to_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_greater_than_or_equal_to<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_greater_than_or_equal_to_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_less_than_or_equal_to`

```cpp
template<typename T>
struct has_less_than_or_equal_to;
```

Checks if 'a<=b' exists or not.


### Helper variable template `has_less_than_or_equal_to_v`

```cpp
template< class T >
inline constexpr bool has_less_than_or_equal_to_v = has_less_than_or_equal_to<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_less_than_or_equal_to<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_less_than_or_equal_to_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_less_than_or_equal_to<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_less_than_or_equal_to_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_less_than_or_equal_to<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_less_than_or_equal_to_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_logical_not`

```cpp
template<typename T>
struct has_logical_not;
```

Checks if '!a' exists or not.


### Helper variable template `has_logical_not_v`

```cpp
template< class T >
inline constexpr bool has_logical_not_v = has_logical_not<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_logical_not<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_logical_not_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_logical_not<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_logical_not_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_logical_not<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_logical_not_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_logical_and`

```cpp
template<typename T>
struct has_logical_and;
```

Checks if 'a&&b' exists or not.


### Helper variable template `has_logical_and_v`

```cpp
template< class T >
inline constexpr bool has_logical_and_v = has_logical_and<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_logical_and<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_logical_and_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_logical_and<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_logical_and_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_logical_and<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_logical_and_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_logical_or`

```cpp
template<typename T>
struct has_logical_or;
```

Checks if 'a||b' exists or not.


### Helper variable template `has_logical_or_v`

```cpp
template< class T >
inline constexpr bool has_logical_or_v = has_logical_or<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_logical_or<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_logical_or_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_logical_or<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_logical_or_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_logical_or<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_logical_or_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_not`

```cpp
template<typename T>
struct has_bitwise_not;
```

Checks if '~a' exists or not.


### Helper variable template `has_bitwise_not_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_not_v = has_bitwise_not<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_not<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_not_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_not<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_not_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_not<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_not_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_and`

```cpp
template<typename T>
struct has_bitwise_and;
```

Checks if 'a&b' exists or not.


### Helper variable template `has_bitwise_and_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_and_v = has_bitwise_and<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_and<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_and_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_and<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_and_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_and<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_and_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_or`

```cpp
template<typename T>
struct has_bitwise_or;
```

Checks if 'a|b' exists or not.


### Helper variable template `has_bitwise_or_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_or_v = has_bitwise_or<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_or<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_or_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_or<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_or_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_or<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_or_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_xor`

```cpp
template<typename T>
struct has_bitwise_xor;
```

Checks if 'a^b' exists or not.


### Helper variable template `has_bitwise_xor_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_xor_v = has_bitwise_xor<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_xor<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_xor_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_xor<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_xor_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_xor<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_xor_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_left_shift`

```cpp
template<typename T>
struct has_bitwise_left_shift;
```

Checks if 'a<<N' exists or not.


### Helper variable template `has_bitwise_left_shift_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_left_shift_v = has_bitwise_left_shift<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_left_shift<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_left_shift_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_left_shift<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_left_shift_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_left_shift<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_left_shift_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_right_shift`

```cpp
template<typename T>
struct has_bitwise_right_shift;
```

Checks if 'a>>N' exists or not.


### Helper variable template `has_bitwise_right_shift_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_right_shift_v = has_bitwise_right_shift<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_right_shift<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_right_shift_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_right_shift<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_right_shift_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_right_shift<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_right_shift_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_addition_assignment`

```cpp
template<typename T>
struct has_addition_assignment;
```

Checks if 'a+=b' exists or not.


### Helper variable template `has_addition_assignment_v`

```cpp
template< class T >
inline constexpr bool has_addition_assignment_v = has_addition_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_addition_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_addition_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_addition_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_addition_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_addition_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_addition_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_subtraction_assignment`

```cpp
template<typename T>
struct has_subtraction_assignment;
```

Checks if 'a-=b' exists or not.


### Helper variable template `has_subtraction_assignment_v`

```cpp
template< class T >
inline constexpr bool has_subtraction_assignment_v = has_subtraction_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_subtraction_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_subtraction_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_subtraction_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_subtraction_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_subtraction_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_subtraction_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_multiplication_assignment`

```cpp
template<typename T>
struct has_multiplication_assignment;
```

Checks if 'a*=b' exists or not.


### Helper variable template `has_multiplication_assignment_v`

```cpp
template< class T >
inline constexpr bool has_multiplication_assignment_v = has_multiplication_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_multiplication_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_multiplication_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_multiplication_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_multiplication_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_multiplication_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_multiplication_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_division_assignment`

```cpp
template<typename T>
struct has_division_assignment;
```

Checks if 'a/=b' exists or not.


### Helper variable template `has_division_assignment_v`

```cpp
template< class T >
inline constexpr bool has_division_assignment_v = has_division_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_division_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_division_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_division_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_division_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_division_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_division_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_modulo_assignment`

```cpp
template<typename T>
struct has_modulo_assignment;
```

Checks if 'a%=b' exists or not.


### Helper variable template `has_modulo_assignment_v`

```cpp
template< class T >
inline constexpr bool has_modulo_assignment_v = has_modulo_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_modulo_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_modulo_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_modulo_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_modulo_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_modulo_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_modulo_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_and_assignment`

```cpp
template<typename T>
struct has_bitwise_and_assignment;
```

Checks if 'a&=b' exists or not.


### Helper variable template `has_bitwise_and_assignment_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_and_assignment_v = has_bitwise_and_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_and_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_and_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_and_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_and_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_and_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_and_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_or_assignment`

```cpp
template<typename T>
struct has_bitwise_or_assignment;
```

Checks if 'a|=b' exists or not.


### Helper variable template `has_bitwise_or_assignment_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_or_assignment_v = has_bitwise_or_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_or_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_or_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_or_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_or_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_or_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_or_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_leftshift_assignment`

```cpp
template<typename T>
struct has_bitwise_leftshift_assignment;
```

Checks if 'a<<=N' exists or not.


### Helper variable template `has_bitwise_leftshift_assignment_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_leftshift_assignment_v = has_bitwise_leftshift_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_leftshift_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_leftshift_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_leftshift_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_leftshift_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_leftshift_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_leftshift_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bitwise_rightshift_assignment`

```cpp
template<typename T>
struct has_bitwise_rightshift_assignment;
```

Checks if 'a>>=N' exists or not.


### Helper variable template `has_bitwise_rightshift_assignment_v`

```cpp
template< class T >
inline constexpr bool has_bitwise_rightshift_assignment_v = has_bitwise_rightshift_assignment<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bitwise_rightshift_assignment<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bitwise_rightshift_assignment_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bitwise_rightshift_assignment<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bitwise_rightshift_assignment_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bitwise_rightshift_assignment<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bitwise_rightshift_assignment_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_ostream`

```cpp
template<typename T>
struct has_ostream;
```

Checks if 'std::cout<<a' exists or not.


### Helper variable template `has_ostream_v`

```cpp
template< class T >
inline constexpr bool has_ostream_v = has_ostream<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_ostream<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_ostream_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_ostream<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_ostream_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_ostream<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_ostream_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_istream`

```cpp
template<typename T>
struct has_istream;
```

Checks if 'std::cin>>a' exists or not.


### Helper variable template `has_istream_v`

```cpp
template< class T >
inline constexpr bool has_istream_v = has_istream<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_istream<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_istream_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_istream<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_istream_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_istream<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_istream_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_bracket`

```cpp
template<typename T>
struct has_bracket;
```

Checks if 'a[N]' exists or not.


### Helper variable template `has_bracket_v`

```cpp
template< class T >
inline constexpr bool has_bracket_v = has_bracket<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_bracket<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_bracket_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_bracket<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_bracket_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_bracket<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_bracket_v<void(*)()> << std::endl;
	return 0;
}
```


## `has_const_bracket`

```cpp
template<typename T>
struct has_const_bracket;
```

Checks if 'auto const& a = xxx; a[N];' exists or not.


### Helper variable template `has_const_bracket_v`

```cpp
template< class T >
inline constexpr bool has_const_bracket_v = has_const_bracket<T>::value;
```


### Example

```cpp
#include "operator_traits.hpp"
#include <iostream>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "void: " << operator_traits::has_const_bracket<void>::value << std::endl;
	std::cout << "bool: " << operator_traits::has_const_bracket_v<bool> << std::endl;
	std::cout << "char: " << operator_traits::has_const_bracket<char>::value << std::endl;
	std::cout << "int: " << operator_traits::has_const_bracket_v<int> << std::endl;
	std::cout << "double: " << operator_traits::has_const_bracket<double>::value << std::endl;
	std::cout << "void(*)(): " << operator_traits::has_const_bracket_v<void(*)()> << std::endl;
	return 0;
}
```



