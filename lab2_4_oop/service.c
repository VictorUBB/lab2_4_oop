#include "repository.h"
#include <stdio.h>
#include <string.h>

void add_produs(produs product, memorie* mem) {
	add_product(product, mem);
}


void modify_product_price(int id,int new_price, memorie* mem) {
	int found = find_product(id, mem);
	if (found == 0) {
		printf("Nu exista produs cu id-ul cautat");
	}
	else {
		mem->memory[found].pret = new_price;
	}
}


void modify_product_quantity(int id, int new_quantity, memorie* mem) {
	int found = find_product(id, mem);
	if (found == 0) {
		printf("Nu exista produs cu id-ul cautat");
	}
	else {
		mem->memory[found].cantitate = new_quantity;
	}
}


void delete_product(int id, memorie* mem) {
	int found = find_product(id, mem);
	if (found == 0) {
		printf("Nu exista produs cu id-u introdus");
	}
	else {
		delete_produs(found, mem);
	}
}

void swap(produs* xp, produs* yp)
{
	produs temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void filter_by_price(memorie* mem,int direction) {
	int i, j;
	if (direction == 0) {
		for (i = 1; i <= mem->contor ; i++)
			for (j = 1; j <= mem->contor - i; j++) {
				if (mem->memory[j].pret > mem->memory[j + 1].pret) {
					
					swap(&mem->memory[j] , &mem->memory[j+1]);
				}
					
			}

	}
	else {
		for (i = 1; i < mem->contor; i++)
			for (j = 1; j <= mem->contor - i; j++) {
				if (mem->memory[j].pret <= mem->memory[j + 1].pret) {

					swap(&mem->memory[j], &mem->memory[j + 1]);
				}

			}
	}

}

void filter_by_quantity(memorie* mem, int direction) {
	int i, j;
	if (direction == 0) {
		for (i = 1; i < mem->contor; i++)
			for (j = 1; j <= mem->contor - i; j++)
				if (mem->memory[j].cantitate > mem->memory[j + 1].cantitate)
					swap(&mem->memory[j], &mem->memory[j + 1]);
	}
	else {
		for (i = 1; i < mem->contor; i++)
			for (j = 1; j <= mem->contor - i; j++)
				if (mem->memory[j].cantitate < mem->memory[j + 1].cantitate)
					swap(&mem->memory[j], &mem->memory[j + 1]);
	}

}

memorie get_products_by_price(memorie* mem,int price) {
	memorie new_list;
	new_list.contor = 0;
	for (int i = 1;i <= mem->contor;i++) {
		if (mem->memory[i].pret == price) {
			new_list.contor++;
			new_list.memory[new_list.contor] = mem->memory[i];	
		}
	}
	return new_list;
		
}

memorie get_products_by_quantity(memorie* mem, int cantitate) {
	memorie new_list;
	new_list.contor = 0;
	for (int i = 1;i <= mem->contor;i++) {
		if (mem->memory[i].cantitate == cantitate) {
			new_list.contor++;
			new_list.memory[new_list.contor] = mem->memory[i];
		}
	}
	return new_list;

}

memorie get_products_by_producer(memorie* mem, char producator[30]) {
	memorie new_list;
	new_list.contor = 0;
	for (int i = 1;i <= mem->contor;i++) {
		if (strcmp(mem->memory[i].producator ,producator)==0) {
			new_list.contor++;
			new_list.memory[new_list.contor] = mem->memory[i];
		}
	}
	return new_list;

}


memorie generate_product() {
	memorie	test_mem;
	produs p1, p2, p3, p4;
	p1.id = 1;
	p1.pret = 80;
	p1.cantitate = 100;
	strcpy_s(p1.type,sizeof "televizor", "televizor");
	strcpy_s(p1.model,sizeof "bun", "bun");
	strcpy_s(p1.producator,sizeof "sony", "sony");
	test_mem.memory[1] = p1;
	p2.id = 2;
	p2.pret = 50;
	p2.cantitate = 75;
	strcpy_s(p2.type,sizeof "monitor", "monitor");
	strcpy_s(p2.model,sizeof "rau", "rau");
	strcpy_s(p2.producator,sizeof "lg", "lg");
	test_mem.memory[2] = p2;
	p3.id = 3;
	p3.pret = 90;
	p3.cantitate = 90;
	strcpy_s(p3.type,sizeof "frigider" ,"frigider");
	strcpy_s(p3.model,sizeof "nou", "nou");
	strcpy_s(p3.producator,sizeof "asus" ,"asus");
	test_mem.memory[3] = p3;
	p4.id = 4;
	p4.pret = 25;
	p4.cantitate = 30;
	strcpy_s(p4.type,sizeof "pc", "pc");
	strcpy_s(p4.model,sizeof "vechi", "vechi");
	strcpy_s(p4.producator,sizeof "samsung", "samsung");
	test_mem.memory[4] = p4;
	test_mem.contor = 4;
	return test_mem;
}