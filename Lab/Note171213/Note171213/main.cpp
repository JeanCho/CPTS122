#include <iostream>

class LivingThing {
protected:
	void breathe() {
		std::cout << "I'm breathing as a living thing." << std::endl;
	}
};

class Animal : protected LivingThing {
protected:
	void breathe() {
		std::cout << "I'm breathing as an animal." << std::endl;
	}
};

class Reptile : protected LivingThing {
protected:
	void crawl() {
		std::cout << "I'm crawling as a reptile." << std::endl;
	}
};

class Snake : protected Animal, protected Reptile {
public:
	void breathe() {
		std::cout << "i'm breathing as a snake." << std::endl;
	}

	void crawl() {
		std::cout << "i'm crawling as a snake." << std::endl;
	}
};

int main() {
	Snake snake;
	

	snake.breathe();
	snake.crawl();
	

	return 0;
}