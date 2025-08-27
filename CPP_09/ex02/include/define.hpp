#ifndef DEFINE_HPP
# define DEFINE_HPP

// compile with 'make debug' to print debug output
# ifdef DEBUG
#  define DEBUG_PRINT(x) do { std::cout << x << std::endl; } while (0)
# else
#  define DEBUG_PRINT(x) do {} while (0)
# endif

#define YELLOW		"\033[33m"
#define GREEN		"\033[32m"
#define RED			"\033[31m"
#define BOLD		"\033[1m"
#define RESET		"\033[0m"

#define MAX_ARGS	9999 // max numbers of integers to be passed

#define WIDTH_N		3	// used in setw(); ideally the max digits of numbers being sorted
#define WIDTH_C		16	// used in setw(); ideally the max width of container names

#endif
