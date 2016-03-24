# Graphics

Graphics library written in C and based on SDL 2.0

### Récupérer le code et installer les dépendances

Dans un terminal, en tant que root:

    apt-get install git make

Puis, en tant qu'utilisateur lambda:

    git clone https://github.com/Sancho-Panza/graphics.git

Enfin, en tant que root, se placer dans le répertoire récupéré précedemment et:

    make install

### Compilation

#### En ligne de commande

En tant qu'utilisateur lambda dans un terminal, se placer dans le répertoire récupéré précedemment et:

    make all

### Utilisation

Le moyen le plus simple d'utiliser la bibliothèque est de remplacer le contenu des fichiers main.c et main.cpp en faisant juste en sorte de garder les fichiers inclus, puis d'ajouter ses propres fichiers - toujours dans le répertoire src. Pour changer le nom de l'exécutable produit, il suffit de remplacer la valeur de NAME dans le Makefile.
