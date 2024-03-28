#ifndef		INTEGER_CLASS_H
# define	INTEGER_CLASS_H

# include <iostream>
class Integer {

public:
		Integer(int const n);
		~Integer(void);

		int	getvalue(void) const;

		Integer & operator=(Integer const & rhs); //operateur d'assignation
		Integer operator+(Integer const & rhs); //operateur d'addition

private:
		int	_n;
};

std::ostream &operator <<(std::ostream & o, Integer const &rhs);

#endif
