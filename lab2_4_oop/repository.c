#include "repository.h"
#include <stdio.h>
#include <assert.h>

void add_product(produs product,memorie *mem) {
	mem->contor = mem->contor+1;
	mem->memory[mem->contor] = product;

}

int find_product(int id, memorie* mem) {
	for (int i = 1;i <= mem->contor;i++) {
		if (mem->memory[i].id == id) {
			return i;
		}
	
	}
	return 0;
}

void delete_produs(int position, memorie* mem) {
	for (int i = position;i < mem->contor;i++) {
		mem->memory[i] = mem->memory[i + 1];

		mem->contor -= 1;
	}
}

memorie generate_products() {
	memorie	test_mem;
	produs p1, p2, p3, p4;
	p1.id = 1;
	p1.pret = 10;
	p1.cantitate = 90;
    strcpy(p1.type ,"televizor");
	strcpy(p1.model, "bun");
	strcpy(p1.producator,"sony");
	test_mem.memory[1] = p1;	
	p2.id = 2;
	p2.pret = 50;
	p2.cantitate = 75;
	strcpy(p2.type, "monitor");
	strcpy(p2.model, "rau");
	strcpy(p2.producator, "lg");
	test_mem.memory[2] = p2;
	p3.id = 1;
	p3.pret = 10;
	p3.cantitate = 90;
	strcpy(p3.type, "frigider");
	strcpy(p3.model, "nou");
	strcpy(p3.producator, "asus");
	test_mem.memory[3] = p3;
	p4.id = 1;
	p4.pret = 10;
	p4.cantitate = 90;
	strcpy(p4.type, "pc");
	strcpy(p4.model, "vechi");
	strcpy(p4.producator, "samsung");
	test_mem.memory[4] = p4;
	test_mem.contor = 4;
	return test_mem;
}

void test_add_product() {
	memorie test_memory;
	produs p1;
	p1.id = 5;
	p1.pret = 11;
	p1.cantitate = 90;
	strcpy(p1.type, "televizor");
	strcpy(p1.model, "bun");
	strcpy(p1.producator, "sony");
	test_memory = generate_products();
	add_product(p1, &test_memory);
	assert(test_memory.memory[5].id== p1.id);
	assert(test_memory.memory[5].pret == p1.pret);
	assert(test_memory.memory[5].cantitate == p1.cantitate);
	assert(strcmp(test_memory.memory[5].type, p1.type));
	assert(strcmp(test_memory.memory[5].model, p1.model));
	assert(strcmp(test_memory.memory[5].producator, p1.producator));
}