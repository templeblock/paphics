# Graphics

Graphics library written in C and based on SDL 2.0

## Récupérer le code source

### Installation de git

Pour récupérer le code et pouvoir contribuer au projet, il faut installer git.

#### Sous Debian et distributions dérivées (Ubuntu, Mint, etc.)

    # apt-get install git

### Cloner le projet avec git

    $ git clone https://github.com/zapashcanon/graphics.git

## Installation des dépendances

Il faut se placer dans le répertoire récupéré précedemment.

    $ cd graphics/

Puis installer les dépendances.

### Sous Debian et distributions dérivées (Ubuntu, Mint, etc.)

    # make install-dep-debian
    # make install-dep-dev-debian

## Compilation

    $ make

## Installation

    # make install
    # make install-dev

## Utilisation

Pour utiliser la bibliothèque dans un projet annexe, il suffit d'ajouter le flag suivant au moment de la compilation:

    -lgraphics

Puis d'inclure les fichiers nécessaires, par exemple:

    <graphics/graphics.h>
    <graphics/screen.h>
