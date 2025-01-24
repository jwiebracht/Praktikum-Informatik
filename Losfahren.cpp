/*
 * Losfahren.cpp
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg) {
}

void Losfahren::vBearbeiten() {
	std::unique_ptr<Fahrzeug> pFahrzeugKopie = weg.pAbgabe(fahrzeug);
	weg.vAnnahme(move(pFahrzeugKopie));
    std::cout << "Losfahren-Ausnahme bei Fahrzeug: "
              << fahrzeug.getName()
              << " auf Weg: "
              << weg.getName()
              << std::endl;
}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

