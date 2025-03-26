import random
import argparse

parser = argparse.ArgumentParser(
    prog="TestDataGenerator",
    description="Generates test data for evaluation of OVCSorting."
)

parser.add_argument("--seed", help="Optional seed for random data generation. Use '-1' for random seed. (default: -1)", default=-1)
parser.add_argument("--order", help="Order of generated data. Available: random, ordered, reversed. (default: random)", default="random")
parser.add_argument("--number", help="Number of keys to generate. (default: 1000)", default=1000)
parser.add_argument("--keylength", help="Length of generated keys. (default: 5)", default=5)
parser.add_argument( "--out", help="Output file. (default: out.txt)", default="out.txt")

args = parser.parse_args()

if args.seed != -1:
    random.seed(int(args.seed))

N = int(args.number)
k = int(args.keylength)
OUTPUT = args.out
maxVal = 10**k


with open(OUTPUT, "w") as file:
    if args.order == "random":
        for i in range(N):
            key = str(random.randint(0, maxVal-1)).zfill(k)
            file.write(key + "\n")
    elif args.order == "ordered":
        for i in range(N):
            key = str(i%maxVal).zfill(k)
            file.write(key + "\n")
    elif args.order == "reversed":
        for i in reversed(range(N)):
            key = str(i%maxVal).zfill(k)
            file.write(key + "\n")