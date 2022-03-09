#pragma once

/*Creez struct pentru produse
*/
typedef struct {
	int id, pret, cantitate;
	char type[30], producator[30], model[30];
}produs;

/*Struct pentru a tine minte elmentele si nu7marul lor
*/
typedef struct {
	int contor;
	produs memory[30];
}memorie;

