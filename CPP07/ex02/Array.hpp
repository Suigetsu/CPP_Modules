/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:47:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/06 14:03:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class OutOfBoundException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("The index is out of bound.");
		}
};

template <typename T>
class	Array
{
	private:
		T *array;
		unsigned int n;
	public:
		Array(){
			this->array = NULL;
			this->n = 0;
		}
		Array(unsigned int n){
			this->n = n;
			this->array = new T[this->n];
		}
		Array(const T &obj){
			*this = obj;
		}
		T	&operator=(const T &obj){
			if (*this != obj)
			{
				delete []this->array;
				this->array = obj.array;
				this->n = obj.n;
			}
			return (*this);
		}
		~Array(){
			delete []this->array;
		}
		const T	&operator[](int index){
			if (index > this->n || index < this->n)
				throw (OutOfBoundException());
			return (T[index]);
		}
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> obj)
{
	out = obj;
	return (out);
}

#endif
