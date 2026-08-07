"""Functions to automate Conda airlines ticketing system."""


def generate_seat_letters(number: int):
    """Generate a series of letters for airline seats.

    Parameters:
        number (int): Total number of seat letters to be generated.

    Returns:
        generator: A generator that yields seat letters.

    Note:
        Seat letters are generated from A to D.
        After D the sequence starts again with A.
        For example: A, B, C, D, A, B

    """

    for num in range(number):
        yield ['A', 'B', 'C', 'D'][num % 4]


def generate_seats(number: int):
    """Generate a series of identifiers for airline seats.

    Parameters:
        number (int): The total number of seats to be generated.

    Returns:
        generator: A generator that yields seat numbers.

    Note:
        A seat number consists of the row number and the seat letter.
        There is no row 13, and each row has 4 seats.

        Seats should be sorted from low to high.
        For example: 3C, 3D, 4A, 4B

    """

    letters = generate_seat_letters(number)
    row = 0
    for num, letter in zip(range(number), letters):
        if num % 4 == 0:
            row += 1
        if row == 13:
            row = 14
        yield str(row) + letter


def assign_seats(passengers: [str]):
    """Assign seats to passengers.

    Parameters:
        passengers (list[str]): A list of strings containing names of passengers.

    Returns:
        dict: With passenger names as keys and seat numbers as values.
        Example output: {"Adele": "1A", "Björk": "1B"}

    """

    seats = generate_seats(len(passengers))
    return {passenger: next(seats) for passenger in passengers}
    

def generate_codes(seat_numbers: [str], flight_id: str):
    """Generate codes for a ticket.

    Parameters:
        seat_numbers (list[str]): A list of seat numbers.
        flight_id (str): A string containing the flight identifier.

    Returns:
        generator: A generator that yields 12 character long ticket codes.

    """

    for seat in seat_numbers:
        yield f"{seat + flight_id:012}"
