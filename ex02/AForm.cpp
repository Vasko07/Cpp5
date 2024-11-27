/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:33:08 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/26 17:42:20 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Constructor de copia
AForm::AForm(const AForm& other)
    : name(other.name),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute),
      isSigned(other.isSigned),
      target(other.target) {}

// Operador de asignación
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }
const std::string& AForm::getTarget() const { return target; }

// Método beSigned
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// Método execute
void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
    performAction();
}

// Excepciones
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

// Operador de inserción
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form name: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Target: " << form.getTarget();
    return os;
}
