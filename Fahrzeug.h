/*
 * Fahrzeug.h
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iostream>
#include <string>

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(std::string p_sName);
	virtual ~Fahrzeug();

private:
	 static int p_iMaxID;
	 std::string p_sName;
	 const int ID;
};

#endif /* FAHRZEUG_H_ */
