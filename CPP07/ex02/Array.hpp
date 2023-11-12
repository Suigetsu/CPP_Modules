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
# include <cstdlib>

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
		Array(const Array &obj) : n(obj.n){
			this->array = new T[obj.n];
			std::copy(obj.array, obj.array + n, array);
		}
		Array	&operator=(const Array &obj){
			if (this != &obj)
			{
				delete []this->array;
				this->array = new T[obj.n];
				for (int i = 0; i < obj.n; ++i)
					this->array[i] = obj.array[i];
				this->n = obj.n;
			}
			return (*this);
		}
		~Array(){
			delete []this->array;
		}
		T	&operator[](unsigned int index){
			if (index >= this->n)
				throw (OutOfBoundException());
			return (this->array[index]);
		}
		unsigned int	size(){
			return (this->n);
		}
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> obj)
{
	out = obj;
	return (out);
}

#endif
