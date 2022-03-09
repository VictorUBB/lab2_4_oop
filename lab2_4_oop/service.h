#ifndef SERVICE_H_
#define SERVICE_H_
#include "objects.h"



/*Functie pentru stocarea produselor in memorie
*/
void add_produs(produs product, memorie* mem);


/*Functie ce se ocupa cu modificarea pretului unui produs in functie de id
* id-id-ul produsului
* new_price-noul pret
* mem-produsele existente
*/
void modify_product_price(int id,int new_price, memorie* mem);


/*Functie ce se ocupa cu modificarea cantitatii unui produs in functie de id
* id-id-ul produsului
* new_quantity-noua cantitate
* mem-produsele existente
*/
void modify_product_quantity(int id, int new_quantity, memorie* mem);


/*Functie ce sterge un produs in functie de id
* id- id-ul produsului ce va fi sters
*  mem- lista cu produsele si cu contorul curent
*/
void delete_product(int id, memorie* mem);



/*Functie ce creaza o lista sortata dupa pret din produsele existente
* daca direction=0- sortare crescatoare
*				=1 - sortare descrescatoare
*/
void filter_by_price(memorie* mem, int direction);

/*Functie ce creaza o lista sortata dupa cantitate din produsele existente
* daca direction=0- sortare crescatoare
*				=1 - sortare descrescatoare
*/
void filter_by_quantity(memorie* mem, int direction);

/*Functie ce genereaza o serie de produse
*/
memorie generate_product();

/*Functie pentru a gasi produsele ce au un anumit pret
* mem- structul ce tine toate produsele
* price- pretul cautat
*/
memorie get_products_by_price(memorie* mem, int price);

/*Functie ce se ocupa de a gasi produsele ce auo anumita cantitae
* mem- structul ce tine toate produsele
* cantitate- cantitatea cautatat
*/
memorie get_products_by_quantity(memorie* mem, int cantitate);

/*Functie ce se ocupa de a gasi produsele ce au un anumit producator
* mem- structul ce tine toate produsele
* producator- producatorul cautat
*/
memorie get_products_by_producer(memorie* mem, char producator[30]);
#endif // !SERVICE_H_

