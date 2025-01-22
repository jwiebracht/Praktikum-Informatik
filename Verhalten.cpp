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

Weg& Verhalten::getWeg()
{
	return aktuellerWeg;
}

Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}

