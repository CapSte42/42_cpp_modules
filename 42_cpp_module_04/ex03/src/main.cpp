/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:13:01 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/09 00:34:51 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include <iostream>

void personalTest()
{
	// Creazione di MateriaSource per apprendere nuove Materia
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Creazione di due personaggi
	ICharacter* hero = new Character("Hero");
	ICharacter* villain = new Character("Villain");

	// Equipaggiamento di Materia per il personaggio "Hero"
	AMateria* iceMateria = src->createMateria("ice");
	hero->equip(iceMateria);

	AMateria* cureMateria = src->createMateria("cure");
	hero->equip(cureMateria);

	// Equipaggiamento aggiuntivo per riempire l'inventario
	AMateria* anotherIce = src->createMateria("ice");
	hero->equip(anotherIce);

	AMateria* anotherCure = src->createMateria("cure");
	hero->equip(anotherCure);

	// Tentativo di equipaggiare un'ulteriore Materia (l'inventario è pieno)
	AMateria* overflowMateria = src->createMateria("ice");
	hero->equip(overflowMateria);  // Questo non dovrebbe funzionare

	// Uso delle Materia del personaggio "Hero" su "Villain"
	std::cout << std::endl;
	hero->use(0, *villain);  // Usa Ice su Villain
	hero->use(1, *villain);  // Usa Cure su Villain

	// Uso di Materia in un indice vuoto (fuori dai limiti)
	hero->use(4, *villain);  // Tentativo di usare Materia in un indice fuori dai limiti
	hero->use(-1, *villain);  // Tentativo di usare un indice negativo

	// Rimozione di una Materia dall'inventario
	hero->unequip(2);  // Rimuove la terza Materia (indice 2)
	hero->use(2, *villain);  // Tentativo di usare la Materia rimossa (non dovrebbe fare nulla)

	// Ri-equipaggiamento in uno slot vuoto
	hero->equip(overflowMateria);  // Ora dovrebbe funzionare, dato che uno slot è vuoto
	hero->use(2, *villain);  // Usa la Materia ri-equipaggiata

	// Copia di un personaggio
	std::cout << std::endl << "Cloning Hero into Sidekick..." << std::endl;
	ICharacter* sidekick = new Character(*static_cast<Character*>(hero));

	sidekick->use(0, *villain);  // Usa Ice su Villain
	sidekick->use(1, *villain);  // Usa Cure su Villain

	// Distruzione dei personaggi e delle sorgenti di Materia
	delete anotherIce;
	delete villain;
	delete hero;
	delete sidekick;
	delete src;
}

void subjectTest ()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	std::cout << BOLDCYAN "Personal test:" RESET << std::endl;
	personalTest();
	std::cout << std::endl << BOLDCYAN "Subject test:" RESET << std::endl;
	subjectTest();
	return 0;
}
