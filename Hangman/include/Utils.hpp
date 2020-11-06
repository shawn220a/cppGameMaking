#ifndef UTILS_HPP
#define UTILS_HPP

char GetCharacter(const char *prompt, const char *error);
char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength);

void ClearScreen();

#endif // UTILS_HPP