/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** compare two string till the len n is not passed
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len_1 = 0;
    int len_2 = 0;
    int result = 0;
    int count = 0;
    int len_max = 0;

    for (len_1 = 0; s1[len_1] != '\0' && len_1 < n; len_1++);
    for (len_2 = 0; s2[len_2] != '\0' && len_2 < n; len_2++);
    if (len_2 > len_1)
        len_max = len_2;
    if (len_2 <= len_1)
        len_max = len_1;
    for (; count <= len_max; count++) {
        if (s2[count] - s1[count] != 0) {
            result = s1[count] - s2[count];
            return result;
        }
    }
    return 0;
}
