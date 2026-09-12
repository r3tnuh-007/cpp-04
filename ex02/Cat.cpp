#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);  // Deep copy
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);  // Deep copy
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}
