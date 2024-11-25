/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:33:11 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/25 00:56:55 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form();
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();
	Form& operator=(const Form &other);

	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;
	
	// Métodos
    void beSigned(const Bureaucrat& bureaucrat);

	// Excepciones
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
	
};

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif