/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:24 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/23 16:15:20 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.decrementGrade(); // Intento válido
        std::cout << b1 << std::endl;

        b2.incrementGrade(); // Intento válido
        std::cout << b2 << std::endl;

        b1.incrementGrade(); // Esto lanzará una excepción
		b1.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
