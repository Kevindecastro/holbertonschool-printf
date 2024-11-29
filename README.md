
# README PRINTF

La fonction "_printf" affiche une sortie.
Elle est comme `printf` mais avec un ensemble de spécificateurs.




## main.c

```c
#include "main.h"
#include <stdio.h>
#include <limits.h>


int main(void)
{
    int len1, len2;

    len1 = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Character: [%c]\n", 'H');
    printf("Character: [%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Length:[%d, %i]\n", len1, len1);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Percent test: [%%]\n");
    printf("Percent test: [%%]\n");
    _printf("Unsupported specifier: [%r]\n");
    return (0);
}
```

Spécificateurs Spéciales

| Spécificateurs            | Description                                                               |
| ----------------- | ------------------------------------------------------------------ |
| %c | Affiche un caractère. |
| %s | Affiche une chaîne de caractères.
| %d ou %i| Affiche un entier signé. |
| %% | Affiche un caractère pourcentage (`%`). |


## Déploiment

Commande pour compiler le programme.

```gcc
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```




## Pour la man-page

[Man Page](https://www.man-linux-magique.net/man7/man-pages.html)



![Holberton](https://www.entreprises-magazine.com/wp-content/uploads/2020/12/Holberton.png)


## Authors

- [@Noam](https://www.github.com/Noam72T)
- [@Kevin](https://github.com/Kevindecastro)

