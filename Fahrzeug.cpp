/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;
double dGlobaleZeit = 0.0;

Fahrzeug::Fahrzeug() : ID(++p_iMaxID), p_sName("")
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

Fahrzeug::Fahrzeug(std::string p_sName) : p_sName(p_sName), ID(++p_iMaxID)
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

Fahrzeug::Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit) : ID(++p_iMaxID), p_sName(p_sName), p_dMaxGeschwindigkeit(p_dMaxGeschwindigkeit > 0 ? p_dMaxGeschwindigkeit : throw std::invalid_argument("Geschwindigkeit muss groeßer als 0 sein"))
{
	std::cout << "Ein Fahrzeug mit dem Namen " << p_sName << " und der ID " << ID << " wurde erstellt." << std::endl;
}

void Fahrzeug::vKopf()
{
    std::cout << std::left;
    std::cout << std::setw(6) << "ID"
              << std::setw(13) << "Name"
              << std::setw(20) << "MaxGeschwindigkeit"
              << std::setw(20) << "Gesamtstrecke"
    			<< std::setw(20) << "Akt. Geschw.";
}

void Fahrzeug::vAusgeben(std::ostream& out) const
{
    std::cout << std::left;
    std::cout << std::setw(6) << ID
              << std::setw(13) << p_sName
              << std::setw(20) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
              << std::setw(20) << std::fixed << std::setprecision(2) << p_dGesamtStrecke
              << std::setw(20) << std::fixed << dGeschwindigkeit();
}

void Fahrzeug::vSimulieren()
{
	if(p_dGesamtZeit < dGlobaleZeit)
	{
		double vergangeneZeit = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke = p_dGesamtStrecke + vergangeneZeit * dGeschwindigkeit();
	}
	else
	{
		std::cout << "Auto wurde schon simuliert, Simulationsschritt wird uebersprungen. Globale Zeit ist: " << dGlobaleZeit << " und letzte Simulationszeit ist: " << p_dZeit << std::endl;
	}

	p_dZeit = dGlobaleZeit;
	p_dGesamtZeit = p_dZeit;
}

std::ostream& operator<<(std::ostream& out, const Fahrzeug& fahrzeug)
{
	fahrzeug.vAusgeben(out);
	return out;
}

Fahrzeug::~Fahrzeug() {
	// TODO Auto-generated destructor stub
	std::cout << "Das gelöschte Fahrzeug hatte die ID " << ID << " und den Namen " << p_sName << std::endl;
}

