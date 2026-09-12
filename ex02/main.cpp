#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Array of Animals ===" << std::endl;
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Making Sounds ===" << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I love bones");

    Dog dog2 = dog1;  // Copy constructor
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "I love toys");
    std::cout << "After modification:" << std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "I love fish");

    Cat cat2;
    cat2 = cat1;  // Assignment operator
    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
