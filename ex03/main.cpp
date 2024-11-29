/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:24 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:27 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat john("John", 1);

    // Crear formularios válidos
    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "garden");
    AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
    AForm* pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");

    // Intentar ejecutar los formularios
    try {
        john.signForm(*shrubberyForm);
        john.executeForm(*shrubberyForm);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        john.signForm(*robotomyForm);
        john.executeForm(*robotomyForm);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        john.signForm(*pardonForm);
        john.executeForm(*pardonForm);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Intentar crear un formulario inválido
    AForm* invalidForm = intern.makeForm("unknown form", "target");

    // Liberar memoria
    delete shrubberyForm;
    delete robotomyForm;
    delete pardonForm;
    delete invalidForm;

    return 0;
}

