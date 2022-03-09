#include <stdio.h>
#include "service.h"
#include <stdlib.h>
#include "validators.h"

void options();

void delete_by_id(memorie* mem);

/*Citeste elementele pentru un produs nou
*/
void read_product(produs* the_product);

void add_product_ui(memorie* mem);

/*Afiseaza toate elmentele din memorie
*/
void print_all(memorie* mem);

void modify_price(memorie* mem);

void modify_quantity(memorie* mem);

void filter_ui(memorie* mem);

/*Interfata penru moificare elmente
*/
void modify(memorie* mem);


void sorted_ui(memorie* mem);

int main() {
	int option;
	memorie internal_mem;
	memorie mem2;
	internal_mem.contor=0;
	while (1) {
		options();
		printf("Introduceti optiunea dumneavoastra: ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			add_product_ui(&internal_mem);
			print_all(&internal_mem);
			break;
		case 2:
			modify(&internal_mem);
			break;
		case 3:
			delete_by_id(&internal_mem);
			print_all(&internal_mem);
			break;
		case 4:
			mem2 = generate_product();
			//memorie copy;
			//copy = generate_product();
			//copy = internal_mem;
			filter_ui(&mem2);
			break;
		case 5:
			mem2 = generate_product();
			sorted_ui(&mem2);
			break;
		default:
			break;
		}
	}
	return 0;
}


void options() {
	printf("1.Adauga produs nou\n");
	printf("2.Modifica produs \n");
	printf("3.Sterge produs \n");
	printf("4.Sortare \n");
	printf("5.Filtrare \n");
}

void sorted_ui(memorie* mem) {
	int option;
	printf("Alegeti dupa ce sa filtrati\n");
	printf("1.Pret\n");
	printf("2.Cantitate\n");
	printf("3.Producator\n");
	scanf_s("%d", &option);
	switch (option)
	{ case 1:
		int pret;
		memorie new_list;
		printf("Introduceti pretul dorit:");
		scanf_s("%d", &pret);
		new_list = get_products_by_price( mem, pret);
		print_all(&new_list);
		break;
	case 2:
		int cantitate;
		memorie new_list1;
		printf("Introduceti cantiatatea dorita:");
		scanf_s("%d", &cantitate);
		new_list1 = get_products_by_quantity(mem, cantitate);
		print_all(&new_list1);
		break;
	case 3:
		char producator[30];
		memorie new_list2;
		printf("Introduceti producatorul dorit:");
		scanf_s("%s", &producator, (unsigned)_countof(producator));
		new_list2 = get_products_by_producer(mem, producator);
		print_all(&new_list2);
		break;
	default:
		break;
	}
}

void filter_ui(memorie *mem) {
	int direction,option;
	printf("Alegeti dupa ce doriti sa sortati:\n 1.Pret\n 2.Cantitate  ");
	scanf_s("%d", &option);
	if (option == 1) {
		printf("Alegeti sensul:\n 0.Crescator\n 1.Descrescator  ");
		scanf_s("%d",&direction);
		filter_by_price(mem,direction);
	}
	else{
		printf("Alegeti sensul:\n 0.Crescator\n 1.Descrescator  ");
		scanf_s("%d", &direction);
		filter_by_quantity(mem, direction);
	}
	print_all(mem);
}

void delete_by_id(memorie* mem) {
	int id;
	printf("Introduceti id-ul cautat: ");
	scanf_s("%d", &id);
	delete_product(id, mem);
}


void modify(memorie* mem) {
	int option;
	printf("Alegeti ce doriti sa modificati:\n 1.Pretul\n 2.Cantitatea:  ");
	scanf_s("%d", &option);
	if (option == 1) {
		modify_price(mem);
	}
	else {
		modify_quantity(mem);
	}
}


void modify_quantity(memorie* mem) {
	int id, cantitate;
	printf("Introduceti id-ul dorit: ");
	scanf_s("%d", &id);
	printf("Introduceti noua cantitate: ");
	scanf_s("%d", &cantitate);
	modify_product_quantity(id, cantitate, mem);
	print_all(mem);
}


void modify_price(memorie* mem) {
	int id,pret;
	printf("Introduceti id-ul dorit: ");
	scanf_s("%d", &id);
	printf("Introduceti noul pret: ");
	scanf_s("%d", &pret);
	modify_product_price(id, pret, mem);
	print_all(mem);
}

void add_product_ui(memorie *mem) {
	produs new_product;
	read_product( &new_product);
	if (validation(new_product, mem) == 0) {
		add_product(new_product, mem);
	}
	else 
		printf("Exista deja id-ul introdus\n");
	

}

void read_product(produs *the_product) {
	printf("Introduceti id: ");
	scanf_s("%d", &the_product->id);
	printf("Introduceti pret: ");
	scanf_s("%d", &the_product->pret);
	printf("Introduceti cantitate: ");
	scanf_s("%d", &the_product->cantitate);
	printf("Introduceti tip: ");
	scanf_s("%s", &the_product->type, (unsigned)_countof(the_product->type));
	printf("Introduceti producator: ");
	scanf_s("%s", &the_product->producator, (unsigned)_countof(the_product->producator));
	printf("Introduceti model: ");
	scanf_s("%s", &the_product->model, (unsigned)_countof(the_product->model));

}
void print_all(memorie *mem) {
	for (int i = 1;i <= mem->contor;i++) {
		printf("Id: %d Pret: %d  Cantitate: %d  Tip: %s Producator: %s Model: %s\n", mem->memory[i].id, mem->memory[i].pret, mem->memory[i].cantitate, mem->memory[i].type, mem->memory[i].producator, mem->memory[i].model);
	}

}