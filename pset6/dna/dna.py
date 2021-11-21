import sys
import csv


def main(argv):
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    database = []
    with open(argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for key in row:
                if key != "name":
                    row[key] = int(row[key])

            database.append(row)

    with open(argv[2], newline='') as file:
        text = file.read()

    strs = []
    for key in database[0]:
        if key != "name":
            strs.append(key)

    dna = {}
    for i in range(len(strs)):
        max = check(text,strs[i])
        dna[strs[i]] = max

    for i in range(len(database)):
        person = database[i]
        l = 1
        for key in person:
            if(key != "name"):
                if(person[key] != dna[key]):
                    continue
                else:
                    l += 1
            if(l == len(strs)):
                print(person["name"])
                return
    
    print("No match")


def check(text, s):
    max_n = 0
    l = len(s)
    length = len(text)
    for i in range(length):
        tmp_max = 0
        if (text[i:l+i] == s):
            k = 0
            while text[(i + k):(i + k + l)] == s:
                tmp_max += 1
                k += l
            if (tmp_max > max_n):
                max_n = tmp_max
        
    return max_n



if __name__ == '__main__':
    main(sys.argv)