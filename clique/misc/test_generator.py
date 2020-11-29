#!/usr/bin/python3

import argparse
import sys

def generate_clique_benchmark(n, k, out):
    
    for i in range(n):
        print(i, end=' ', file=out)
    print(file=out)
    
    for i in range(n):
        print(i, i+1, file=out)
    for i in range(k):
        for j in range(i+1, k):
            print(i, j, file=out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', help='Number of vertecies', type=int, required=True)
    parser.add_argument('-k', help='Size of clique', type=int, required=True)
    parser.add_argument('-o', help='Output file')
    args = parser.parse_args()

    if args.o is None:
        out = sys.stdout
    else:
        out = open(args.o, 'w')

    generate_clique_benchmark(args.n, args.k, out)

if __name__ == '__main__':
    main()
