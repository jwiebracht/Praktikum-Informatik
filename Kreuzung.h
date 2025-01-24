/*
 * Kreuzung.h
 *
 *  Created on: 24.01.2025
 *      Author: jonas
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_
#include "Simulationsobjekt.h"
#include <list>
#include <random>

class Weg;

class Fahrzeug;

enum class p_eTempolimit;

class Kreuzung : public Simulationsobjekt{
public:
	Kreuzung(std::string p_sName);
	Kreuzung(std::string p_sName, double tank);

	static void vVerbinde(std::string p_sNameHinweg, std::string p_sNameRueckweg, double weglaenge, std::shared_ptr<Kreuzung> startKreuzung, std::shared_ptr<Kreuzung> zielKreuzung, p_eTempolimit tempolimit);
	void vAnnahme(std::unique_ptr<Fahrzeug>, double);
	void vSimulieren();
	void vTanken(Fahrzeug&);
	std::shared_ptr<Weg> pZufaelligerWeg(Weg&) const;
	void vAusgeben(std::ostream& out) const override;

	std::string getName() const;
	double getTankstelleninhalt() const;

	virtual ~Kreuzung();

private:
	std::list<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle;
};

#endif /* KREUZUNG_H_ */
