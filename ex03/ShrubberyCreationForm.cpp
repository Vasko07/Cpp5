/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:23:13 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:07 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

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
    std::ofstream outFile((getTarget() + "_shrubbery").c_str()); // Convertir a const char*
    if (!outFile) {
        std::cout << "Error: Could not open file for writing." << std::endl;
        return;
    }

    outFile <<
        "         &&& &&  & &&\n"
        "      && &\\/&\\|& ()|/ @, &&\n"
        "      &\\/(/&/&||/& /_/)_&/_&\n"
        "   &() &\\/&|()|/&\\/ '%\" & ()\n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "&&   && & &| &| /& & % ()& /&&\n"
        "   ()&_---()&\\&\\|&&-&&--%---()~\n"
        "            &&     \\|||\n"
        "                      |||\n"
        "                      |||\n"
        "                      |||\n"
        "                , -=-~  .-^- _\n";

    outFile.close();
    std::cout << "Shrubbery has been created successfully in " << getTarget() << "_shrubbery" << std::endl;
}
