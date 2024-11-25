/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:24 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/25 00:45:16 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form taxForm("Tax Form", 40, 30);

        std::cout << taxForm << std::endl;
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat boss("Boss", 10);
        boss.signForm(taxForm);
        std::cout << taxForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

