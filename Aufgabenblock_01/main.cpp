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
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include "math.h"
using namespace std;

void vAufgabe_1a();
void v_Aufgabe_2();
void vAufgabe_3();
void vAufgabe_AB1();

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





	//vAufgabe_1a();
	//v_Aufgabe_2();
	vAufgabe_3();
	//vAufgabe_AB1();
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

void v_Aufgabe_2() {
    int nPKW, nFahrrad;
    std::cout << "Bitte geben Sie die Anzahl der zu erzeugenden PKWs ein: ";
    std::cin >> nPKW;
    std::cout << "Bitte geben Sie die Anzahl der zu erzeugenden Fahrräder ein: ";
    std::cin >> nFahrrad;

    // Vector zur Verwaltung der Fahrzeuge
    std::vector<std::unique_ptr<Fahrzeug>> vecFahrzeuge;

    // PKW-Objekte erstellen und zum Vector hinzufügen
    for (int i = 0; i < nPKW; ++i) {
        std::string name;
        double maxGeschwindigkeit;
        std::cout << "Geben Sie den Namen des PKW " << (i + 1) << " ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die maximale Geschwindigkeit des PKW " << (i + 1) << " ein: ";
        std::cin >> maxGeschwindigkeit;
        double verbrauch;
        std::cout << "Geben Sie den Verbrauch des PKW " << (i + 1) << " ein: ";
        std::cin >> verbrauch;
        vecFahrzeuge.push_back(std::make_unique<PKW>(name, maxGeschwindigkeit, verbrauch));
    }

    // Fahrrad-Objekte erstellen und zum Vector hinzufügen
    for (int i = 0; i < nFahrrad; ++i) {
        std::string name;
        double maxGeschwindigkeit;
        std::cout << "Geben Sie den Namen des Fahrrads " << (i + 1) << " ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die maximale Geschwindigkeit des Fahrrads " << (i + 1) << " ein: ";
        std::cin >> maxGeschwindigkeit;
        vecFahrzeuge.push_back(std::make_unique<Fahrrad>(name, maxGeschwindigkeit));
    }

    // Simulationsschritte durchführen
    double dGlobaleZeit = 0.0;
    double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 3.0; // Gesamt-Simulationsdauer in Stunden

    while (dGlobaleZeit < dSimulationsdauer) {
        dGlobaleZeit += dZeittakt;
        std::cout << "\nSimulation zur Zeit: " << dGlobaleZeit << " Stunden\n";
        for (auto& fahrzeug : vecFahrzeuge) {
            fahrzeug->vSimulieren();
            std::cout << *fahrzeug << "\n"; // Ausgabe mit überladenem Operator <<
        }

        // Nach genau 3 Stunden die PKWs volltanken
        if (dGlobaleZeit >= 3.0) {
            for (auto& fahrzeug : vecFahrzeuge) {
                if (auto pkw = dynamic_cast<PKW*>(fahrzeug.get())) {
                    pkw->dTanken(0.0); // Volltanken
                }
            }
        }
    }
}

void vAufgabe_3() {
    // Fahrzeuge simulieren
        double dZeittakt = 0.5; // Zeittakt in Stunden
    double dSimulationsdauer = 3.0; // Gesamt-Simulationsdauer in Stunden

    PKW pkw1("Audi", 150, 8.0);
    PKW pkw2("BMW", 180, 9.0);

    while (dGlobaleZeit < dSimulationsdauer) {
        dGlobaleZeit += dZeittakt;
        pkw1.vSimulieren();
        pkw2.vSimulieren();
    }

    // Vergleich der Fahrzeuge basierend auf der Gesamtstrecke
    if (pkw1 < pkw2) {
        std::cout << pkw1.getName() << " hat eine geringere Gesamtstrecke als " << pkw2.getName() << "." << std::endl;
    } else if (pkw2 < pkw1) {
        std::cout << pkw2.getName() << " hat eine geringere Gesamtstrecke als " << pkw1.getName() << "." << std::endl;
    } else {
        std::cout << pkw1.getName() << " und " << pkw2.getName() << " haben die gleiche Gesamtstrecke." << std::endl;
    }
}





/*
double dEpsilon = 0.001;
void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{15};
    double dTakt = 0.3;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 217, 10.7));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 21.4));
    for (dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}
*/
