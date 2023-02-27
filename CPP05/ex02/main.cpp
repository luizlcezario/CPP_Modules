/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:21:44 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 15:47:39 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_ex00(void) {
  std::cout << "/***********************************/" << std::endl;
  std::cout << "TEST EX00" << std::endl;
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
  std::cout << "/***********************************/" << std::endl;
}

void test_ex01(void) {
  std::cout << "TEST EX01" << std::endl;

  Bureaucrat  b1("CO", 1);
  Bureaucrat  b2("Estagiario", 150);
  Bureaucrat  b3("Pleno", 90);
  Form        f1("Corrupcao", 1, 1);
  Form        f2("novo projeto", 90, 90);
  
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;
  
  try {
    b3.signForm(f1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b2.signForm(f1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b1.signForm(f1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b3.signForm(f2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b2.signForm(f2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b1.signForm(f2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "/***********************************/" << std::endl;
}

int main(void) {
  test_ex00();
  test_ex01();
  return (0);
}