/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:37:04 by gpinilla          #+#    #+#             */
/*   Updated: 2024/11/27 21:37:08 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;
class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		const int& getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(const AForm& form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
	
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif