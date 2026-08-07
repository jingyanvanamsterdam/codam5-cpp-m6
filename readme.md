## implicit: auto by compiler. 
int var = 10
float f = var;

## explicit: specified. 
int var = 10
float f = (float)var / 3

## four type casting
- static_cast -- resolved in compile-time; widening or narrowing numeric types.
- const_cast (change the states of const-ness. DO NOT USE)
- reinterpret_cast
- dynamic_cast -- used in polymorphic class; run-time check to ensure the conversion; if the conversion is not possible, return nullptr. 

## static member functoins
- assiociate with class, not instance of the class.


## compile time and run time

### lifecycle of the program.
- compile time: static
- run time: dynamic
🔍 Key Concepts in Both Worlds
1. Polymorphism (Static vs. Dynamic)
	- Compile Time (Static): The compiler looks at the argument types and explicitly links a function call to its definition before the program ever runs.
		Examples: Function Overloading, Operator Overloading, and Templates.
	- Run Time (Dynamic): The program resolves which function to call while running based on what object a pointer points to via a hidden look-up mechanism called a virtual table (vtable).
		Examples: Virtual Functions and Inheritance Function Overriding.

2. Evaluation & Optimization
	- Compile Time: Constants can be entirely pre-calculated by the compiler to save execution overhead. Modern C++ utilizes keywords like ```constexpr``` and ```consteval``` to force operations to compute while building.
		Example: constexpr int square(int x) { return x * x; } → int arr[square(5)]; 
		evaluates to a fixed size of 25 during compilation.
	- Run Time: Variables depend on outside sources and must be evaluated live on the fly.
		Example: Reading a value from std::cin and squaring it.

3. Errors & Catching Bugs
	- Compile-Time Errors: Syntax mistakes, missing semicolons, type mismatches, or failed template constraints (static_assert). If these happen, no executable file is generated.
	- Run-Time Errors: Code builds flawlessly, but fails during execution due to unexpected logic or system limits.Examples: Dividing a number by zero, null pointer dereferences, array out-of-bounds access, or running out of RAM.