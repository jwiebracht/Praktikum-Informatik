/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#include "Fahrzeug.h"

double dGlobaleZeit = 0.0;

Fahrzeug::Fahrzeug(std::string p_sName) : Simulationsobjekt(p_sName)
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

Fahrzeug::Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit) : Simulationsobjekt(p_sName), p_dMaxGeschwindigkeit(p_dMaxGeschwindigkeit > 0 ? p_dMaxGeschwindigkeit : throw std::invalid_argument("Geschwindigkeit muss groeßer als 0 sein"))
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}


void Fahrzeug::vSimulieren()
{
	if(p_dGesamtZeit < dGlobaleZeit)
	{
		double vergangeneZeit = dGlobaleZeit - p_dZeit;
		double teilStrecke = p_pVerhalten->dStrecke(*this, vergangeneZeit);
        p_dGesamtStrecke += teilStrecke;
        p_dAbschnittStrecke += teilStrecke;
	}
	else
	{
		std::cout << "Auto wurde schon simuliert, Simulationsschritt wird uebersprungen. Globale Zeit ist: " << dGlobaleZeit << " und letzte Simulationszeit ist: " << p_dZeit << std::endl;
	}

	p_dZeit = dGlobaleZeit;
	p_dGesamtZeit = p_dZeit;
}

void Fahrzeug::vAusgeben(std::ostream& out) const
{
	Simulationsobjekt::vAusgeben(out);
    std::cout << std::setw(20) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
    << std::setw(20) << std::fixed << std::setprecision(2) << p_dGesamtStrecke
    << std::setw(20) << std::fixed << dGeschwindigkeit();
}

void Fahrzeug::vNeueStrecke(Weg& weg)
{
	p_pVerhalten = std::make_unique<Verhalten>(weg);
	p_dAbschnittStrecke = 0;
}


std::string Fahrzeug::generateRandomName()
{
	std::string names[] = {"Dieter", "Peter", "Johann", "Ken", "Barbie"};
	int nummer = rand() % 5;
	return names[nummer];
}

double Fahrzeug::getGesamtStrecke() const
{
	return p_dGesamtStrecke;
}

double Fahrzeug::getMaxGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

bool operator<(const Fahrzeug& lhs, const Fahrzeug& rhs)
{
    return lhs.getGesamtStrecke() < rhs.getGesamtStrecke();
}

// Benutzerdefinierter Zuweisungsoperator für die Fahrzeug-Klasse
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& rhs) {
    if (this == &rhs) {
        return *this; // Selbstzuweisungsschutz
    }
    // Nur Stammdaten kopieren (Daten, die bei der Erstellung festgelegt werden)
    p_sName = rhs.p_sName;
    p_dMaxGeschwindigkeit = rhs.p_dMaxGeschwindigkeit;
    // ID bleibt unverändert, da sie eindeutig für jedes Fahrzeug sein sollte
    return *this;
}

Fahrzeug::~Fahrzeug() {
	// TODO Auto-generated destructor stub
	std::cout << "Das gelöschte Fahrzeug hatte die ID " << ID << " und den Namen " << p_sName << std::endl;
}

