# Paphics

Paphics is a library written in C and based on SDL 2.0.

[![Build Status](https://travis-ci.org/zapashcanon/paphics.svg?branch=master)](https://travis-ci.org/zapashcanon/paphics)
[![Latest stable release](https://img.shields.io/github/release/zapashcanon/paphics.svg)](https://github.com/zapashcanon/paphics/releases)
[![Overall downloads on Github](https://img.shields.io/github/downloads/zapashcanon/paphics/total.svg)](https://github.com/zapashcanon/paphics/releases)
[![license](https://img.shields.io/github/license/zapashcanon/paphics.svg)](http://unlicense.org/)

## Récupérer le code source

Il suffit de récupérer l'archive souhaitée:

* [version de développement](https://github.com/zapashcanon/paphics/archive/master.zip)
* [versions stables](https://github.com/zapashcanon/paphics/releases)

## Installation des dépendances

Il faut extraire l'archive précédemment récupérée, se placer dedans puis installer les dépendances:

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

    export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# Documentation

The doc is available [here](http://www.ndrs.fr/paphics/doc.pdf).
