/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:55:02 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 21:13:08 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <string>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class ClapTrap
{
	private:

		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
// Constructors
//--- Default Constructor
//--- Constructor Overload
//--- Copy Constructor
//--- Default Destructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

// Overload operator
//--- Assignation operator
		ClapTrap &operator=(const ClapTrap &other);

// Set - Get
//--- Setters
//--- Getters
		void setName(std::string name);
		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);

		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

// Public member functions
//--- Actions functions
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

// Other
//--- print
//--- debug print
//--- amIOk?
		void print(int action, unsigned int &value,const std::string &name, const std::string &target = "buddy");
		void dbgPrint(const std::string &msg);
		bool amIOk();
};

#endif // ClapTrap_HPP
