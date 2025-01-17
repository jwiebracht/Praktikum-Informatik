/*
 * Simulationsobjekt.h
 *
 *  Created on: 28.11.2024
 *      Author: jonas
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <iostream>

class Simulationsobjekt {
public:
	Simulationsobjekt();
	Simulationsobjekt(Simulationsobjekt&) = delete;
	Simulationsobjekt(std::string p_sName);
	std::string getName() const;
	virtual void vAusgeben(std::ostream& out) const = 0;
	static void vKopf();
	int getID() const;

	virtual ~Simulationsobjekt();

private:
	 static int p_iMaxID;

protected:
	double p_dlokaleZeit;
	std::string p_sName;
	double p_dZeit = 0.0;
	const int ID;
};

bool operator==(const Simulationsobjekt& one, const Simulationsobjekt& two);
std::ostream& operator<<(std::ostream& out, const Simulationsobjekt& objekt);

#endif /* SIMULATIONSOBJEKT_H_ */
