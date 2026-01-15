/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:31:17 by blohrer           #+#    #+#             */
/*   Updated: 2026/01/15 10:23:32 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    // TEST 1: Valid Bureaucrat
    try
    {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        b1.incrementGrade();       // 42 -> 41
        std::cout << b1 << std::endl;

        b1.decrementGrade();       // 41 -> 42
        std::cout << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------\n";

    // TEST 2: Grade too HIGH in constructor
    try
    {
        Bureaucrat b2("Bob", 0);   // Ungültig -> Exception
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------\n";

    // TEST 3: Grade too LOW in constructor
    try
    {
        Bureaucrat b3("Charlie", 200); // Ungültig -> Exception
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------\n";

    // TEST 4: incrementGrade() throws exception
    try
    {
        Bureaucrat b4("Diana", 1);
        std::cout << b4 << std::endl;

        b4.incrementGrade();  // Soll Exception werfen
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------\n";

    // TEST 5: decrementGrade() throws exception
    try
    {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;

        b5.decrementGrade(); // Soll Exception werfen
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
