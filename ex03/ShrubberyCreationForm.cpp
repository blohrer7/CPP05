/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:13:47 by blohrer           #+#    #+#             */
/*   Updated: 2026/03/09 09:06:57 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((target + "_shrubbery").c_str());

    if (!file)
        return;

    file << "       _-_       " << std::endl;
    file << "    /~~   ~~\\    " << std::endl;
    file << " /~~         ~~\\ " << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  / " << std::endl;
    file << "   ~  \\\\ //  ~   " << std::endl;
    file << "_- -   | | _- _  " << std::endl;
    file << "  _ -  | |   -_  " << std::endl;
    file << "      // \\\\      " << std::endl;
}

