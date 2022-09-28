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
    n = random.randint(1, 10)
    a = list(range(1, n+1))
    random.shuffle(a);
    print(n)
    print(a)
    sys.stdout.flush()
    while True:
        words = sys.stdin.readline().split()
        if words[0] == '?':
            l = int(words[1])
            r = int(words[2])
            print(sorted(a[l-1: r]))
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
