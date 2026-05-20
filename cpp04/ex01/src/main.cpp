#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <stdexcept>

static void	testDeepCopy()
{
	std::cout << "\n--- Deep copy test ---" << std::endl;

	Dog original;
	original.getBrain()->setIdea(0, std::string("chase the cat"));

	Dog copy(original);
	copy.getBrain()->setIdea(0, std::string("sleep all day"));

	std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
}

static void	testAssignment()
{
	std::cout << "\n--- Assignment test ---" << std::endl;

	Cat a;
	a.getBrain()->setIdea(1, std::string("hunt birds"));

	Cat b;
	b = a;
	b.getBrain()->setIdea(1, std::string("eat fish"));

	std::cout << "a idea[1]: " << a.getBrain()->getIdea(1) << std::endl;
	std::cout << "b idea[1]: " << b.getBrain()->getIdea(1) << std::endl;
}

static void	testAnimalArray()
{
	std::cout << "\n--- Animal array test ---" << std::endl;

	const int	size = 4;
	Animal		*animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	for (int i = 0; i < size; i++)
		delete animals[i];
}

static void	testPolymorphism()
{
	std::cout << "\n--- Polymorphism: Animal vs WrongAnimal ---" << std::endl;

	const Animal		*cat = new Cat();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << "Cat:          "; cat->makeSound();
	std::cout << "WrongCat: "; wrongCat->makeSound();

	delete cat;
	delete wrongCat;
}

static void	testBrainException()
{
	std::cout << "\n--- Brain out-of-range exception test ---" << std::endl;

	Brain brain;
	try
	{
		brain.getIdea(200);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int	main()
{
	testDeepCopy();
	testAssignment();
	testAnimalArray();
	testPolymorphism();
	testBrainException();
	return 0;
}