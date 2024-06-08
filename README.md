# cpp07 - École 42 | Paris

## Description

Ce projet fait partie des exercices du module CPP07. Il a pour but de renforcer les compétences en programmation C++98, en mettant l'accent sur l'utilisation des templates en C++.

## Exercise 00: Start with a few functions

L'objectif de L'exercice 00 consiste à créer plusieurs fonctions templates en C++. Vous allez développer des fonctions capables de manipuler des valeurs de types génériques. Les fonctions à implémenter incluent :

- `swap`: Permute les valeurs de deux arguments donnés.
- `min`: Compare deux valeurs et renvoie la plus petite.
- `max`: Compare deux valeurs et renvoie la plus grande.

Ces fonctions doivent pouvoir être appelées avec n'importe quel type d'argument. La seule exigence est que les deux arguments doivent avoir le même type et supporter tous les opérateurs de comparaison.

## Structure du Projet

Le projet est organisé de la manière suivante :

- **Directory:** `ex00/`
- **Files to submit:**
  - `incs/whatever.hpp`
  - `Makefile`
  - `srcs/main.cpp`

### Description des Fichiers

- `incs/whatever.hpp`: Contient la déclaration des classes et fonctions utilisées dans le projet.
- `srcs/main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.

## Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé whatever dans le répertoire courant.

## Exécution
### Exécution Simple
Après la compilation, exécutez le programme avec la commande :

```bash

./whatever arg
```
Remplacez arg par les arguments nécessaires au fonctionnement de votre programme.

### Exécution du Tester
Après la compilation, exécutez le programme avec la commande et l'argument tester :

```bash

./whatever tester
```
Cette commande permet de lancer le programme en mode test, si ce mode est implémenté dans le code.

## Fonctionnalités
- Gestion des exceptions : Le programme démontre l'utilisation des exceptions pour gérer les erreurs de manière propre et sécurisée.
- Suivi des bonnes pratiques de codage C++98 : Respect strict des conventions de codage et des standards de C++98.
- Structure de code modulaire et maintenable : Le code est organisé de manière à être facilement compréhensible et extensible.
...
#
## Exercise 01: Template Iteration
L'objectif de l'exercice 01 consiste à créer une fonction template en C++ pour itérer sur des collections. Vous allez développer une fonction capable de manipuler des éléments de types génériques. La fonction à implémenter inclut :

- `iter`: Applique une fonction donnée à chaque élément d'une collection.

Cette fonction doit pouvoir être appelée avec n'importe quel type d'argument. Les éléments de la collection doivent supporter l'opérateur de déréférencement.

## Structure du Projet

Le projet est organisé de la manière suivante :

- **Directory:** ex01/
- **Files to submit:**
  - `incs/Iter.hpp`
  - `Makefile`
  - `srcs/main.cpp`
  
### Description des Fichiers
- `incs/Iter.hpp`: Contient la déclaration et la définition de la fonction template iter.
- `srcs/main.cpp`: Contient le point d'entrée du programme et la logique principale.
- `Makefile`: Fichier pour automatiser la compilation du projet.

## Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```
Cette commande génère un exécutable nommé iter dans le répertoire courant.

## Exécution
Exécution Simple
Après la compilation, exécutez le programme avec la commande :

```bash
./iter
```
Cette commande permet de lancer le programme.

## Fonctionnalités
- Gestion des exceptions : Le programme démontre l'utilisation des exceptions pour gérer les erreurs de manière propre et sécurisée.
- Suivi des bonnes pratiques de codage C++98 : Respect strict des conventions de codage et des standards de C++98.
- Structure de code modulaire et maintenable : Le code est organisé de manière à être facilement compréhensible et extensible.
##
### Exercise 02: Array
- **Directory:** `ex02/`
- **Files to submit:**
  - `incs/Array.hpp`
  - `Makefile`
  - `srcs/Array.tpp`
  - `srcs/main.cpp`

#### Functionality
...

## Compilation and Execution
Navigate to the specific exercise directory and use the `make` command to compile the projects. Each executable can be run directly to demonstrate the functionalities implemented.

## Contributeurs
raveriss - Développeur principal

## Remarques
Ce projet suit les conventions de codage strictes pour C++98, évitant l'utilisation de fonctionnalités modernes et de conteneurs STL. Les bonnes pratiques pour la gestion de la mémoire et la portabilité sont également respectées.

## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
- [Apprenez à programmer en C++ sur codecademy](https://www.codecademy.com/catalog/language/c-plus-plus)
- [Introduction à C++ sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-introduction)
- [C++ Intermédiaire sur Sololearn](https://www.sololearn.com/fr/learn/courses/c-plus-plus-intermediate)
