/*
 * main.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */
#include "Fahrzeug.h"
#include <memory>
#include <vector>

int main()
{
	Fahrzeug Auto1("Jonas");
	Fahrzeug* Auto2 = new Fahrzeug;
	delete Auto2;

	std::unique_ptr<Fahrzeug> Auto3 = std::make_unique<Fahrzeug>();
	std::shared_ptr<Fahrzeug> Auto4 = std::make_shared<Fahrzeug>();
	std::cout << Auto4.use_count() << std::endl;
	std::shared_ptr<Fahrzeug> Auto5 = Auto4;
	std::cout << Auto5.use_count() << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vektor;


	return 0;
}



