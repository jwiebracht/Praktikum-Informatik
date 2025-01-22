/*
 * Fahrausnahme.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include <exception>
#include "Fahrzeug.h"
#include "Weg.h"

class Fahrausnahme : public std::exception{
public:
	Fahrausnahme() = delete;
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);

	virtual void vBearbeiten() = 0;

	virtual ~Fahrausnahme();

protected:
	Fahrzeug& fahrzeug;
	Weg& weg;
};

#endif /* FAHRAUSNAHME_H_ */
