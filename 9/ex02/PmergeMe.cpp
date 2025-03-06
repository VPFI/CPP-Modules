/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:34 by vpf               #+#    #+#             */
/*   Updated: 2025/03/04 18:12:13 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    return ;
}

RPN::RPN(std::string const &stack) : _input(stack)
{
    return ;
}

RPN::RPN(RPN const &copy)
{
    *this = copy;

    return ;
}

RPN &RPN::operator = (RPN const &other)
{
    if (this != &other)
    {
        this->_input = other.getInput();
    }

    return (*this);
}

RPN::~RPN()
{
    return ;
}

const char *	RPN::WrongInput::what(void) const throw()
{
    return ("Error while computing | Probable missorder of operands");
}

bool    isNum(std::string &token)
{
    size_t  size = token.size();

    if (size == 0 || size > 10)
        return (false);
    
    for (size_t i = 0; i < size; i++)
    {
        char tokenChar = token.at(i);
        if (!isdigit(tokenChar) && tokenChar != '.' && !(i == 0 && (tokenChar == '-' || tokenChar == '+')))
            return (false);
    }

    return (true);
}

bool    isOperand(std::string &token, std::string *operands)
{
    for (int i = 0; i < 4; i++)
    {
        if (token == operands[i])
            return (true);
    }

    return (false);
}

std::string    RPN::getToken(size_t &pos, size_t &space) const
{
    std::string token;
    std::string operands[4] = {"+", "-", "/", "*"};

    if ((space = this->_input.find(' ', (pos = space + 1))) != std::string::npos)
    {
        token = this->_input.substr(pos, (space - pos));
        if (isNum(token) || isOperand(token, operands))
        {
            return (token);
        }
        else
        {
            throw(std::runtime_error("Invalid token passed"));
        }
    }
    token = this->_input.substr(pos);
    space = _input.size() - 1;
    
    return (token);
}

std::string	RPN::getInput() const
{
    return (this->_input);
}

static float  operate(float &lval, float &rval, std::string &operand)
{
    float       result;

    if (operand == "+")
    {
        result = lval + rval;
    }
    else if (operand == "-")
    {
        result = lval - rval;
    }
    else if (operand == "/")
    {
        result = lval / rval;
    }
    else if (operand == "*")
    {
        result = lval * rval;
    }
    else
        throw (std::runtime_error("Unknown operand"));

    return (result);
}

void    RPN::calculate()
{
    size_t              pos = 0;
    size_t              space = -1;
    float               lval;
    float               rval;
    std::string         token;
    std::string         operands[4] = {"+", "-", "/", "*"};
    std::stack<float>   stack;

    while (!(token = getToken(pos, space)).empty())
    {
        if (isOperand(token, operands))
        {
            if (stack.size() < 2)
                throw (RPN::WrongInput());
            rval = stack.top();
            stack.pop();
            lval = stack.top();
            stack.pop();
            stack.push(operate(lval, rval, token));
        }
        else
            stack.push(std::atof(token.c_str()));
    }
    if (stack.size() != 1)
        throw (RPN::WrongInput());
    std::cout << "Result: " << stack.top() << std::endl;

    return ;
}

