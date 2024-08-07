import csv
import sys


def main():
    # Checking for command-line usage
    if not (len(sys.argv) == 3 and sys.argv[1].endswith(".csv") and sys.argv[2].endswith(".txt")):
        sys.exit("Usage: python dna.py database.csv sequences.txt")

    # Reading database file into a list of dicts
    database = list()
    try:
        with open(sys.argv[1], "r") as file:
            reader = csv.DictReader(file)
            subsequences = reader.fieldnames[1:]
            for row in reader:
                database.append(row)
    except FileNotFoundError:
        sys.exit(f"File not found: {sys.argv[1]}")

    # Reading DNA sequence file into a variable
    try:
        with open(sys.argv[2], "r") as file:
            sequence = file.read()
    except FileNotFoundError:
        sys.exit(f"File not found: {sys.argv[2]}")

    # Finding the longest match of each STR in DNA sequence
    subsequences_lengths = dict()
    for subsequence in subsequences:
        subsequences_lengths[subsequence] = longest_match(sequence, subsequence)

    # Checking database for matching profiles
    for person in database:
        person_subsequences_lengths = dict()
        for key in person:
            if key != "name":
                person_subsequences_lengths[key] = int(person[key])
        if person_subsequences_lengths == subsequences_lengths:
            print(person["name"])
            break
    else:
        # Printing no match if no match is found
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


if __name__ == "__main__":
    main()
