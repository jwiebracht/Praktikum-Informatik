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

	if (dGlobaleZeit >= dStartZeitpunkt)
	{
		std::cout << aFzg.getName() << " hat Startzeitpunkt erreicht" << std::endl;
		throw Losfahren(aFzg, aktuellerWeg);
	}
	else
	{
		return 0;
	}

}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}

