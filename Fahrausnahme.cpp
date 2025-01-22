/*
 * Fahrausnahme.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Fahrausnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

Fahrausnahme::Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg) : fahrzeug(fahrzeug), weg(weg){

}

Fahrausnahme::~Fahrausnahme() {
}

