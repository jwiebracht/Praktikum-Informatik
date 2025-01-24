/*
 * Fahren.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Fahren::Fahren(Weg& weg) : Verhalten(weg) {
	// TODO Auto-generated constructor stub

}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
    double maximaleStrecke = aFzg.getMaxGeschwindigkeit() * dZeitIntervall;
    double verbleibendeStrecke = aktuellerWeg.getLaenge() - aFzg.getGesamtStrecke();
    if(verbleibendeStrecke == 0)
    {
    	throw Streckenende(aFzg, aktuellerWeg);
    }
    return std::min(maximaleStrecke, verbleibendeStrecke);
}

Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}

