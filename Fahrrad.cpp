/*
 * Fahrrad.cpp
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad(std::string p_sName, double p_dMaxGeschwindigkeit) : Fahrzeug(p_sName, p_dMaxGeschwindigkeit)
{

}

double Fahrrad::dGeschwindigkeit() const{
    double faktor = 1.0 - (static_cast<int>(p_dGesamtStrecke / 20) * 0.10);
    double aktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * faktor;
    return std::max(aktuelleGeschwindigkeit, 12.0);  // Minimal 12 km/h
}

double Fahrrad::dTanken(double dMenge)
{
	return 0;
	//Ein Fahrrad kann nicht tanken
}

void Fahrrad::vSimulieren()
{
    if (dGlobaleZeit <= p_dZeit)
        return;

    double vergangeneZeit = dGlobaleZeit - p_dZeit;
    double teilStrecke = p_pVerhalten->dStrecke(*this, vergangeneZeit);

    if (teilStrecke == 0)
    {
    	p_dAbschnittStrecke = 0;
        //throw Streckenende(*this, p_pVerhalten->getWeg());
    }
	Fahrzeug::vSimulieren();
}

std::unique_ptr<Fahrzeug> Fahrrad::fahrzeugErstellen()
{
	std::string name =  Fahrzeug::generateRandomName();
	std::unique_ptr<Fahrrad> bike = std::make_unique<Fahrrad>(name, 30);
	return bike;
}

double Fahrrad::getTankvolumen()
{
	return 0;
}

double Fahrrad::getTankinhalt()
{
	return 0;
}

Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}

