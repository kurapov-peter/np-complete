import argparse

def main():
    parser = argparse.ArgumentParser(description=("test "))
    parser.add_argument('-i', '--input', type=str, help='Input file')
    parser.add_argument('-o', '--output', type=str, help='Output file')
    args = parser.parse_args()

    a = 1
    count = 0

    with open(args.input) as input:
        for line in input:
            count += 1
    
    with open(args.output, "w") as output:
        with open(args.input) as input:
            for line in input:
                for s in line.split():
                    if(a == 2):
                        output.write(s)
                        output.write("\n")
                        output.write(str(count - 1))
                        output.write("\n")
                    elif(a % 3 == 2 and a > 3):
                        output.write(s)
                        output.write(" ")
                    elif(a % 3 == 0 and a > 3):
                        output.write(s)
                        output.write("\n")
                    a = a + 1
        # print(l[2])
        # return None


if __name__ == "__main__":
    main()