from cs50 import get_string


def main():
    # Prompt the user for some text
    text = get_string("Text: ")

    # Compute the Coleman-Liau index
    L = count_letters(text) / count_words(text) * 100
    S = count_sentences(text) / count_words(text) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print the grade level
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    """Return the number of letters in text."""
    return len([char for char in text if char.isalpha()])


def count_words(text):
    """Return the number of words in text."""
    return len(text.split())


def count_sentences(text):
    """Return the number of sentences in text."""
    sentence_delimiters = [".", "!", "?"]
    return sum(1 for char in text if char in sentence_delimiters)


if __name__ == "__main__":
    main()
