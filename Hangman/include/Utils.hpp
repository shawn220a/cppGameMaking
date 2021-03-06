#ifndef UTILS_HPP
#define UTILS_HPP

char GetCharacter(const char *prompt, const char *error);
char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength);
void ClearScreen();
void WaitForKeyPress();

#endif // UTILS_HPP