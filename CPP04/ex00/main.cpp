/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:21:44 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 14:19:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  const WrongAnimal *wrongMeta = new WrongAnimal();
  const WrongAnimal *k = new WrongCat();
  const WrongCat *l = new WrongCat();

  std::cout << "\n";

  std::cout << *j << ": ";
  j->makeSound();  // will output the cat sound!

  std::cout << *i << ": ";
  i->makeSound();  // will output the dog sound!

  std::cout << *meta << ": ";
  meta->makeSound();  // will output the animal sound!

  std::cout << "\n";

  std::cout << *wrongMeta << ": ";
  wrongMeta->makeSound();  // will output the wrong animal sound!

  std::cout << *k << ":  ";
  k->makeSound();  // will output the wrong cat sound!

  std::cout << *l << "2: ";
  l->makeSound();  // will output the wrong cat original sound!

  std::cout << "\n";

  delete meta;
  delete j;
  delete i;

  delete wrongMeta;
  delete k;
  delete l;

  std::cout << "\n";
  return (0);
}