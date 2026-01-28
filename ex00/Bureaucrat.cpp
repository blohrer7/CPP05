/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:31:40 by blohrer           #+#    #+#             */
/*   Updated: 2026/01/28 08:31:51 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :name(name), grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    this->grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
    std::cout<< "copy constructor called"<<std::endl;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this == &other)
        this->grade = other.grade;
    return *this;
}


Bureaucrat::~Bureaucrat(){}


const std::string& Bureaucrat::getName() const
{
    return(this->name);
}


int Bureaucrat::getGrade() const
{
    return(this->grade);
}


void Bureaucrat::incrementGrade()
{
    if(grade <= 1)
        throw GradeTooHighException();
    grade--;
}


void Bureaucrat::decrementGrade()
{
    if(grade >= 150)
        throw GradeTooLowException();
    grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade too high");
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade too low");
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
