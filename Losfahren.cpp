/*
 * Losfahren.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Losfahren.h"

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {
}

void Losfahren::vBearbeiten() {
    std::cout << "Losfahren-Ausnahme bei Fahrzeug: "
              << fahrzeug.getName()
              << " auf Weg: "
              << weg.getName()
              << std::endl;
}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

