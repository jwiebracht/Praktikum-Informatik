/*
 * Verhalten.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

Verhalten::Verhalten(Weg& weg) : aktuellerWeg(weg)
{
}

double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
    double maximaleStrecke = aFzg.getMaxGeschwindigkeit() * dZeitIntervall;
    double verbleibendeStrecke = aktuellerWeg.getLaenge() - aFzg.getGesamtStrecke();
    return std::min(maximaleStrecke, verbleibendeStrecke);
}

Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}

