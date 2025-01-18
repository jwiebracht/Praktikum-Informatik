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

void Weg::vKopf() {

    // Kopfzeile
    std::cout << std::left
              << std::setw(6) << "ID"
              << "| " << std::setw(10) << "Name"
              << "| " << std::setw(15) << "Laenge"
              << "| " << "Fahrzeuge"
              << std::endl;

    // Trennlinie
    std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
    std::cout << std::setfill(' '); // Zurücksetzen des Füllzeichens
}

void Weg::vAusgeben(std::ostream& out) const
{
	Simulationsobjekt::vAusgeben(out);
	std::cout << std::setw(20) << p_dLaenge << std::setw(10) << "()" << std::endl;
}

double Weg::getTempolimit()
{
	return static_cast<double>(tempolimit);
}

double Weg::getLaenge()
{
	return p_dLaenge;
}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

