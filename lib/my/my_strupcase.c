/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** puts every letter of every word in uppercase
*/

char *my_strupcase(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++) {
        if (str[count] > 122)
            break;
        if (str[count] >= 97)
            str[count] = str[count] - 32;
    }
    return str;
}
