/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:21:44 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 16:26:32 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  Animal *meta[10];
  for (int i = 0; i < 10; i++) {
    if (i < 5)
      meta[i] = new Dog();
    else
      meta[i] = new Cat();
  }
  for (int i = 0; i < 10; i++) {
    std::cout << *meta[i] << ": ";
    meta[i]->makeSound();
    delete meta[i];
  }
  Dog *j = new Dog();
  std::string think= "I am a dog";
  j->getBrain()->addNewThinking(think);
  std::cout << *j->getBrain() << std::endl;
  return (0);
}