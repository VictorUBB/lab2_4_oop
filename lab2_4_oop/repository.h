#ifndef REPOSITORY_H_
#define  REPOSITORY_H_
#include "objects.h"

/*Functie ce se ocupa cu adaugarea de produde noi
* mem - elementel din memorie
* product-produsul ce vreau sa il adaug
*/
void add_product(produs product, memorie* mem);

/*Functie ce verifica daca id-ul unui produs exista in memorie
* id- id-ul cautat
* mem- lista cu produsele si cu contorul curent
* return 0 daca nu exista,altfel pozitia produsului
*/
int find_product(int id, memorie* mem);

/*Functie ce sterge un produs in functie de id
* position-pozitia produsului ce va fi sters
*  mem- lista cu produsele si cu contorul curent
*/
void delete_produs(int position, memorie* mem);

memorie generate_products();
#endif /* REPOSITORY_H_*/