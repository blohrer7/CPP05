/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:31:17 by blohrer           #+#    #+#             */
/*   Updated: 2026/01/28 15:10:26 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "=== TEST 1: Valid AForm creation ===" << std::endl;
    try
    {
        AForm f1("TaxForm", 50, 20);
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: AForm with invalid grades ===" << std::endl;
    try
    {
        AForm f2("InvalidForm", 0, 10); // grade too high
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        AForm f3("InvalidForm2", 10, 200); // grade too low
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Successful signing ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        AForm f4("Permit", 50, 30);

        std::cout << alice << std::endl;
        std::cout << f4 << std::endl;

        alice.signForm(f4); // should succeed
        std::cout << f4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Failed signing (grade too low) ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        AForm f5("SecretForm", 50, 10);

        std::cout << bob << std::endl;
        std::cout << f5 << std::endl;

        bob.signForm(f5); // should fail
        std::cout << f5 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Direct beSigned() test ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        AForm f6("TopSecret", 1, 1);

        f6.beSigned(boss);
        std::cout << "AForm signed directly." << std::endl;
        std::cout << f6 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
