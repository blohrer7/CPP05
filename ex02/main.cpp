/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:31:17 by blohrer           #+#    #+#             */
/*   Updated: 2026/03/09 11:20:01 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    std::cout << "===== TEST 1: Shrubbery not signed =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("home");

        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Shrubbery signed and executed =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
        std::cout << shrub << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Shrubbery sign works, execute fails =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 140);
        ShrubberyCreationForm shrub("park");

        std::cout << alice << std::endl;
        std::cout << shrub << std::endl;
        alice.signForm(shrub);
        alice.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Robotomy success/fail =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 1);
        RobotomyRequestForm robot("Marvin");

        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Presidential pardon =====" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur");

        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: Sign fails because grade too low =====" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << intern << std::endl;
        std::cout << pardon << std::endl;
        intern.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 7: Execute fails because grade too low =====" << std::endl;
    try
    {
        Bureaucrat mid("Mid", 20);
        PresidentialPardonForm pardon("Trillian");

        std::cout << mid << std::endl;
        std::cout << pardon << std::endl;
        mid.signForm(pardon);
        mid.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}