#include <iostream>
#include "../includes/Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "Esempio di dati";

	std::cout << "Indirizzo originale di Data: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Dato serializzato: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Indirizzo dopo deserializzazione: " << ptr << std::endl;

	if (ptr == &data) {
		std::cout << "I puntatori sono uguali. Serializzazione e deserializzazione riuscite." << std::endl;
		std::cout << "Valore: " << ptr->value << ", Nome: " << ptr->name << std::endl;
	} else {
		std::cout << "I puntatori non sono uguali. Serializzazione e deserializzazione fallite." << std::endl;
	}

	return 0;
}
