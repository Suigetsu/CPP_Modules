/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/21 16:33:30 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *errorException::what() const throw()
{
	return ("Error");
}

RPN::~RPN()
{
	
}
int	RPN::calculateRPN(std::string expression)
{
	std::string		token;
	std::stack<int>	nbrStack;

	while (!expression.empty())
	{
		token = expression.substr(0, expression.find(" "));
		if (token.empty() || token.size() != 1)
			throw (errorException());
		if (std::isdigit(token[0]))
			nbrStack.push(std::strtol(token.c_str(), NULL, 10));
		else
		{
			if (!(token == "+" || token == "-" || token == "/" || token == "*"))
				throw (errorException());
			int secondOperand = nbrStack.top();
			nbrStack.pop();
			int	firstOperand = nbrStack.top();
			nbrStack.pop();
			switch (token[0])
			{
				case '+':
					nbrStack.push(firstOperand + secondOperand);
					break;
				case '-':
					nbrStack.push(firstOperand - secondOperand);
					break;
				case '*':
					nbrStack.push(firstOperand * secondOperand);
					break;
					case '/':
					nbrStack.push(firstOperand / secondOperand);
					break;
				default:
					break;
			}
			if (expression.find(" ") > 1)
				break ;
		}
		expression.erase(0, expression.find(" ") + 1);
	}
	return (nbrStack.top());
}
