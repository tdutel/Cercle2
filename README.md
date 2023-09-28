### tdutel
# Cercle2
Push_swap | So_long | Pipex

## Summary

- [Introduction](#introduction)
- [Push_swap](#pushswap)
- [So_long](#solong)
- [Pipex](#pipex)
- [Usage](#usage)

## Introduction <a name="introduction"></a>

Cercle2 contain 3 projects : Push_swap, so_long and Pipex. All these projects are individual.
- So_long was a choice project with FDF and Fractol.
- Pipex was a choice project with Minitalk.

## Push_swap <a name="pushswap"></a>

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, we have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting. View [Push_swap subject](https://github.com/tdutel/Cercle2/blob/main/push_swap/en.subject.pdf)

## So_long <a name="solong"></a>

May it be a file, stdin, or even later a network connection, we will always need a way to read content line by line. It's time to start working on this function, which will be essential for our future projects. View [So_long subject](https://github.com/tdutel/Cercle2/blob/main/so_long/en.subject.pdf)

## Pipex <a name="pipex"></a>

This project aims to deepen our understanding of the two concepts: Redirections and Pipes. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus. View [Pipex subject](https://github.com/tdutel/Cercle2/blob/main/pipex/en.subject.pdf)

## Usage <a name="usage"></a>

1. Copy link : https://github.com/tdutel/Cercle2.git
2. tap in terminal :
```
git clone https://github.com/tdutel/Cercle2.git
```
then according to subject :

```
cd push_swap
make
./push_swap nb1 nb2 nb3 nb4 nb5 ...
```
```
cd so_long
make
./so_long maps/big.ber (or another map)
```
```
cd pipex
make
./pipex infile "cmd1" "cmd2" outfile
```

> ⚠️ So_long and pipex was made on Mac, so it doesn't compile correctly on linux (I plan to fix this in the future.) 🚧

> #### Disclaimer
> This project is a part of the 42-Cursus curriculum and is intended for educational purposes. If you are a current student of 42, we strongly advise you not to copy this project or submit it as your own work, as it goes against the school's academic integrity policy.
