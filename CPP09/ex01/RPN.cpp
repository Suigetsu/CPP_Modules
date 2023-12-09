/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/09 11:10:55 by mlagrini         ###   ########.fr       */
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

// int	RPN::calculateRPN(char *av)
// {
// 	std::stack<int> nbrStack;
// 	int i = 0;
// 	int num;
	
// 	while (av[i])
// 	{
// 		std::istringstream iss(av[i]);
// 		while (iss >> num || !iss.eof())
// 		{
// 			std::cout << "debug" << std::endl;
// 			if (iss.fail() || num > 9 || num < 0)
// 			{
// 				if (!(av[i] == '+' || av[i] == '-' || av[i] == '/' || av[i] == '*'))
// 					throw (errorException());
// 				if (nbrStack.size() != 2)
// 				throw (errorException());
// 				int secondOperand = nbrStack.top();
// 				nbrStack.pop();
// 				int	firstOperand = nbrStack.top();
// 				nbrStack.pop();
// 				switch (av[i])
// 				{
// 					case '+':
// 						nbrStack.push(firstOperand + secondOperand);
// 						break;
// 					case '-':
// 						nbrStack.push(firstOperand - secondOperand);
// 						break;
// 					case '*':
// 						nbrStack.push(firstOperand * secondOperand);
// 						break;
// 						case '/':
// 						nbrStack.push(firstOperand / secondOperand);
// 						break;
// 					default:
// 						break;
// 				}
// 			}
// 			nbrStack.push(num);
// 		}
// 		i++;
// 	}
// 	return (nbrStack.top());
// }

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

// int	RPN::calculateRPN(std::string expression)
// {
// 	std::string		token;
// 	std::stack<int>	nbrStack;

// 	while (!expression.empty())
// 	{ 
// 		token = expression.substr(0, expression.find(" "));
// 		if (token.empty() || token.size() != 1)
// 			throw (errorException());
// 		if (std::isdigit(token[0]))
// 			nbrStack.push(std::strtol(token.c_str(), NULL, 10));
// 		else
// 		{
// 			if (!(token == "+" || token == "-" || token == "/" || token == "*"))
// 				throw (errorException());
// 			if (nbrStack.size() < 2)
// 				throw (errorException());
// 			int secondOperand = nbrStack.top();
// 			nbrStack.pop();
// 			int	firstOperand = nbrStack.top();
// 			nbrStack.pop();
// 			switch (token[0])
// 			{
// 				case '+':
// 					nbrStack.push(firstOperand + secondOperand);
// 					break;
// 				case '-':
// 					nbrStack.push(firstOperand - secondOperand);
// 					break;
// 				case '*':
// 					nbrStack.push(firstOperand * secondOperand);
// 					break;
// 					case '/':
// 					nbrStack.push(firstOperand / secondOperand);
// 					break;
// 				default:
// 					break;
// 			}
// 			if (expression.find(" ") > 1)
// 				break ;
// 		}
// 		if (expression.find(" ") > 1)
// 			break ;
// 		expression.erase(0, expression.find(" ") + 1);
// 	}
// 	// if (nbrStack.size() != 1)
// 	// 	throw (errorException());
// 	return (nbrStack.top());
// }
