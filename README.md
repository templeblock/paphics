# Paphics

Paphics is a library written in C and based on SDL 2.0.

[![Build Status](https://travis-ci.org/zapashcanon/paphics.svg?branch=master)](https://travis-ci.org/zapashcanon/paphics)
[![Latest stable release](https://img.shields.io/github/release/zapashcanon/paphics.svg)](https://github.com/zapashcanon/paphics/releases)
[![Overall downloads on Github](https://img.shields.io/github/downloads/zapashcanon/paphics/total.svg)](https://github.com/zapashcanon/paphics/releases)
[![license](https://img.shields.io/github/license/zapashcanon/paphics.svg)](http://unlicense.org/)

## Récupérer le code source

### Installation de git

Pour récupérer le code et pouvoir contribuer au projet, il faut installer git.

#### Sous Debian et distributions dérivées (Ubuntu, Mint, etc.)

    # apt-get install git

### Cloner le projet avec git

    $ git clone https://github.com/zapashcanon/paphics.git

## Installation des dépendances

Il faut se placer dans le répertoire récupéré précedemment.

    $ cd paphics/

Puis installer les dépendances.

### Sous Debian et distributions dérivées (Ubuntu, Mint, etc.)

    # make get-dep-debian-all

## Compilation

    $ make

## Installation

    # make install-all

## Utilisation

Pour utiliser la bibliothèque dans un projet annexe, il suffit d'ajouter le flag suivant au moment de la compilation:

    -lpaphics

Puis d'inclure le fichier contenant tous les headers:

    #include <paphics/paphics.h>

Il est possible que les fichiers ne soient pas trouvés, il faut alors ajouter ceci au moment de la compilation:

    -I/usr/local/lib

Et ceci au moment de l'édition de liens:

    -L/usr/local/lib

Et éventuellement, ajouter la ligne suivante dans le Makefile de votre projet:

    export LD_LIBRARY_PATH=/usr/lib:/usr/local/lib:$LD_LIBRARY_PATH

# Documentation

The doc is available [here](http://www.ndrs.fr/paphics/doc.pdf).
