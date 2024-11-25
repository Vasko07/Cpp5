/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:24 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/25 23:23:50 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat john("John", 1);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("robot");
    PresidentialPardonForm pardon("Alice");

    try {
        shrub.beSigned(john);
        john.executeForm(shrub);

        robot.beSigned(john);
        john.executeForm(robot);

        pardon.beSigned(john);
        john.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
