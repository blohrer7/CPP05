/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:50:44 by blohrer           #+#    #+#             */
/*   Updated: 2026/01/28 15:07:11 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name,int gradeToSign, int gradeToExecute)
	:name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150)
		throw GradeTooLowException();
	if(gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm(){}

const std::string& AForm::getName() const
{
	return(this->name);
}

bool AForm::getIsSigned() const
{
	return(this->isSigned);
}

int AForm::getGradeToSign() const
{
	return(this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return(this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed";
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (this->isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();

	this->executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName()
		<< " [signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", gradeToSign: " << f.getGradeToSign()
		<< ", gradeToExecute: " << f.getGradeToExecute() << "]";
	return os;
}
