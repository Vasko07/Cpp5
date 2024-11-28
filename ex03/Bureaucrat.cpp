/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:56:58 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/27 21:39:46 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Unamed"), grade(150) {
	std::cout << "Deafault contrusctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name (name) {
	if (grade < 1) throw GradeTooLowException();
	else if (grade > 150) throw GradeTooHighException();
	else this->grade = grade;
	std::cout << "Complete constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) this->grade = other.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Copy Contructor Called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return (this->name);
}

const int& Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1) throw GradeTooHighException();
	else this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150) throw GradeTooHighException();
	else this->grade++;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << ".\n";
    } catch (std::exception& e) {
        std::cout << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << ".\n";
    }
}


const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is to low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is to high!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}