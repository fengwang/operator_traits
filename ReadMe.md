## <operator\_traits.hpp>

A single header file to heck if an [operator](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) defined or not.


### Type categories 


| type category  | function  | comment  |
|---|---|---|
|  [has_assignment](#has-assignment) | checks if `operato =(T const)` exist or not  |   |
|  [has_move_assignment](#has-move-assignment) | checks if `operator=(T&&)` exist or not  |   |
|  [has_addition](#has-addition) | checks if `T + T` exist or not  |   |
|   |   |   |

#### `has_addition`

```cpp
template<typename T>
struct has_addition;
```

Checks if 'auto operator + (T const&, T const&)' exists or not.


##### Helper variable template `has_addition_v`

```cpp
template< class T >
inline constexpr bool has_addition_v = has_addition<T>::value;
```


##### Example

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




#### `has_move_assignment`

```cpp
template<typename T, typename U> 
struct has_move_assignment;

template<typename T>
struct has_move_assignment;
```

Checks if `auto T::operator=(U&&)` or `auto T::operator=(T&&)` exist or not.

#####  Helper variable template `has_move_assignment_v` and `has_move_assignment_v2`

```cpp
template< class T >
inline constexpr bool has_move_assignment_v = has_move_assignment<T>::value;

template< class T, class U >
inline constexpr bool has_move_assignment_v2 = has_move_assignment<T, U>::value;
```

#### Example

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


#### `has_assignment`

```cpp
template<typename T, typename U> 
struct has_assignment;

template<typename T>
struct has_assignment;
```

Checks if `auto T::operator=(T const&)` or `auto T::operator=(T const&)` exist or not.

#####  Helper variable template `has_assignment_v` and `has_assignment_v2`

```cpp
template< class T >
inline constexpr bool has_assignment_v = has_assignment<T>::value;

template< class T, class U >
inline constexpr bool has_assignment_v2 = has_assignment<T, U>::value;
```

#### Example

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