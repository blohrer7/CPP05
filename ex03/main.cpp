/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:31:17 by blohrer           #+#    #+#             */
/*   Updated: 2026/03/25 10:04:48 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "===== TEST 1: Shrubbery =====" << std::endl;
    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form1)
    {
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    std::cout << "\n===== TEST 2: Robotomy =====" << std::endl;
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form2)
    {
        std::cout << *form2 << std::endl;
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    std::cout << "\n===== TEST 3: Presidential Pardon =====" << std::endl;
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form3)
    {
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    std::cout << "\n===== TEST 4: Invalid form =====" << std::endl;
    AForm* form4 = someRandomIntern.makeForm("coffee form", "Kitchen");
    if (form4)
        delete form4;

    return 0;
}
