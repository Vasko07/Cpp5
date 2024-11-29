/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:46:00 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:27 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor por defecto
Intern::Intern() {}

// Constructor de copia
Intern::Intern(const Intern& other) {
    (void)other;
}

// Operador de asignación
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Funciones para crear formularios
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Método makeForm
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        createShrubbery,
        createRobotomy,
        createPresidentialPardon
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: Form '" << formName << "' does not exist." << std::endl;
    return NULL;
}

