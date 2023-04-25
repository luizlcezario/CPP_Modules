

#include "RPN.hpp"

RPN::RPN(/* args */) : _expression(""), _stack()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &op)
{
	if (this == &op)
		return (*this);
	_expression = op.get_expression();
	return (*this);
}

RPN::RPN(std::string expression) : _expression(expression), _stack()
{
}

std::string RPN::get_expression(void) const{
	return (_expression);
}

static double performOperation(char op, double operand1, double operand2) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw std::runtime_error("Erro: divisão por zero"); 
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Erro: operador inválido"); 
    }
}

static void removeSpaces(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

double RPN::calculate(void) {
	removeSpaces(_expression);
     for (size_t i = 0; i < _expression.length(); i++)  {
        if (isdigit(_expression[i])) {
            _stack.push(_expression[i] - '0');
        } else if(_expression[i] == '+' || _expression[i] == '-' || _expression[i] == '*' || _expression[i] == '/') {
            if (_stack.size() < 2) {
                throw std::runtime_error("Erro: operandos insuficientes");
            }
            double operand2 = _stack.top();
            _stack.pop();
            double operand1 = _stack.top();
            _stack.pop();
            double result = performOperation(_expression[i], operand1, operand2);
            _stack.push(result);
        } else {
            throw std::runtime_error("Erro: caractere inválido");
        }
    }
    if (_stack.size() != 1) {
        throw std::runtime_error("Erro: expressão inválida"); 
    }
    return _stack.top();
}
