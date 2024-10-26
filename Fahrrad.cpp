/*
 * Fahrrad.cpp
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad() {
	// TODO Auto-generated constructor stub
}

Fahrrad::Fahrrad(std::string p_sName, double p_dMaxGeschwindigkeit) : Fahrzeug(p_sName, p_dMaxGeschwindigkeit)
{

}

double Fahrrad::dGeschwindigkeit() const{
    double faktor = 1.0 - (static_cast<int>(p_dGesamtStrecke / 20) * 0.10);
    double aktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * faktor;
    return std::max(aktuelleGeschwindigkeit, 12.0);  // Minimal 12 km/h
}

void Fahrrad::dTanken(double dMenge)
{
	//Ein Fahrrad kann nicht tanken
}

Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}

