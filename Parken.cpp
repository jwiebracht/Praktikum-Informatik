/*
 * Parken.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Parken.h"
#include "Fahrzeug.h"
#include "Fahren.h"
#include "Weg.h"

Parken::Parken(Weg& weg, double startZeitpunkt)
    : Verhalten(weg), dStartZeitpunkt(startZeitpunkt) {}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if(dStartZeitpunkt < dGlobaleZeit)
	{
		return 0.0;
	}
	else
	{
	    double maximaleStrecke = aFzg.getMaxGeschwindigkeit() * dZeitIntervall;
	    double verbleibendeStrecke = aktuellerWeg.getLaenge() - aFzg.getGesamtStrecke();
	    if(verbleibendeStrecke == 0) std::cout << "Fahrzeug: " << aFzg.getName() << " ist am Ende des Weges angekommen" << std::endl;
	    return std::min(maximaleStrecke, verbleibendeStrecke);
	}
}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}

