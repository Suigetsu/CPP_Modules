/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/09 11:14:03 by mlagrini         ###   ########.fr       */
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
	std::stack<int>	nbrStack;
	int	i = 0;
	
	while (expression[i])
	{
		while (expression[i] == ' ')
			i++;
		if (std::isdigit(expression[i]))
		{
			std::string str;
			str[0] = expression[i];
			nbrStack.push(std::strtol(str.c_str(), NULL, 10));
		}
		else
		{
			if (!(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*'))
			{
				if (nbrStack.empty())
					throw (errorException());
				break ;
			}
			if (nbrStack.size() < 2)
				throw (errorException());
			int secondOperand = nbrStack.top();
			nbrStack.pop();
			int	firstOperand = nbrStack.top();
			nbrStack.pop();
			switch (expression[i])
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
		}
		i++;
	}
	if (nbrStack.size() != 1)
		throw (errorException());
	return (nbrStack.top());
}
