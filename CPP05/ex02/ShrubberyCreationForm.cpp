/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:39:13 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/23 16:25:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("N/A")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
	*this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	int				i;
	std::fstream	file;
	std::string		filename;
	
	i = 0;
	isExecuted(executor);
	filename = this->target + "_Shrubbery";
	file.open(filename, std::ios::out);
	while (i < 3)
	{
		file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
		file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
		file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
		file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
		file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
		file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
		file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
		file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
		file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
		file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
		file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
		file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
		file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
		file << "             {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
		file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
		file << "               (_)  \\.-'.-/" << std::endl;
		file << "          __...--- |'-.-'| --...__" << std::endl;
		file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
		file << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
		file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
		file << "          ' ..     |'-_.-|" << std::endl;
		file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
		file << "              .'   |'- .-|   '." << std::endl;
		file << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
		file << "   .-' '        '-._______.-'     '  ." << std::endl;
		file << "        .      ~," << std::endl;
		file << "    .       .   |\\   .    ' '-." << std::endl;
		file << "    ___________/  \\____________" << std::endl;
		file << "   /  Why is it, when you want \\" << std::endl;
		file << "  |  something, it is so damn   |" << std::endl;
		file << "  |    much work to get it?     |" << std::endl;
		file << "   \\___________________________/" << std::endl << std::endl;
		i++;
	}
	file.close();
	std::cout << filename << " has been created." << std::endl;
}
