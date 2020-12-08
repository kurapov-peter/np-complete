import argparse

def main():
    parser = argparse.ArgumentParser(description=("test "))
    parser.add_argument('-i', '--input', type=str, help='Input file')
    parser.add_argument('-o', '--output', type=str, help='Output file')
    args = parser.parse_args()

    l = 0
    a = 1
    b = 1
    count = 0

    with open(args.input) as input:
        for line in input:
            count += 1

    with open(args.output, "w") as output:
        with open(args.input) as input:
            for line in input:
                l += 1
                # print(line)
                if(line[0] == '1' or l == 1):
                    # print(line)
                    for s in line.split():
                        if(a == 2 and l == 1):
                            output.write(s)
                            output.write(" ")
                        elif(a == 3 and l == 1):
                            output.write(s)
                            output.write(" ")
                            output.write(str(count - 1))
                            output.write("\n")
                        elif(a % 4 == 2 and l > 1):
                            # print('aaaa')
                            output.write(s)
                            output.write("\n")
                        # elif(a % 4 == 0 and a > 4):
                        #     output.write(s)
                        #     output.write("\n")
                        a = a + 1
                if(l == 1):
                    a = 1
                        


if __name__ == "__main__":
    main()