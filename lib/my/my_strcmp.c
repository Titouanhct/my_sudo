/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare two string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int len_str1 = 0;
    int len_str2 = 0;
    int result = 0;
    int count = 0;
    int len_max = 0;

    for (len_str1 = 0; s1[len_str1] != '\0'; len_str1++);
    for (len_str2 = 0; s2[len_str2] != '\0'; len_str2++);
    if (len_str2 > len_str1)
        len_max = len_str2;
    if (len_str2 <= len_str1)
        len_max = len_str1;
    for (; count <= len_max; count++) {
        if (s2[count] - s1[count] != 0) {
            result = s1[count] - s2[count];
            return result;
        }
    }
    return 0;
}
