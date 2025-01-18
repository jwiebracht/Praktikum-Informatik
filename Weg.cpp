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
	std::cout << "Weg: " << p_sName << " wurde erstellt" <<std::endl;
}

Weg::Weg(std::string p_sName, double p_dLaenge) : Simulationsobjekt(p_sName), p_dLaenge(p_dLaenge), tempolimit(p_eTempolimit::Autobahn){
	std::cout << "Weg: " << p_sName << " wurde erstellt" <<std::endl;
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

void Weg::vAusgeben(std::ostream& out) const {
    Simulationsobjekt::vAusgeben(out);
    std::cout << std::setw(20) << p_dLaenge << std::setw(10);
    std::cout << "(";

    bool first = true;
    for (const auto& fahrzeug : p_pFahrzeuge) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << fahrzeug->getName();
        first = false;
    }

    std::cout << ")" << std::endl;
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug)
{
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(std::move(pFahrzeug));
	std::cout << "Annahme von fahrendem Fahrzeug erfolgreich" << std::endl;
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double startZeit) {
    fahrzeug->vNeueStrecke(*this, startZeit);
    p_pFahrzeuge.push_front(std::move(fahrzeug));
	std::cout << "Annahme von parkendem Fahrzeug erfolgreich" << std::endl;
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

