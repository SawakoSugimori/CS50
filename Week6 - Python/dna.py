# Implement a program that identifies a person based on their DNA
import csv
import sys

def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sts.exit(1)

    # Read database file into a variable
    people = []
    sequences = []
    with open(sys.argv[1], 'r') as data:
        datareader = csv.DictReader(data)

        # Make a list of key values
        sequences = datareader.fieldnames[1:]

        for person in datareader:
            # Convert string to int
            for x in sequences:
                person[x] = int(person[x])
            people.append(person)

    # Read DNA sequence file into a variable
    sequence = []
    with open(sys.argv[2], 'r') as dna:
        dnareader = csv.reader(dna)
        for dna in dnareader:
            sequence.append(dna)

    # Find longest match of each STR in DNA sequence
    match_dict = {}
    for x in sequences:
        match_dict[x] = longest_match(sequence[0][0], x)

    # Check database for matching profiles
    for person in people:
        match = 0
        for x in sequences:
            if person[x] == match_dict[x]:
                match += 1
            # If all subsequences matched, print person's name
            if match == len(sequences):
                print(person["name"])
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
