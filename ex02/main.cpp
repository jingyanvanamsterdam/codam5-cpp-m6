#include "Base.hpp"
#include <iostream>
#include <string>
#include <random>


Base* create_a()
{
	Base* a = new A();
	return a;
}

Base* create_b()
{
	Base* b = new B();
	return b;
}

Base* create_c()
{
	Base* c = new C();
	return c;
}

Base* generate(void)
{
	Base* (*farr[3])()= {create_a, create_b, create_c};
	
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> dist(0,2);
	int rdn = dist(rng);

	return farr[rdn]();
}

void	identify(Base* p)
{

	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "type is: A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "type is: B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "type is: C" << std::endl;
	else
		std::cout << "identify: unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "type r is: A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "type r is: B" << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "type r is: C" << std::endl;
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cout << "identify-r: unknown type" << std::endl;
			}
		}
		
	}
}

class Test : public Base {};

int main(void)
{
	for (int i = 0; i < 6; i++)
	{
		if (i < 5)
		{
			Base* test = generate();
			identify(test);
			identify(*test);
			delete test;
		}
		else
		{
			Base* unknow = new Test();
			identify(unknow);
			identify(*unknow);
			delete unknow;
		}
	}
}