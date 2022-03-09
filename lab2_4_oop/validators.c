
#include "objects.h"

int validation(produs new_product, memorie* mem) {
	for (int i = 1;i <= mem->contor;i++) {
		if (mem->memory[i].id == new_product.id) {
			return -1;
		}
	}
	return 0;
}