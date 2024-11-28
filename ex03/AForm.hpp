/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:33:11 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/25 00:56:55 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class AForm {
private:
    const std::string name;
    const int gradeToSign;
    const int gradeToExecute;
    bool isSigned;
    const std::string target;

protected:
    // Método puro virtual para implementar la acción específica en clases derivadas
    virtual void performAction() const = 0;

public:
    // Excepciones específicas de AForm
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        const char* what() const throw();
    };

    // Constructor y destructor
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    // Métodos
    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;

    // Operador de inserción
    friend std::ostream& operator<<(std::ostream& os, const AForm& form);
};

#endif
