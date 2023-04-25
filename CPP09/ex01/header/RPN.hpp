
#ifndef RNP_HPP
# define RNP_HPP

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
class RPN
{
private:
	std::string _expression;
	std::stack <double> _stack;
public:
	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &op);
	explicit RPN(std::string expression);
	std::string get_expression(void) const;
	double calculate(void);
};
#endif