#include <iostream>
#include <utility>

class Animal
{
public:
    std::string name = "unknown";
    virtual void WelcomeVoice() = 0;
    virtual void ThreatVoice() = 0;
    virtual void ReactTo(Animal* animal) = 0;
    virtual std::string getName() = 0;
};

class Cat: public Animal
{
public:
    Cat() {
        name = "Cat";
    }
    void ReactTo(Animal* animal) override{
        if (this->getName() == animal->getName()) WelcomeVoice();
        else ThreatVoice();
    };
    void WelcomeVoice() override { std::cout << "Purr";}
    void ThreatVoice() override { std::cout << "Meow";}
    std::string getName() override{
        return name;
    }
};


class Dog: public Animal
{
public:
    Dog() {
        name = "Dog";
    }
    void ReactTo(Animal* animal) override{
        if (this->getName() == animal->getName()) WelcomeVoice();
        else ThreatVoice();
    };
    void WelcomeVoice() override { std::cout << "Woof";}
    void ThreatVoice() override { std::cout << "Bark";}
    std::string getName() override{
        return name;
    }
};


void Meeting(Animal* a, Animal* b)
{
    a->ReactTo(b);
    std::cout << " - ";
    b->ReactTo(a);
}

int main() {
    Animal* a = new Cat();
    Animal* b = new Dog();
    Meeting(a, b);

    return 0;
}
