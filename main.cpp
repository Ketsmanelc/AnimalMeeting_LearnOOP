#include <iostream>
class Animal
{
public:
    virtual void voice(Animal* meetAnimal) = 0;
};

class Cat: public Animal
{
public:
    void voice(Animal* meetAnimal)
    {
        if (this == meetAnimal) std::cout << "Purr";
        else std::cout<< "Meow";
    }
};

class Dog: public Animal
{
public:
    void voice(Animal* meetAnimal)
    {
        if (this == meetAnimal) std::cout << "Woof";
        else std::cout<< "Bark";
    }
};

void Meeting(Animal* a, Animal* b)
{
    a->voice(b);
    std::cout << " - ";
    b->voice(a);
}


int main() {
    Animal* b = new Cat();
    Animal* a = new Cat();
    Meeting(a, b);

    return 0;
}
