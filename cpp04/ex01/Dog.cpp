/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 15:23:27 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain) {
    type = "Dog";
    std::cout << "Constructor Dog Default" << std::endl;

}
Dog::Dog(const Dog& other) {
    *this = other;
    std::cout << "Constructor copy Dog" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        if (brain)
        {
            delete brain; // Supprime l'ancien brain
            brain = NULL;
        }
        brain = newBrain; // Utilise le nouveau
    }
    return (*this);
}
Dog::~Dog() {
    delete brain;
    std::cout << "Destructor Dog" << std::endl; 
}
void Dog::makeSound() const{
    std::cout << "Woof" << std::endl;
}