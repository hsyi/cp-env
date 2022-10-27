#!/usr/bin/env python

from __future__ import print_function
import sys
import math
import random
import argparse


def exit_with_error(errmsg):
    print("Verdict: Wrong Answer ({})".format(errmsg), file=sys.stderr)
    sys.stderr.flush()
    sys.exit(1)


def exit_with_success(n, moves):
    score = (math.log(n, 2) + 1) / (moves + 1)
    fmtstr = "Verdict: Correct Answer (moves={}, score={})"
    print(fmtstr.format(moves, score), file=sys.stderr)
    sys.stderr.flush()
    sys.exit(0)



NMAX=1000


def play(n=NMAX, k=None, seed=None):
    a = [1,6,4,2,3,5,4]
    n = len(a)
    k = 6
    print("{} {}".format(n, k))
    sys.stdout.flush()
    while True:
        words = sys.stdin.readline().split()
        if words[0] == 'and':
            l = int(words[1])
            r = int(words[2])
            print(a[l-1]&a[r-1])
        elif words[0] == 'or':
            l = int(words[1])
            r = int(words[2])
            print(a[l-1]|a[r-1])
        sys.stdout.flush()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', type=int, default=NMAX,
                        help='maximum number that can be chosen')
    parser.add_argument('-k', type=int, help='number chosen by computer')
    parser.add_argument('--seed', help='seed for the random number generator')
    args = parser.parse_args()

    play(args.n, args.k, args.seed)


if __name__ == '__main__':
    main()
