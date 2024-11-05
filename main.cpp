/*
 * main.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <memory>
#include <vector>

void vAufgabe_1a();

int main()
{
	/*
	Fahrzeug Auto1("Jonas");
	Fahrzeug* Auto2 = new Fahrzeug;
	delete Auto2;

	std::unique_ptr<Fahrzeug> Auto3 = std::make_unique<Fahrzeug>("Jonas", 90);
	std::shared_ptr<Fahrzeug> Auto4 = std::make_shared<Fahrzeug>("Emily", 80);
	std::cout << Auto4.use_count() << std::endl;
	std::shared_ptr<Fahrzeug> Auto5 = Auto4;
	std::cout << Auto5.use_count() << std::endl;
	std::vector<std::unique_ptr<Fahrzeug>> vektor;

	for(int i = 0; i<5; ++i)
	{
		dGlobaleZeit += 1.5;
		Auto3->vSimulieren();
		Auto3->vSimulieren();
	}

	Fahrzeug::vKopf();
	Auto3->vAusgeben();
	std::cout << std::endl;
	Auto4->vAusgeben();
	std::cout << std::endl;
	*/
	vAufgabe_1a();
	return 0;

}

void vAufgabe_1a()
{
	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
	int choice;
	std::string newName;
	double maxSpeed;
	double verbrauch;
	double zeit = 1.0;
	int simulationsSchritte = 5;

	while(true)
	{
	//Menüerstellung
	std::cout << " Willkommen im Menue, was wollen sie machen?: " << std::endl << "(1) Neues Fahrzeug erstellen" << std::endl
																<< "(2) Globale Zeitschritte und Anzahl der Simulationsschritte setzten (default: 1.0 und 5)" << std::endl
																<< "(3) Simuliere alle Fahrzeuge" << std::endl
																<< "(4) Fuelle die Liste mit 4 Fahrzeugen"
																<< std::endl << "(0) Menu beenden" << std::endl;
	std::cin >> choice;

	switch(choice)
	{
	case 1:
		std::cout << "Wie soll ihr Fahrzeug heissen?" << std::endl;
		std::cin >> newName;
		std::cout << "Wie schnell kann das Fahrzeug fahren?" << std::endl;
		std::cin >> maxSpeed;
		std::cout << "Wie viel verbraucht das Fahrzeug?" << std::endl;
		std::cin >> verbrauch;

		fahrzeuge.push_back(std::make_unique<PKW>(newName, maxSpeed, verbrauch));
	break;

	case 2:
		std::cout << "In welchen Schritten soll die Globale Zeit erhoehr werden?" << std::endl;
		std::cin >> zeit; //Zeit wie viel die Globale Uhr pro Simulationsschritt erhöhr wird
		std::cout << "Wie oft soll Simuliert werden?" << std::endl;
		std::cin >> simulationsSchritte; //Anzahl wie viele Simulationsschritte durchgeführt werden sollen
	break;

	case 3:
		if(fahrzeuge.empty() == false)
		{
			std::cout << "Simulation wird ausgefuehrt" << std::endl;
			for(int i=1; i <= simulationsSchritte; ++i)
			{
				dGlobaleZeit += zeit;
				std::cout << std::endl;
				PKW::vKopf();
				std::cout << std::endl << "---------------------------------------------------------------------------------------------------------" << std::endl;
				for(auto& fahrzeug : fahrzeuge)
				{
					fahrzeug->vSimulieren();
					std::cout << *fahrzeug << std::endl;
					std::cout << std::endl;
				}
			}
		}
			else
			{
				std::cout << "Keine Fahrzeuge im Vektor vorhanden" << std::endl;
			}
		break;

	case 4:
		fahrzeuge.push_back(std::make_unique<PKW>("BMW", 130, 10));
		fahrzeuge.push_back(std::make_unique<PKW>("Audi", 190, 15));
		fahrzeuge.push_back(std::make_unique<PKW>("Mercedes", 60, 12));
		fahrzeuge.push_back(std::make_unique<PKW>("Renault", 10, 5));
		fahrzeuge.push_back(std::make_unique<Fahrrad>("Cube", 25));
		fahrzeuge.push_back(std::make_unique<Fahrrad>("HollandRad", 23));
	break;

	case 0:
		std::cout << "Programm wird beendet..." << std::endl;
		return;
	break;

	default:
		std::cout << "ungueltige eingabe" << std::endl;
	break;
	}
	}
}
