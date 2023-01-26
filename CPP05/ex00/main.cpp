/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:21:44 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 14:57:05 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat b2;
  Bureaucrat b1("Bureaucrat1", 1);
  b2 = b1;
  Bureaucrat b3("Bureaucrat3", 140);
  Bureaucrat b4("Bureaucrat4", 150);
  
  std::cout << b1 << std::endl << b2 << std::endl << b3 << std::endl;
  b2.decrementGrade();
  b3.incrementGrade();
  std::cout << b1 << std::endl << b2 << std::endl << b3 << std::endl;
  try {
    b1.incrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b4.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}