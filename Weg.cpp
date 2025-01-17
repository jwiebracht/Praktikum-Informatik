/*
 * Weg.cpp
 *
 *  Created on: 17.01.2025
 *      Author: jonas
 */

#include "Weg.h"

Weg::Weg() : Simulationsobjekt("")
{

}

Weg::Weg(std::string p_sName, double p_dLaenge, p_eTempolimit limit) : Simulationsobjekt(p_sName), p_dLaenge(p_dLaenge), tempolimit(limit){

}

Weg::Weg(std::string p_sName, double p_dLaenge) : Simulationsobjekt(p_sName), p_dLaenge(p_dLaenge), tempolimit(p_eTempolimit::Autobahn){

}

void Weg::vSimulieren()
{
	for(const auto& aktuellesFahrzeug : p_pFahrzeuge)
	{
		aktuellesFahrzeug->vSimulieren();
	}
}

void vKopf(){
    const int colWidth = 20; // Breite jeder Spalte

    std::cout << std::left; // Links ausgerichtete Spalten
    std::cout << std::setw(colWidth) << "ID"
              << std::setw(colWidth) << "Name"
              << std::setw(colWidth) << "Max Geschwindigkeit"
              << std::setw(colWidth) << "Gesamtstrecke"
              << std::setw(colWidth) << "Aktuelle Geschwindigkeit"
              << std::endl;

    // Trennlinie
    std::cout << std::setfill('-') << std::setw(colWidth * 5) << "" << std::endl;
    std::cout << std::setfill(' '); // Zurücksetzen des Füllzeichens
}

void Weg::vAusgeben(std::ostream& out) const
{
	Simulationsobjekt::vAusgeben(out);
	std::cout << p_dLaenge << std::setw(20) << "()" << std::endl;
}

double Weg::getTempolimit()
{
	return static_cast<double>(tempolimit);
}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

