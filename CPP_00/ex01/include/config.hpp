/**
Defines ANSI escape codes used for formatting, as well as prompts and error messages etc.
*/

#ifndef CONFIG_HPP
# define CONFIG_HPP

// Define ANSI escape codes for colors and styles

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define RED			"\033[91m"
# define ORANGE			"\033[38;5;208m"
# define BLUE 			"\033[34m"
# define VIOLET 		"\033[35;1m"

#define TITLE			BOLD ORANGE	"┌─────────────────────────┐\n" \
									"│  ☎️ My Tiny Phonebook ☎️  │\n" \
									"└─────────────────────────┘" RESET
# define PROMPT			YELLOW "Please enter:\n" GREEN "[ADD]  [SEARCH]  [EXIT]" RESET
# define ERR_NOT_FOUND	RED BOLD "❌ Option not found ❌" RESET
# define ERR_TOO_L		RED BOLD "❌ Input too long (max. " RESET
# define BYE		 	ORANGE BOLD "Thank you for using My Tiny Phonebook" RESET

// SEARCH

# define IDX_TABLE		GREEN "|     " BOLD "Index" RESET GREEN "|    " BOLD "F_Name" \
						RESET GREEN "|    " BOLD "L_Name" RESET GREEN "|  " BOLD "Nickname"  RESET GREEN "|" RESET
# define NO_CONTACTS 	YELLOW BOLD "📒 Phonebook is empty! No contacts added yet." RESET
# define SEL_CONTACT_1	YELLOW "Select contact (index): " RESET
# define SEL_CONTACT	YELLOW "Select contact (1-" RESET
# define INV_IDX		RED BOLD "❌ Invalid index (press Enter to leave) ❌" RESET
# define PIPE 			GREEN "|" RESET

// ADD

# define ADD 			GREEN "ADD" RESET
# define EMPTY_FIELD	RED BOLD "❌ Cannot be empty ❌" RESET
# define INV_PHONE_NR	RED BOLD "❌ Invalid phone number! Please use digits [0-9], spaces, and characters [+() -]. ❌" RESET

#endif
