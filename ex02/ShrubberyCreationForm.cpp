/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:23:13 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/25 23:33:05 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const {
    std::ofstream outFile(getTarget() + "_shrubbery");
    if (outFile.is_open()) {
        outFile << "       _-_       \n";
        outFile << "    /~~   ~~\\    \n";
        outFile << " /~~         ~~\\ \n";
        outFile << "{               }\n";
        outFile << " \\  _-     -_  / \n";
        outFile << "   ~  \\\\ //  ~   \n";
        outFile << "_- -   | | _- _  \n";
        outFile << "  _ -  | |   -_  \n";
        outFile << "      // \\\\      \n";
        outFile.close();
    }
}
